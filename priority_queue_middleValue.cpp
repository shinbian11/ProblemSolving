#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int main()
{
	F_I;

	/*
	백준 1655번 : 가운데를 말해요 (우선순위 큐)
	- 수가 들어올 때마다 sort 함수를 이용하여 가운데를 출력하는 경우는 O(n* nlogn)이 소요되므로 시간초과이다!
	- 연결리스트로 구현해도 O(n*n)이므로 시간초과이다!

	- 우선순위 큐 2개를 만들어서 관리하는 방법으로 풀기!
	- 2가지 조건을 항상 만족해야 한다
	조건 1. l에 있는 모든 값들은 항상 r에 있는 모든 값보다 작아야 한다. 즉 l의 최대값 <= r의 최대값
	조건 2. l의 원소 개수는 r의 원소 개수와 같아야 한다(각각 n/2개씩) => n이 홀수라면 l의 원소 개수가 r의 원소 개수보다 1개 더 많아야 한다.

	l은 최대 힙이므로, 항상 top 값은 l에 있는 원소들 중 가장 값이다.
	r은 최소 힙이므로, 항상 top 값은 r에 있는 원소들 중 가장 값이다.
	*/

	priority_queue<int, vector<int>> l; //왼쪽(l은 최대 힙)
	priority_queue<int, vector<int>, greater<int> > r;// 오른쪽(r은 최소 힙)

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{

		int x;
		cin >> x;

		//조건 1을 충족하기 위한 반복 작업

		if (l.empty() || r.empty()) //맨 처음에는 l에 넣어줘야 한다. 
			l.push(x);
		else
		{
			if (l.top() >= x) //이번에 입력되어 들어온 x가 l의 최대값보다 작으면, l로 들어와야 함
				l.push(x);
			else if (r.top() <= x) //이번에 입력되어 들어온 x가 r의 최소값보다 크면, r로 들어와야 함
				r.push(x);
			else //이번에 입력되어 들어온 x가 l의 최대값과 r의 최소값 사이에 있는 값이면, l로 들어와야 함.
				l.push(x);
		}

		// 조건 2를 충족하기 위한 반복 작업

		while (true)
		{
			if ((l.size() == r.size()) || (l.size() == r.size() + 1)) //조건 2가 충족될 때까지 반복
				break;
			if (l.size() > r.size())
			{
				r.push(l.top());
				l.pop();
			}
			else if (l.size() < r.size())
			{
				l.push(r.top());
				r.pop();
			}
		}

		cout << l.top() << '\n'; //항상 l의 최댓값이 중간값이다.
	}
	return 0;

}
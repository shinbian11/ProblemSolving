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
	//백준 1377번 : 버블 소트 (버블 소트의 이해)
	/*
	
	- 문제에 나와있는 소스코드에서 출력될 i의 의미는, 버블소트를 모두 끝내고 나왔을 때의 i이므로,
	다시 말해 바깥쪽 for문이 반복 되는 횟수를 출력하라는 의미이다.
	근데 O(n^2)이고, n은 최대 500000 이므로, 저 소스코드를 그대로 가져다가 붙이면 제한시간 초과가 되어서 실행 불가능함.
	즉 다른 방법을 찾아야 함.

	- 버블 정렬은, 한번 반복할때마다 움직여야 하는 원소가 있고, 가만히 있어도 되는 원소가 있는데, 움직여야 하는 원소는 1번에 딱 1칸만 움직일 수 있다. 
	  왜냐하면 swap을 할때 '인접'한 애들끼리만 교환하므로, 1칸씩만 이동가능하다.
	  그 말은 다시 말해, 내가 최종적으로 가야 할 목적지와 현재 위치의 거리가 3이라면, for 문을 '최소 3번 반복'해야 한다는 의미이다.

	- 이 아이디어를 이용하여, (정렬 전의 인덱스 - 정렬 이후의 인덱스) 의 '최대값'으로 정답을 유도할 수 있다.

	*/
	int n;
	cin >> n;
	vector<pi> v(n);
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first;
		v[i].second = i; //정렬 전의 인덱스
	}

	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i].second - i > 0) //정렬 전의 인덱스 - 정렬 이후의 인덱스가 양수라는 의미는, 이동을 해야 하는 원소들만 if문을 만족한다는 의미이다.
		{
			if (ans < v[i].second - i) //그러한 원소들 중에서, 가장 많이 이동해야 하는 원소, 즉 (정렬 전의 인덱스 - 정렬 이후의 인덱스) 의 최대값!
				ans = v[i].second - i;
		}
	}

	cout << ans + 1 << '\n'; //처음부터 정렬이 되어있는 배열일때도 1을 출력한다고 문제에 나와있는 소스코드에 있음.(처음부터 정렬되어 있을때 i=1이므로)
	
	return 0;
}
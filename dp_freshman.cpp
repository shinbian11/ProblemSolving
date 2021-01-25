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

ll d[104][104];

int main()
{
	/*
	[백준] 5557번 : 1학년 (dp, bottom-up)

	d[i][j] => i번째 수까지 사용해서 j라는 수를 만들어낼 수 있는 경우의 수
	e.g.) d[3][5] = 3번째 수까지 +,- 연산을 이용하여 5를 만들어 낼 수 있는 경우의 수

	e.g.)
	n=11 이라면, 마지막 1개는 원하는 답이므로, goal 이라는 변수에 따라 입력받자!

	d[i][goal]는... >> i번째 수 까지 사용해서 goal 이라는 수를 만들어 낼 수 있는 경우의 수

	a1  a2 ... + ai = goal    >> a1  a2   a(i-1) = goal-ai  >> d[i-1][goal-ai]
	a1  a2     - ai = goal    >> a1  a2   a(i-1) = goal+ai  >> d[i-1][goal+ai]

	이 2가지 경우의 합이다.
	*/

	int n;
	cin >> n;
	n -= 1;
	vector<int> arr(n+1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	int goal;
	cin >> goal;

	d[1][arr[1]] = 1; //1번째 수만을 이용해서 arr[1]을 만들어 내는 경우 : 1가지 (1번째 수가 곧 arr[1]이니까)

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (j - arr[i] >= 0) //배열 idx 범위 주의!!
				d[i][j] += d[i - 1][j - arr[i]];
			if (j + arr[i] <= 20) //배열 idx 범위 주의!!
				d[i][j] += d[i - 1][j + arr[i]];
		}
	}
	
	cout << d[n][goal] << '\n'; //n번째 수 까지 모두 사용하여 goal 이라는 값을 만드는 방법의 수!

	return 0;
}
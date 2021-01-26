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
ll arr[104];


ll go(ll idx, ll ans)
{
	//기저조건(탈출조건)-------------
	if (idx == 1 && ans == arr[1])
		return d[idx][ans] = 1;
	if (idx == 1 && ans != arr[1])
		return d[idx][ans] = 0;

	//memoization
	if (d[idx][ans] != -1)
		return d[idx][ans];
	
	//재귀함수
	ll a = 0;

	if (ans - arr[idx] >= 0)
		a += go(idx - 1, ans - arr[idx]);
	if (ans + arr[idx] <= 20)
		a += go(idx - 1, ans + arr[idx]);

	return d[idx][ans] = a;
}

int main()
{
	/*
	[백준] 5557번 : 1학년 (dp, Top-down)

	d[i][j] => i번째 수까지 사용해서 j라는 수를 만들어낼 수 있는 경우의 수
	e.g.) d[3][5] = 3번째 수까지 +,- 연산을 이용하여 5를 만들어 낼 수 있는 경우의 수

	e.g.)
	n=11 이라면, 마지막 1개는 원하는 답이므로, goal 이라는 변수에 따라 입력받자!

	d[i][goal]는... >> i번째 수 까지 사용해서 goal 이라는 수를 만들어 낼 수 있는 경우의 수

	a1  a2 ... + ai = goal    >> a1  a2   a(i-1) = goal-ai  >> d[i-1][goal-ai]
	a1  a2     - ai = goal    >> a1  a2   a(i-1) = goal+ai  >> d[i-1][goal+ai]

	이 2가지 경우의 합이다.
	*/

	ll n;
	cin >> n;
	n -= 1;

	memset(d, -1, sizeof(d));

	for (ll i = 1; i <= n; i++)
		cin >> arr[i];

	ll goal;
	cin >> goal;

	cout << go(n, goal) << '\n';

	return 0;
}
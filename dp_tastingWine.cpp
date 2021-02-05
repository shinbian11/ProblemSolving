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
	
int n;
int a[10004];
int d[10004];

int main()
{
	F_I;

	//[백준] 2156번 : 포도주 시식 (dp - bottom-up)
	/*
	d[i] : i 번째 포도주까지 먹을수 있는 최대 양
	e.g.) d[1] = a[1]
	d[2] = a[1]+a[2]

	and, d[3] = (a[1]+a[2] , a[1]+a[3], a[2]+a[3]) 의 최대값

	...

	즉, d[n] 은
	1. d[n - 3] + a[n - 1] + a[n] , 
	2. d[n - 2] + a[n]
	3. d[n - 1] 
	들 중에서의 최대값이다.

	연속 3잔의 포도주를 먹으면 안된다는 조건만 만족하면 된다!
	*/
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	d[0] = 0;
	d[1] = a[1];
	d[2] = a[1] + a[2];


	for (int i = 3; i <= n; i++)
	{
		d[i] = max(max(d[i - 3] + a[i - 1] + a[i], d[i - 2] + a[i]), d[i - 1]);
	}

	cout << d[n] << '\n';

	return 0;
}
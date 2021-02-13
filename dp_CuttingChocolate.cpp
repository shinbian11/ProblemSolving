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

int d[400][400];
int n, m;

int go(int x, int y)
{
	/*
	사실 n*m-1 하면 풀리는 매우 간단한 문제지만, 굳이 dp를 쓴다면 이렇게 해결 가능하다!

	d[n][m] : 가로 n , 세로 m 짜리 초콜릿을 1 * 1 로 자르는 최소 횟수
	1. d[n][m] 을 가로로 자르는 경우 : d[i][m] + d[n-i][m] + 1 
	2. d[n][m] 을 세로로 자르는 경우 : d[n][i] + d[n][m-i] + 1 
	- 1. 과 2. >> 이 둘의 최소 로 d[n][m]을 갱신 시켜 주면 된다.
	
	*/
	if (x == 1 && y == 1) return 0;

	int& ans = d[x][y];
	if (ans != -1) return ans;

	ans = 1e9;

	//초콜릿을 가로로 자르는 경우
	for (int i = 0; i <= x; i++)
	{
		if (ans > go(i, y) + go(x - i, y) + 1)
			ans = go(i, y) + go(x - i, y) + 1;
	}
	//초콜릿을 세로로 자르는 경우
	for (int i = 0; i <= y; i++)
	{
		if (ans > go(x, i) + go(x, y - i) + 1)
			ans = go(x, i) + go(x, y - i) + 1;
	}

	return ans;
}

int main()
{
	//[백준] 2163번 : 초콜릿 자르기 (Top-down)

	F_I;

	int n, m;
	cin >> n >> m;

	memset(d, -1, sizeof(d));

	cout << go(n, m) << '\n';

	return 0;
}
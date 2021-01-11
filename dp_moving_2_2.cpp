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

int arr[1002][1002];
int d[1002][1002];
int n, m;

int go(int i, int j)
{
	if (i > n || j > m)
		return 0;

	if (d[i][j] >= 0)
		return d[i][j];

	return d[i][j] = Max(go(i, j + 1), go(i + 1, j)) + arr[i][j];
}

int main()
{
	F_I;

	//11048번 : 이동하기 (dp) >> (top-down : 재귀함수2)

	//int n, m;
	cin >> n >> m;

	for (int i = 0; i < 1002; i++)
	{
		for (int j = 0; j < 1002; j++)
			d[i][j] = -1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	}

	cout << go(1, 1) << '\n';

	return 0;
}
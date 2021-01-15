#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int a[101][101];
int b[101][101];
int c[101][101];

int main()
{
	F_I;

	/*
	백준 2740번 : 행렬 곱셈
	- n*m 행렬과 m*k 행렬을 곱하는 작업의 시간복잡도는 O(n*m*k) 이고, O(max(n,m,k)^3)과 비슷하다.
	- 삼중 반복문에서, 변수의 위치를 잘 파악하기! m이 가장 안쪽 반복문의 변수이다.
	*/
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	cin >> m >> k;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			for (int l = 0; l < m; l++)
			{
				c[i][j] += a[i][l] * b[l][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
			cout << c[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}
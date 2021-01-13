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

int d[14];

int main()
{
	F_I;
	/*
	백준 9095번 : 1, 2, 3 더하기  (dp)
	
	d[i] = 1,2,3의 합으로 i를 만들 수 있는 방법의 수
	*/
	int n;
	cin >> n;
	int arr[3] = { 1,2,3 };

	while (n--)
	{
		int m;
		cin >> m;

		memset(d, 0, sizeof(d));

		d[0] = 1;

		/*for (int j = 0; j < 3; j++) // 15989번 : 1, 2, 3 더하기 4 solution
		{
			for (int i = 1; i <= m; i++)
			{
				if (i - arr[j] >= 0)
					d[i] += d[i - arr[j]];
			}
		}*/
		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i - arr[j] >= 0)
					d[i] += d[i - arr[j]];
			}
		}
		cout << d[m] << '\n';
	}
	return 0;
}
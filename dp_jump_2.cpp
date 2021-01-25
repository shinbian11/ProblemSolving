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
int arr[104][104];
ll d[104][104];

ll go(int x, int y)
{
	ll ans = 0;

	if (x == 0 && y == 0) //d[0][0] = (0,0)->(0,0) 이므로 1가지이다.
		return 1;

	if (d[x][y] != -1)
		return d[x][y];

	for (int k = 0; k < y; k++)
	{
		if (y - k == arr[x][k])
			ans += go(x, k);
	}
	for (int k = 0; k < x; k++)
	{
		if (x - k == arr[k][y])
			ans += go(k, y);
	}

	d[x][y] = ans;

	return d[x][y];
}

int main()
{
	F_I;
	/*
	[백준] 1890번 : 점프 (dp, Top-down)

	d[i][j] > (i,j)까지 이동이 가능한 경로의 수의 개수라고 한다면,

	1) 왼쪽에서 오른쪽으로 오는 경우 : d[i][j] += d[i][k] (k<j , j-k == arr[i][k])
	2) 위쪽에서 아래쪽으로 내려오는 경우 : d[i][j] += d[k][j] (k<i , i-k == arr[k][j])

	*/
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	memset(d, -1, sizeof(d));
	d[0][0] = 0;
	cout << go(n - 1, n - 1) << '\n';

	//bottom-up
	/*
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << d[i][j] << ' ';
			cout << '\n';
		}
		cout << '\n';


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < j; k++) // 오른쪽으로 이동
				{
					if (j - k == arr[i][k])
					{
						d[i][j] += d[i][k];
					}
				}

				for (int k = 0; k < i; k++) // 아래쪽으로 이동
				{
					if (i - k == arr[k][j])
						d[i][j] += d[k][j];
				}
			}
		}

		cout << d[n - 1][n - 1] << '\n';
		*/


	return 0;
}
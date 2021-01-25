#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

int n;
int arr[104][104];
ll d[104][104];

ll go(int x, int y)
{
	ll ans = 0;

	if (x == 0 && y == 0) //d[0][0] = (0,0)->(0,0) �̹Ƿ� 1�����̴�.
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
	[����] 1890�� : ���� (dp, Top-down)

	d[i][j] > (i,j)���� �̵��� ������ ����� ���� ������� �Ѵٸ�,

	1) ���ʿ��� ���������� ���� ��� : d[i][j] += d[i][k] (k<j , j-k == arr[i][k])
	2) ���ʿ��� �Ʒ������� �������� ��� : d[i][j] += d[k][j] (k<i , i-k == arr[k][j])

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
				for (int k = 0; k < j; k++) // ���������� �̵�
				{
					if (j - k == arr[i][k])
					{
						d[i][j] += d[i][k];
					}
				}

				for (int k = 0; k < i; k++) // �Ʒ������� �̵�
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
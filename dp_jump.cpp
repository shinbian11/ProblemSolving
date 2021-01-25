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
int ans;
int arr[104][104];
ll d[104][104];


int main()
{
	F_I;
	/*
	[����] 1890�� : ���� (dp, bottom-up)

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

	d[0][0] = 1;

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

	return 0;
}
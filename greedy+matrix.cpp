#include <bits/stdc++.h>

//#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// ���� ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

int a[51][51];
int b[51][51];
int n, m;

void flip(int i, int j) //3 X 3 �з� ��ŭ�� �ش��ϴ� ��� �κ� ������
{
	for (int x = i; x <= i + 2; x++)
	{
		for (int y = j; y <= j + 2; y++)
		{
			a[x][y] = 1 - a[x][y];
		}
	}
}
int main() 
{
	//F_I; >> scanf�� cin ���ÿ� �� ���� �̰� �� ����!! ����س���!
	//int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &b[i][j]);
		}
	}

	int cnt = 0;
	if (n < 3 || m < 3) //���γ� ���γ� 3�� �ȵǸ�, ������ ���� �����Ƿ�, �׳� �� ���¿��� ��� ���Ұ� �������� �Ǵ��ؾ� �Ѵ�.
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] != b[i][j])
				{
					cout << "-1" << '\n';
					return 0;
				}
			}
		}
		cout << "0" << '\n';
		return 0;
	}
	else
	{
		//A,B�� 3 x 3 ��� ������ ���� ���� ����� ���Ұ� �ٸ��� FLIP �Ѵ�. 
		//��ø �ݺ����� ������ ����, ��� ���� 1 ~ M-2 �κа�, ���� 1 ~ N-2 �κ��� ��������. 
		for (int i = 0; i <= n - 3; i++)
		{
			for (int j = 0; j <= m - 3; j++)
			{
				if (a[i][j] != b[i][j])
				{
					flip(i, j);
					++cnt;
				}
			}
		}
		//������ �κи� ���ؼ� �׷��� �ٸ��� ������ �����Ƿ� -1 ���, �ƴϸ� cnt ���.
		//�ٵ� ������ �κи� ���ϴ°ų� �׳� ��ü ���ϴ°ų� �� ���� �����Ƿ� �׳� ��ü ���ϱ�!
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] != b[i][j])
				{
					cout << "-1" << '\n';
					return 0;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
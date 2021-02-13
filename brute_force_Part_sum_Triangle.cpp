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

int arr[500][1000];
int part_sum[500][1000];
int n;

int calc(int x, int y)
{
	int cur = arr[x][y];
	int ans = cur;
	int row = x, n_ly = y, n_ry = y;

	if (y % 2 != 0) // y�� Ȧ�� >> (x,y) �������� �ﰢ���� �Ʒ��� ����
	{
		while (true)
		{
			row += 1;
			n_ly = y;
			n_ry += 2;

			if (row > n || row < 1) break;
			if (n_ly < 1 || n_ry > row * 2 - 1) break;

			cur += (part_sum[row][n_ry] - part_sum[row][n_ly - 1]);

			if (ans < cur)
				ans = cur;
		}
	}
	else // y�� ¦�� >> (x,y) �������� �ﰢ���� ���� ����
	{
		while (true)
		{
			row -= 1;
			n_ly -= 2;
			n_ry = y;

			if (row > n || row < 1) break;
			if (n_ly < 1 || n_ry > row * 2 - 1) break;

			cur += (part_sum[row][n_ry] - part_sum[row][n_ly - 1]);

			if (ans < cur)
				ans = cur;
		}
	}

	return ans;
}

int main()
{
	F_I;

	//[����] 4902�� : �ﰢ���� �� (���Ʈ ����)
	/*
	e.g.) �κ��տ� ����
	4~10������ ����? : 1~10������ �� - 1~3������ ��

	- �� ��������, ���� �ﰢ���� y ��ǥ�� Ȧ���� ������ ������� �κ� �ﰢ���� ���� �� �ְ�,
	- ���� �ﰢ���� y ��ǥ�� ¦���� ���� ������� �κ� �ﰢ���� ���� �� �ִ�.
	*/
	int tc = 1;
	while (true)
	{

		cin >> n;
		if (n == 0)
			break;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 2 * i - 1; j++)
			{
				cin >> arr[i][j];
				part_sum[i][j] = part_sum[i][j - 1] + arr[i][j]; //i��° ���� j��°������ �κ��� : i��° ���� j-1��°������ �κ��� + (i,j)�� ��
			}
		}

		int ans = -1000000;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 2 * i - 1; j++)
			{
				int tmp = calc(i, j); // ������ �ﰢ������ ���� �� ���� ������ �κ� �ﰢ���� ��� �������鼭 ���� üũ�� �Ѵ�.
				if (ans < tmp)
					ans = tmp;
			}
		}

		cout << tc << ". " << ans << '\n';

		tc += 1;
	}
	return 0;
}
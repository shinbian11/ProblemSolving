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

int arr[504][504];
int d[504][504];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m;

int move(int x, int y)
{
	if (x == n - 1 && y == m - 1) return 1; //�������� �����ϸ� ����->�������� ���� ��찡 + 1 �� ���̹Ƿ� 1 �����Ѵ�.

	if (d[x][y] != -1) return d[x][y]; //memoization

	int ans = 0;

	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
		{
			if (arr[x][y] > arr[nx][ny])
			{
				ans += move(nx, ny); //(nx,ny)���� (n-1,m-1)�� ���� ����� ������ �����ش�.
			}
		}
	}

	return d[x][y] = ans;
}

int main()
{
	F_I;

	//[����] 1520�� : ������ �� (dp, Top-down)
	//1937�� : ������� �Ǵٿ� ����� ����� �����̴�! ������� �Ǵ� ���� ���� Ǯ��� ���ƿ���!

	cin >> n >> m;

	memset(d, -1, sizeof(d));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	cout << move(0, 0) << '\n'; //(0,0)���� ����

	return 0;
}
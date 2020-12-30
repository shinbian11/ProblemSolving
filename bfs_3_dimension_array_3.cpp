#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

int a[1001][1001]; // �迭 ����
int wall[1001][1001][12][2];
int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int n, m, k;

int isinside(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m)
		return 1;
	else
		return 0;
}

int main()
{
	//F_I;

	//���� 16933�� : �� �μ��� �̵��ϱ� 3
	//���� 14442���� �� �μ��� �̵��ϱ� 2���ٰ� ���� �㸸 �߰��� ���̴�. 4���� �迭��!!
	//�� 4���� �迭�� 4��° []�� ���� ���� üũ�ϴ� �뵵�� ����ϸ� �ȴ�.
	//57��° �ٿ��� �ٸ� ������ �̵����� �ʰ�, ������ �ִ� ��쵵 ������ ����� �Ѵ�! �̰͸� �����ϸ� ��!!

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}

	queue<tuple<int, int, int, int>> q;
	q.push(make_tuple(0, 0, 0, 0));

	wall[0][0][0][0] = 1;

	while (!q.empty())
	{
		int x, y, z, day;
		tie(x, y, z, day) = q.front();
		q.pop();

		if (wall[x][y][z][1 - day] == 0) //����! �������� �ʰ� ������ �ִ� ���(���� �㸸 �ٲ��, �װ͵� Ƚ���� �ľ� �ϹǷ� 1�� ���Ѵ�.)
		{
			wall[x][y][z][1 - day] = wall[x][y][z][day] + 1; 
			q.push(make_tuple(x, y, z, 1 - day));
		}
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (isinside(nx, ny) && a[nx][ny] == 1 && wall[nx][ny][z + 1][1 - day] == 0 && (z + 1) <= k && day == 0) //���� �� ���� ���ε�, ���� ���� �ν� �� �ִ� Ƚ���� ���Ұ�, ���� ���
			{
				wall[nx][ny][z + 1][1 - day] = wall[x][y][z][day] + 1; // ���� �ѹ� �νð� ��
				q.push(make_tuple(nx, ny, z + 1, 1 - day));
			}
			if (isinside(nx, ny) && a[nx][ny] == 0 && wall[nx][ny][z][1 - day] == 0) //���� ������ ���� �ƴϰ� �׳� ���� �ִ� ���ϋ�
			{
				wall[nx][ny][z][1 - day] = wall[x][y][z][day] + 1;
				q.push(make_tuple(nx, ny, z, 1 - day));
			}
		}
		
		
	}
	int ans = 1e9;
	for (int i = 0; i <= k; i++) //i<k�� �ƴ϶� i<=k�̴�! �ִ� k�� �ν� �� �����ϱ�, k���� ��� ����ϰ� �������� �����ϴ� ��쵵 �����ؾ� ��!
	{
		for (int j = 0; j < 2; j++)
		{
			if (wall[n - 1][m - 1][i][j] != 0)
			{
				if (ans > wall[n - 1][m - 1][i][j])
					ans = wall[n - 1][m - 1][i][j];
			}
		}
	}
	if (ans == 1e9)
		cout << "-1" << '\n';
	else
		cout << ans << '\n';

	return 0;
}
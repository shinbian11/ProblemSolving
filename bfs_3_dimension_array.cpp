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
int wall[1001][1001][2]; //wall[x][y][z] = x�� y�� ���� z�� ���� �μ̴�.
int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int n, m;

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
	
	//���� 2206�� : �� �μ��� �̵��ϱ� (������ �迭 + bfs)
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d",&a[i][j]);
		}
	}

	queue<tuple<int,int,int>> q;
	q.push(make_tuple(0,0,0));
	wall[0][0][0] = 1;
	while (!q.empty())
	{
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (isinside(nx, ny) && a[nx][ny] == 1 && z==0 && wall[nx][ny][z+1] == 0) //���� �� ���� ���ε�, ���� �ѹ��� ���� �ν��� ���� ���. 
			{   // wall[nx][ny][z+1]==0 �̶�� ����, �̹��� ���� �νð� �� �ǵ�, nx�� ny��(������ �湮�� �κ�)�� ���� �湮�� �ȵǾ��ٴ� �ǹ��̴�. 
				// wall �迭�� �湮Ƚ���� �����԰� ���ÿ�, �湮Ƚ���� üũ�� �����ϴ�(0�� ��������� ���� �湮 ���ߴٴ� �ǹ��̴ϱ�)
				wall[nx][ny][z+1] = wall[x][y][z] + 1; // ���� �ѹ� �νð� ��
				q.push(make_tuple(nx, ny, z + 1));
			}
			if (isinside(nx, ny) && a[nx][ny] == 0 && wall[nx][ny][z] == 0) //���� ������ ���� �ƴϰ� �׳� ���� �ִ� �� �ϋ�
			{
				wall[nx][ny][z] = wall[x][y][z] + 1;
				q.push(make_tuple(nx, ny, z));
			}
		}
	}
	if (wall[n - 1][m - 1][0] != 0 && wall[n - 1][m - 1][1] != 0)
		cout << Min(wall[n - 1][m - 1][0], wall[n - 1][m - 1][1]) << '\n';
	else if (wall[n - 1][m - 1][0] != 0 && wall[n - 1][m - 1][1] == 0)
		cout << wall[n - 1][m - 1][0] << '\n';
	else if (wall[n - 1][m - 1][0] == 0 && wall[n - 1][m - 1][1] != 0)
		cout << wall[n - 1][m - 1][1] << '\n';
	else
		cout << "-1" << '\n';
	return 0;
}
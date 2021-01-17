#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

int arr[54][54];
int d[54][54];

int n, m;
int dir_x[8] = { -1,0,1,-1,1,-1,0,1 };
int dir_y[8] = { -1,-1,-1,0,0,1,1,1 };

int bfs(int i, int j)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			d[i][j] = -1;
	}

	queue<pi> q;
	q.push(make_pair(i, j));
	d[i][j] = 0;

	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				//�Ʊ�� �������� �ִٰ� �ϴ���, ��ĭ���� bfs�� ���� �� ĭ�� Ž�� �ϴٰ� �����ϴ� �Ʊ������ ù ������ �� ���� �Ÿ� �̹Ƿ�, 
				//arr[nx][ny] == 1 �� �������ڸ��� (�� ó�� ������ �Ʊ����϶�), �ٷ� d[x][y] + 1 ���� ��ȯ�ϸ� �ȴ�!
				if (arr[nx][ny] == 1) 
					return d[x][y] + 1;
				if (d[nx][ny] == -1)
				{
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

}
int main()
{
	//[����] 17086�� : �Ʊ� ��� 2
	/*
	������ ��ĭ����, BFS�� �Ͽ� ���� ����� �Ʊ������ �Ÿ�(���� �Ÿ�)�� ���Ѵ� (bfs(i,j) �Լ��� �̿��Ͽ�)
	bfs(i,j)�� ��ȯ�� �� �ִ� �Ÿ��� ���!
	*/

	F_I;
	
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	int distance = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
			{
				if (distance < bfs(i, j))
					distance = bfs(i, j);
			}
		}
	}

	cout << distance << '\n';

	return 0;
}
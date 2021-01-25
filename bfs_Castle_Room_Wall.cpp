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

int arr[54][54]; // ĭ ���� �Է�
int d[54][54]; //�� ĭ�� ���� ���� ��ȣ
int room[50 * 50 + 4]; //���� ���� : room[i] : i��° ���� ũ��

//i=0 ����, i=1 ����, i=2 ����, i=3 �����̴�. ���� ���Ѿ� ��!
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

int m, n;

int bfs(int i, int j, int  rooms) //(i,j)��°���� ���۵� rooms��° ���� ũ�⸦ return
{
	int size = 1;

	d[i][j] = rooms;
	queue<pi> q;
	q.push(make_pair(i, j));

	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && nx < m)
			{
				if ((d[nx][ny] == 0) && !(arr[x][y] & (1 << i))) //(x,y)�࿡�� (nx,ny)�� ������ �̵��ϴ� ���� ���� ������ �ȵǴϱ�.
					//arr[x][y] & (1 << i) �� 1�̸�, i��°�� ����Ű�� ���⿡ ���� �ִٴ� �ǹ��ε�,
					//i=0 ����, i=1 ����, i=2 ����, i=3 �����̴�.
				{
					size += 1;
					d[nx][ny] = rooms;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	return size; //�� ũ�� return
}

int main()
{
	F_I;

	//[����] 2234�� : ���� (��Ʈ����ŷ, BFS)

	cin >> m >> n; //�Է� ���� ����! n>>m �ƴϰ� m>>n �̴�.

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
	
	memset(d, 0, sizeof(d));

	//1��
	int rooms = 0; //�� ��ȣ

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (d[i][j] == 0) //(i,j)���� �� ��ȣ�� �������� �ʾ�����
			{
				rooms += 1;
				int cnt = bfs(i, j, rooms); //(i,j)��°���� ���۵� rooms��° ���� ũ�⸦ return
				room[rooms] = cnt; //rooms ��° ���� ũ��� cnt �̴�.
			}
		}
	}


	cout << rooms << '\n'; //�� ����

	//2��
	int mx = -1;
	for (int i = 1; i <= rooms; i++)
	{
		if (mx == -1 || mx < room[i])
			mx = room[i];
	}

	cout << mx << '\n'; //���� ū ���� ũ��


	//3��
	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int x = i + dx[k];
				int y = j + dy[k];
				if (x >= 0 && x < n && y >= 0 && y < m)
				{
					if (d[i][j] != d[x][y]) //(i,j)ĭ�� �� ��ȣ�� (x,y) ĭ�� �� ��ȣ�� �ٸ� �� (���� �ٸ� ���϶�, ���� �����ϰ� ��ĥ �� ���� ��)
					{
						//d[i][j]�� ���� ũ��� d[x][y]�� ���� ũ���� �ִ밪�� ���Ѵ�.
						int tmp = room[d[i][j]] + room[d[x][y]]; 
						if (ans == -1 || ans < tmp)
							ans = tmp;
					}
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
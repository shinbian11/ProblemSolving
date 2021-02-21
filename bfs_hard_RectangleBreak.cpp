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

int dx[4] = { -1,0,1,0 }; //������� ����
int dy[4] = { 0, 1,0,-1 };
int arr[1004][1004];
int d[1004][1004];
int n, m;
int h, w, sx, sy, ex, ey;

bool isinside(int x, int y,int dir)
{
	//���簢���� ������ ������ �Ѿ�� �ʾƾ� �Ѵ�.
	//dir :  0  1  2  3
	//���� : �� �� �� ��

	if (dir == 0) //��
	{
		if ((x - 1 >= 1 && x - 1 <= n && y >= 1 && y <= m) && (x - 1 >= 1 && x - 1 <= n && y + w - 1 >= 1 && y + w - 1 <= m) && (x + h - 2 >= 1 && x + h - 2 <= n && y >= 1 && y <= m) && (x + h - 2 >= 1 && x + h - 2 <= n && y + w - 1 >= 1 && y + w - 1 <= m))
			return true;
		else
			return false;
	}
	else if (dir == 1) //��
	{
		if ((x >= 1 && x <= n && y + 1 >= 1 && y + 1 <= m) && (x >= 1 && x <= n && y + w >= 1 && y + w <= m) && (x + h - 1 >= 1 && x + h - 1 <= n && y + 1 >= 1 && y + 1 <= m) && (x + h - 1 >= 1 && x + h - 1 <= n && y + w >= 1 && y + w <= m))
			return true;
		else
			return false;
	}
	else if (dir == 2) //��
	{
		if ((x + 1 >= 1 && x + 1 <= n && y >= 1 && y <= m) && (x + 1 >= 1 && x + 1 <= n && y + w - 1 >= 1 && y + w - 1 <= m) && (x + h >= 1 && x + h <= n && y >= 1 && y <= m) && (x + h >= 1 && x + h <= n && y + w - 1 >= 1 && y + w - 1 <= m))
			return true;
		else
			return false;
	}
	else if (dir == 3) //��
	{
		if ((x >= 1 && x <= n && y - 1 >= 1 && y - 1 <= m) && (x >= 1 && x <= n && y + w >= 1 && y + w <= m) && (x + h - 1 >= 1 && x + h - 1 <= n && y - 1 >= 1 && y - 1 <= m) && (x + h - 1 >= 1 && x + h - 1 <= n && y + w >= 1 && y + w <= m))
			return true;
		else
			return false;
	}
}

bool notWall(int x, int y,int dir)
{
	//���簢���� ���� ��ġ�� �ȵȴ� == ���簢���� �������� ���� ���ο� ������ ���� ������ �ȵȴ�
	//�� ���� �ٽ� ����, �������� ���� ���ο� �κ��� ���� 0�̿��� �Ѵ�. (���� 1 �̻��̸� ������ �κп� ���� �ּ� 1�� �̻� �ִٴ� �ǹ̴ϱ�)
	//dir :  0  1  2  3
	//���� : �� �� �� ��

	if (dir == 0) //��
	{
		int sum = 0;
		for (int j = y; j < y + w; j++)
		{
			sum += arr[x - 1][j];
		}
		if (sum == 0)
			return true;
		else
			return false;
	}
	else if (dir == 1) //��
	{
		int sum = 0;
		for (int j = x; j < x+h; j++)
		{
			sum += arr[j][y+w];
		}
		if (sum == 0)
			return true;
		else
			return false;
	}
	else if (dir == 2) //��
	{
		int sum = 0;
		for (int j = y; j < y + w; j++)
		{
			sum += arr[x + h][j];
		}
		if (sum == 0)
			return true;
		else
			return false;
	}
	else if (dir == 3) //��
	{
		int sum = 0;
		for (int j = x; j < x + h; j++)
		{
			sum += arr[j][y -1];
		}
		if (sum == 0)
			return true;
		else
			return false;
	}

}

int main()
{
	F_I;

	// [����] 16973�� : ���簢�� Ż�� (bfs - �Ϲ����� �̷� Ż��� �ٸ� ��)

	// ���簢���� 1 x 1 �̾��ٸ� , �׳� �Ϲ����� �̷� Ż�� �����̰� O(NM)�� �ð��� �ҿ� �ǹǷ� ���������, 
	// �� ������ ���簢���� H x W �̹Ƿ�, �� ���簢�� ���ο� ���� �ִ����� ���θ� �Ǵ��ϴ� ������ O(HW)�� �ð��� �ҿ�ȴ�.
	// ��, �Ϲ����� ����ó�� Ǯ�� O(NMHW) �� �ð��� �ҿ�ǹǷ�, �ð��ʰ��� ����!! (���� ���� �̷� �Ʒ����� 2��° '�ð��ʰ�' ���� ����!)
	// �� ���簢�� ���ο� ���� �ִ����� ���θ� �Ǵ��ϴ� �ð��� O(HW)���� O(H) or O(W)�� �ٿ��� �Ѵ�! ( notWall() �κ� )

	memset(d, -1, sizeof(d));
	//int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cin >> h >> w >> sx >> sy >> ex >> ey;

	//���簢���� ���� ��� �������� �������� �Ѵ�.
	d[sx][sy] = 0;

	queue<pi> q;
	q.push(make_pair(sx, sy));

	while (!q.empty())
	{

		int x, y;
		tie(x, y) = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x;
			int ny = y;

			if (isinside(nx, ny, i))
			{
				if (notWall(nx, ny, i))
				{
					nx = x + dx[i];
					ny = y + dy[i];

					if (d[nx][ny] == -1)
					{
						d[nx][ny] = d[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
				}

			}
		}
	}

	if (d[ex][ey] == -1)
		cout << -1 << '\n';
	else
		cout << d[ex][ey] << '\n';


	return 0;
}


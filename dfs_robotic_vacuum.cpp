#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

//��� 1 : DFS �̿��ϱ�

int n, m, x, y, dir, clean;
int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };
int v[50][50];
bool visited[50][50];

int turnDirection(int dir) { //���� �������� ���� ����
	switch (dir)
	{
	case 0:
		return 3;
	case 1:
		return 0;
	case 2:
		return 1;
	case 3:
		return 2;
	}
}

void dfs(int x, int y, int dir, int clean)
{
	for (int i = 0; i < 4; i++) {

		int nd = turnDirection(dir);
		int nx = x + dir_x[nd];
		int ny = y + dir_y[nd];

		if (v[nx][ny] == 0 && visited[nx][ny] == 0) // �̹��� Ž���� ĭ��, û�� ������ ĭ�̸�
		{
			visited[nx][ny] = 1;
			dfs(nx, ny, nd, clean + 1);
			break;
		}
		dir = nd;
	}

	int backidx = (dir > 1) ? dir - 2 : dir + 2; //���� �ٶ󺸰� �ִ� ������ ���� ����

	int back_x = x + dir_x[backidx];
	int back_y = y + dir_y[backidx];

	if (v[back_x][back_y] == 0) // ���� ������ ���� �ƴ� ���, ������ ������ä ���� �Ѵ�
	{
		dfs(back_x, back_y, dir, clean);
	}
	else { //���� ������ ���̶� ������ ���� ���� ��, ���� ����ϰ� �����Ѵ�.
		cout << clean << '\n';
		exit(0);
		//return;
	}

}

int main()
{
	F_I;

	cin >> n >> m >> x >> y >> dir;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> v[i][j];
	}

	visited[x][y] = true;
	clean += 1;

	dfs(x, y, dir, clean);

	return 0;
}
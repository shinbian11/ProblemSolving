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

int d[51][51][4][4]; //d[x][y][s][k] : (x,y)�� ���� ��ǥ�̰�, s�� c �湮 ����, k�� (x,y)�� ���� ���� ���� ����(���ӵ� �������� �̵��ϴ� �� ������Ų ���� Ȯ���ϱ� ����)
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
	F_I;
	/*
	[����] 1175�� : ��� (bfs_hard)

		������ 2���� ��޿���, 2���� ������ �� �߰��Ͽ� 4���� �迭�� Ǭ��! d[x][y][s][k]

	=> s�� ���� ���� 

		S���� C�� ����� ���µ�, S->C1->C2 ����� �ְ�, S->C2->C1 ����� �ִ�.

		���� �� ��Ȳ����,

		C1,C2 �Ѵ� ����� ���� ���� ��Ȳ : s=0
		C1�� ����� �� ��Ȳ : s=1
		C2�� ����� �� ��Ȳ : s=2
		C1,C2 �Ѵ� ����� �� ��Ȳ : s=3

		-> �� ������ s�� ��´�.

	=> k�� ���� ���� 

		���������� ���� �������� �̵� �� �� ���ٴ� ������ ó���ϱ� ���ؼ� �����ϴ� �κ��̴�.
		������ ����(0 ~ 4 �� �ϳ�)�� �̹��� ������ ���� (0 ~ 4 �� �ϳ�)�� ��ġ�ϸ� �ȵȴ�.

	*/
	int n, m;
	cin >> n >> m;
	vector<string> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	queue< tuple<int, int, int, int> >q;
	memset(d, -1, sizeof(d));

	int x1 = -1, y1 = -1, x2 = -1, y2 = -1;

	//s�� c 2�� ��ġ ���� ã��!
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 'S') //S�� ��ġ
			{
				for (int k = 0; k < 4; k++)
				{
					d[i][j][0][k] = 0;
					q.push({ i,j,0,k }); //��� ������ ���⿡�� (i,j)�� �Դٰ� �����ؾ� �Ѵ�. s==0 �� ������ ���� c1,c2�� �湮���� �ʾ����ϱ�! 
				}
			}
			if (arr[i][j] == 'C') //C�� ��ġ : 2�� ã��
			{
				if (x1 == -1 && y1 == -1)
				{
					x1 = i;
					y1 = j;
				}
				else
				{
					x2 = i;
					y2 = j;
				}
			}
		}
	}

	int ans = -1;

	while (!q.empty())
	{
		int x, y, st, dir;
		tie(x, y, st, dir) = q.front(); q.pop();

		if (st == 3) //c1,c2 ��� �湮������ �װ��� ���̴�!
		{
			ans = d[x][y][st][dir];
			break;
		}

		for (int k = 0; k < 4; k++)
		{
			if (k == dir) //���� 1 : ���� �̵��ߴ� ����� �̹��� �̵��Ϸ��� �ϴ� ������ ������, �̵��� �� ����.
				continue;

			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) //���� üũ!
			{
				if (arr[nx][ny] == '#') continue; //���� 2 : �̵��ϰ��� �ϴ� ���� # �̸� �̵� �Ұ�!

				//st�� �ϴ� �̵��ϱ� ���� �Ȱ��� �����س���, ���� �̵��� ���� c��� �׶� nst ���� ��������ֱ�!
				//�̵��� ���� C�� �ƴϸ� �׳� st�� �״�δϱ�!
				int nst = st;

				if (arr[nx][ny] == 'C') //�̵��� ���� c ���,
				{
					if (nx == x1 && ny == y1) // �̵��� ���� c1�̶��
					{
						nst |= 1; //+�� �ϸ� �ȵȴ�.
						//nst�� 0�� ��Ȳ���� c1�� �湮�ߴٸ� nst�� 1�� ��
						//nst�� 2�� ��Ȳ���� c1�� �湮�ߴٸ� nst�� 3�� ��
					}
					else //�̵��� ���� c2���
					{
						nst |= 2; //+�� �ϸ� �ȵȴ�.
						//nst�� 0�� ��Ȳ���� c2�� �湮�ߴٸ� nst�� 2�� ��
						//nst�� 1�� ��Ȳ���� c2�� �湮�ߴٸ� nst�� 3�� ��
					}
				}

				if (d[nx][ny][nst][k] == -1) //�湮�� ���� ���ٸ�,
				{
					d[nx][ny][nst][k] = d[x][y][st][dir] + 1;
					q.push({ nx,ny,nst,k });
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}

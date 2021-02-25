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

int arr[11][11];
int d[11][11][104][4]; //d[x][y][num][piece] >> num : num->num+1�� �����̴� ���� / piece : 0�̸� ����Ʈ/ 1�̸� ���/ 2�̸� ��

//����Ʈ�� ������
int kx[8] = { 2,1,1,2,-2,-1,-1,-2 }; 
int ky[8] = { 1,2,-2,-1,1,-2,2,-1 };
//����� ������
int bx[4] = { 1,-1,-1,1 };
int by[4] = { 1,-1,1,-1 };
//���� ������
int rx[4] = { 1,-1,0,0 };
int ry[4] = { 0,0,1,-1 };

int main()
{
	F_I;

	/*
	[����] 16959�� : ü���� ���� 1 (bfs_hard)

	- ���� ��ü�ϰų�/ ��(����Ʈ/���/��) �� �̵��ϰų� > ��� ��Ȳ���� �� �ΰ����� ��츦 ����ؾ� �Ѵ�.

	d[x][y][num][piece] : (x,y)�̰�, num���� num+1�� �̵��Ϸ��� �ϴ� ��Ȳ�̰�, �׶��� ���� piece �϶��� �ʿ��� �ּ� �ð� 
	�̶�  piece : 0�̸� ����Ʈ/ 1�̸� ���/ 2�̸� �� �̶�� ���!

	����) ������ ������
	
	����Ʈ : 8������ ������
	��� : �밢������ �Ÿ� ��� ���� �̵�
	�� : �����¿�� �Ÿ� ��� ���� �̵�

	*/
	int n;
	cin >> n;

	queue < tuple<int, int, int, int> > q;
	memset(d, -1, sizeof(d));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1) //1���� �����ϹǷ�, 1������ ����Ʈ, ���, ���� ��� ť�� �ִ´�. (3�� �� � ���� 1�� ���� �� �𸣴ϱ�)
			{
				for (int piece = 0; piece < 3; piece++)
				{
					d[i][j][1][piece] = 0; //1->2 �� ���� �����̴ϱ� num�� 1�̴�.
					q.push({ i,j,1,piece });
				}
			}
		}
	}

	int ans = 1e9;

	while (!q.empty())
	{
		int x, y, num, piece;
		tie(x, y, num, piece) = q.front(); q.pop();

		if (num == n * n) //num�� n*n�̸�, ������ ���̹Ƿ� �� ���� �߿����� �ּҸ� ���ϱ�
		{
			if (ans > d[x][y][num][piece]) //�ּҰ� ��!
			{
				ans = d[x][y][num][piece];
			}
		}

		//1. ���� ��ü�ϴ� ��� (�� ��쵵 1�� �ð� �ҿ�ȴ�.)
		for (int k = 0; k < 3; k++)
		{
			if (piece == k) continue; //���� �������� ��ü ���Ѵ�.

			if (d[x][y][num][k] == -1)
			{
				d[x][y][num][k] = d[x][y][num][piece] + 1;
				q.push({ x,y,num,k });
			}
		}

		//2. ���� �̵��ϴ� ��� (����Ʈ/ ���/ ��)

		if (piece == 0) //����Ʈ
		{
			for (int k = 0; k < 8; k++)
			{
				int nx = x + kx[k];
				int ny = y + ky[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n)
				{
					int next_num = num;
					if (arr[nx][ny] == num + 1) //������ �ڸ��� ���� num�̾��µ�, �� ������ �̵��� �ڸ��� ���� num+1 �̶��,
					{
						next_num += 1;
					}
					if (d[nx][ny][next_num][piece] == -1)
					{
						d[nx][ny][next_num][piece] = d[x][y][num][piece] + 1;
						q.push({ nx,ny,next_num,piece });
					}
				}
			}
		}
		if (piece == 1) //��� (�밢������ ������. (�Ÿ� �������) )
		{
			for (int k = 0; k < 4; k++)
			{
				for (int ex = 1;; ex++)
				{
					int nx = x + bx[k] * ex;
					int ny = y + by[k] * ex;

					if (nx >= 0 && nx < n && ny >= 0 && ny < n)
					{
						int next_num = num;
						if (arr[nx][ny] == num + 1) //������ �ڸ��� ���� num�̾��µ�, �� ������ �̵��� �ڸ��� ���� num+1 �̶��,
						{
							next_num += 1;
						}
						if (d[nx][ny][next_num][piece] == -1)
						{  
							d[nx][ny][next_num][piece] = d[x][y][num][piece] + 1;
							q.push({ nx,ny,next_num,piece });
						}
					}
					else //ü���� ���� ��������� ��� �� �������� ������ �� �ִ�.
						break;
				}
			}
		}
		if (piece == 2) //�� (�����¿�� ������. (�Ÿ� �������) )
		{
			for (int k = 0; k < 4; k++)
			{
				for (int ex = 1;; ex++) 
				{
					int nx = x + rx[k] * ex;
					int ny = y + ry[k] * ex;

					if (nx >= 0 && nx < n && ny >= 0 && ny < n)
					{
						int next_num = num;
						if (arr[nx][ny] == num + 1) //������ �ڸ��� ���� num�̾��µ�, �� ������ �̵��� �ڸ��� ���� num+1 �̶��,
						{
							next_num += 1; 
						}
						if (d[nx][ny][next_num][piece] == -1)
						{
							d[nx][ny][next_num][piece] = d[x][y][num][piece] + 1;
							q.push({ nx,ny,next_num,piece });
						}
					}
					else //ü���� ���� ��������� ��� �� �������� ������ �� �ִ�.
						break;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}

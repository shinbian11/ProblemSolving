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

int dir1[2][4] = { {0,0,1,-1},{1,-1,0,0} };
int dir2[2][8] = { {-1,-1,1,1,-2,-2,2,2},{2,-2,-2,2,1,-1,-1,1} };

int cost_near1[4] = { 0,0,0,0 };
int cost_near2[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };

int arr[204][204];
int d[204][204][32];

int main()
{
	//���� 1600�� : ���� �ǰ��� ������ (2������ �ƴ� 3���� �迭�� ����� BFS)
	//���� : 2206�� > �� �μ��� �̵��ϱ�

	F_I;
	int k, n, m;
	cin >> k;
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	memset(d, -1, sizeof(d));

	queue< tuple<int, int, int> >q;
	q.push(make_tuple(0, 0, 0));

	d[0][0][0] = 0;

	while (!q.empty())
	{
		int x, y, cost;
		tie(x, y, cost) = q.front();
		q.pop();


		//�����¿�θ� �̵�
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir1[0][i];
			int ny = y + dir1[1][i];
			int ncost = cost + cost_near1[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (arr[nx][ny] == 1) continue; //��ֹ��̸� ������ �� ����.

				if (d[nx][ny][ncost] == -1)
				{
					d[nx][ny][ncost] = d[x][y][cost] + 1;
					q.push(make_tuple(nx, ny, ncost));
				}

			}
		}


		//��ó�� �̵�
		for (int i = 0; i < 8; i++) 
		{
			int nx = x + dir2[0][i];
			int ny = y + dir2[1][i];
			int ncost = cost + cost_near2[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (arr[nx][ny] == 1) continue; //��ֹ��̸� ������ �� ����.

				if (d[nx][ny][ncost] == -1)
				{
					if (ncost <= k) //k�� Ƚ�� �ʰ� �ȵ�!
					{
						d[nx][ny][ncost] = d[x][y][cost] + 1;
						q.push(make_tuple(nx, ny, ncost));
					}

				}

			}
		}


		/*
		- dir �迭��, cost_near �迭�� �ѹ��� ��Ƽ� �̷��� �ѹ��� ó���ص� �ȴ�! 
		
		int dir[2][12] = { {0,0,1,-1, -1,-1,1,1,-2,-2,2,2},{1,-1,0,0,2,-2,-2,2,1,-1,-1,1} };
		int cost_near[12] = { 0,0,0,0,1,1,1,1,1,1,1,1 };

		for (int i = 0; i < 12; i++) // �ѹ��� ó��!
		{
			int nx = x + dir[0][i];
			int ny = y + dir[1][i];
			int ncost = cost + cost_near[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (arr[nx][ny] == 1) continue; //��ֹ��̸� ������ �� ����.

				if (d[nx][ny][ncost] == -1)
				{
					if (ncost <= k) //cost�� ���� ���� �ʴ� ���(�����¿츸 �̵�) �� cost�� 1 ��� ���(��ó�� �̵�)�� ��� �����Ѵ�! �ѹ��� ó�� ����!
 					{
						d[nx][ny][ncost] = d[x][y][cost] + 1;
						q.push(make_tuple(nx, ny, ncost));
					}
				}

			}
		}

		*/

	}



	int ans = 50000;

	for (int i = 0; i <= k; i++)
	{
		if (d[n - 1][m - 1][i] == -1)
			continue;
		else
		{
			if (ans > d[n - 1][m - 1][i])
				ans = d[n - 1][m - 1][i];
		}

	}

	if (ans == 50000)
		cout << -1 << '\n';
	else
		cout << ans << '\n';


	return 0;
}
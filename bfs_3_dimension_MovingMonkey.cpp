#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int dir1[2][4] = { {0,0,1,-1},{1,-1,0,0} };
int dir2[2][8] = { {-1,-1,1,1,-2,-2,2,2},{2,-2,-2,2,1,-1,-1,1} };

int cost_near1[4] = { 0,0,0,0 };
int cost_near2[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };

int arr[204][204];
int d[204][204][32];

int main()
{
	//백준 1600번 : 말이 되고픈 원숭이 (2차원이 아닌 3차원 배열을 사용한 BFS)
	//참고 : 2206번 > 벽 부수고 이동하기

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


		//상하좌우로만 이동
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir1[0][i];
			int ny = y + dir1[1][i];
			int ncost = cost + cost_near1[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (arr[nx][ny] == 1) continue; //장애물이면 움직일 수 없다.

				if (d[nx][ny][ncost] == -1)
				{
					d[nx][ny][ncost] = d[x][y][cost] + 1;
					q.push(make_tuple(nx, ny, ncost));
				}

			}
		}


		//말처럼 이동
		for (int i = 0; i < 8; i++) 
		{
			int nx = x + dir2[0][i];
			int ny = y + dir2[1][i];
			int ncost = cost + cost_near2[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (arr[nx][ny] == 1) continue; //장애물이면 움직일 수 없다.

				if (d[nx][ny][ncost] == -1)
				{
					if (ncost <= k) //k번 횟수 초과 안됨!
					{
						d[nx][ny][ncost] = d[x][y][cost] + 1;
						q.push(make_tuple(nx, ny, ncost));
					}

				}

			}
		}


		/*
		- dir 배열과, cost_near 배열을 한번에 담아서 이렇게 한번에 처리해도 된다! 
		
		int dir[2][12] = { {0,0,1,-1, -1,-1,1,1,-2,-2,2,2},{1,-1,0,0,2,-2,-2,2,1,-1,-1,1} };
		int cost_near[12] = { 0,0,0,0,1,1,1,1,1,1,1,1 };

		for (int i = 0; i < 12; i++) // 한번에 처리!
		{
			int nx = x + dir[0][i];
			int ny = y + dir[1][i];
			int ncost = cost + cost_near[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (arr[nx][ny] == 1) continue; //장애물이면 움직일 수 없다.

				if (d[nx][ny][ncost] == -1)
				{
					if (ncost <= k) //cost가 전혀 들지 않는 경우(상하좌우만 이동) 과 cost가 1 드는 경우(말처럼 이동)를 모두 포괄한다! 한번에 처리 가능!
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
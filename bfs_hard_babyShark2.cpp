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
				//아기상어가 여러마리 있다고 하더라도, 빈칸에서 bfs를 통해 한 칸씩 탐색 하다가 마주하는 아기상어와의 첫 만남이 곧 안전 거리 이므로, 
				//arr[nx][ny] == 1 을 만족하자마자 (맨 처음 만나는 아기상어일때), 바로 d[x][y] + 1 값을 반환하면 된다!
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
	//[백준] 17086번 : 아기 상어 2
	/*
	각각의 빈칸에서, BFS를 하여 가장 가까운 아기상어와의 거리(안전 거리)를 구한다 (bfs(i,j) 함수를 이용하여)
	bfs(i,j)의 반환값 중 최대 거리를 출력!
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
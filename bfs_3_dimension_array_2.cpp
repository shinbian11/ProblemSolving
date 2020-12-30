#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int a[1001][1001]; // 배열 저장
int wall[1001][1001][12];
int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int n, m, k;

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

	//백준 14442번 : 벽 부수고 이동하기 2
	//2206번 벽 부수고 이동하기 과의 차이점 : 2206은 최대 1번만 벽을 부실 수 있고, 14442번은 최대 k번 부실 수 있다.
	//즉 삼차원 배열의 3번째 []을 k개까지 만들어야 한다.

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
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
			if (isinside(nx, ny) && a[nx][ny] == 1  && wall[nx][ny][z + 1] == 0 && (z + 1) <= k) //다음 갈 곳이 벽인데, 아직 벽을 부실 수 있는 횟수가 남은 경우
			{
				wall[nx][ny][z + 1] = wall[x][y][z] + 1; // 벽을 한번 부시게 됨
				q.push(make_tuple(nx, ny, z + 1));
			}
			if (isinside(nx, ny) && a[nx][ny] == 0 && wall[nx][ny][z] == 0) //다음 갈곳이 벽이 아니고 그냥 갈수 있는 곳일떄
			{
				wall[nx][ny][z] = wall[x][y][z] + 1;
				q.push(make_tuple(nx, ny, z));
			}
		}
	}
	int ans = 1e9;
	for (int i = 0; i <= k; i++) //i<k가 아니라 i<=k이다! 최대 k번 부실 수 있으니까, k번을 모두 사용하고 도착점에 도착하는 경우도 생각해야 함!
	{
		if (wall[n - 1][m - 1][i] != 0)
		{
			if (ans > wall[n - 1][m - 1][i])
				ans = wall[n - 1][m - 1][i];
		}
	}
	if (ans == 1e9)
		cout << "-1" << '\n';
	else
		cout << ans << '\n';
	return 0;
}
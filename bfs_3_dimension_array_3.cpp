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
int wall[1001][1001][12][2];
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

	//백준 16933번 : 벽 부수고 이동하기 3
	//백준 14442번의 벽 부수고 이동하기 2에다가 낮과 밤만 추가된 것이다. 4차원 배열로!!
	//즉 4차원 배열의 4번째 []는 낮과 밤을 체크하는 용도로 사용하면 된다.
	//57번째 줄에서 다른 곳으로 이동하지 않고, 가만히 있는 경우도 생각을 해줘야 한다! 이것만 주의하면 됨!!

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}

	queue<tuple<int, int, int, int>> q;
	q.push(make_tuple(0, 0, 0, 0));

	wall[0][0][0][0] = 1;

	while (!q.empty())
	{
		int x, y, z, day;
		tie(x, y, z, day) = q.front();
		q.pop();

		if (wall[x][y][z][1 - day] == 0) //주의! 움직이지 않고 가만히 있는 경우(낮과 밤만 바뀌고, 그것도 횟수로 쳐야 하므로 1을 더한다.)
		{
			wall[x][y][z][1 - day] = wall[x][y][z][day] + 1; 
			q.push(make_tuple(x, y, z, 1 - day));
		}
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (isinside(nx, ny) && a[nx][ny] == 1 && wall[nx][ny][z + 1][1 - day] == 0 && (z + 1) <= k && day == 0) //다음 갈 곳이 벽인데, 아직 벽을 부실 수 있는 횟수가 남았고, 낮인 경우
			{
				wall[nx][ny][z + 1][1 - day] = wall[x][y][z][day] + 1; // 벽을 한번 부시게 됨
				q.push(make_tuple(nx, ny, z + 1, 1 - day));
			}
			if (isinside(nx, ny) && a[nx][ny] == 0 && wall[nx][ny][z][1 - day] == 0) //다음 갈곳이 벽이 아니고 그냥 갈수 있는 곳일떄
			{
				wall[nx][ny][z][1 - day] = wall[x][y][z][day] + 1;
				q.push(make_tuple(nx, ny, z, 1 - day));
			}
		}
		
		
	}
	int ans = 1e9;
	for (int i = 0; i <= k; i++) //i<k가 아니라 i<=k이다! 최대 k번 부실 수 있으니까, k번을 모두 사용하고 도착점에 도착하는 경우도 생각해야 함!
	{
		for (int j = 0; j < 2; j++)
		{
			if (wall[n - 1][m - 1][i][j] != 0)
			{
				if (ans > wall[n - 1][m - 1][i][j])
					ans = wall[n - 1][m - 1][i][j];
			}
		}
	}
	if (ans == 1e9)
		cout << "-1" << '\n';
	else
		cout << ans << '\n';

	return 0;
}
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
int wall[1001][1001][2]; //wall[x][y][z] = x행 y열 에서 z번 벽을 부셨다.
int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int n, m;

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
	
	//백준 2206번 : 벽 부수고 이동하기 (삼차원 배열 + bfs)
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d",&a[i][j]);
		}
	}

	queue<tuple<int,int,int>> q;
	q.push(make_tuple(0,0,0));
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
			if (isinside(nx, ny) && a[nx][ny] == 1 && z==0 && wall[nx][ny][z+1] == 0) //다음 갈 곳이 벽인데, 아직 한번도 벽을 부시지 않은 경우. 
			{   // wall[nx][ny][z+1]==0 이라는 말은, 이번에 벽을 부시고 갈 건데, nx행 ny열(다음에 방문할 부분)이 아직 방문이 안되었다는 의미이다. 
				// wall 배열은 방문횟수를 저장함과 동시에, 방문횟수도 체크가 가능하다(0이 들어있으면 아직 방문 안했다는 의미이니까)
				wall[nx][ny][z+1] = wall[x][y][z] + 1; // 벽을 한번 부시게 됨
				q.push(make_tuple(nx, ny, z + 1));
			}
			if (isinside(nx, ny) && a[nx][ny] == 0 && wall[nx][ny][z] == 0) //다음 갈곳이 벽이 아니고 그냥 갈수 있는 곳 일떄
			{
				wall[nx][ny][z] = wall[x][y][z] + 1;
				q.push(make_tuple(nx, ny, z));
			}
		}
	}
	if (wall[n - 1][m - 1][0] != 0 && wall[n - 1][m - 1][1] != 0)
		cout << Min(wall[n - 1][m - 1][0], wall[n - 1][m - 1][1]) << '\n';
	else if (wall[n - 1][m - 1][0] != 0 && wall[n - 1][m - 1][1] == 0)
		cout << wall[n - 1][m - 1][0] << '\n';
	else if (wall[n - 1][m - 1][0] == 0 && wall[n - 1][m - 1][1] != 0)
		cout << wall[n - 1][m - 1][1] << '\n';
	else
		cout << "-1" << '\n';
	return 0;
}
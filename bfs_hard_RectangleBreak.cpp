#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int dx[4] = { -1,0,1,0 }; //상우하좌 방향
int dy[4] = { 0, 1,0,-1 };
int arr[1004][1004];
int d[1004][1004];
int n, m;
int h, w, sx, sy, ex, ey;

bool isinside(int x, int y,int dir)
{
	//직사각형이 격자판 범위를 넘어가지 않아야 한다.
	//dir :  0  1  2  3
	//방향 : 상 우 하 좌

	if (dir == 0) //상
	{
		if ((x - 1 >= 1 && x - 1 <= n && y >= 1 && y <= m) && (x - 1 >= 1 && x - 1 <= n && y + w - 1 >= 1 && y + w - 1 <= m) && (x + h - 2 >= 1 && x + h - 2 <= n && y >= 1 && y <= m) && (x + h - 2 >= 1 && x + h - 2 <= n && y + w - 1 >= 1 && y + w - 1 <= m))
			return true;
		else
			return false;
	}
	else if (dir == 1) //우
	{
		if ((x >= 1 && x <= n && y + 1 >= 1 && y + 1 <= m) && (x >= 1 && x <= n && y + w >= 1 && y + w <= m) && (x + h - 1 >= 1 && x + h - 1 <= n && y + 1 >= 1 && y + 1 <= m) && (x + h - 1 >= 1 && x + h - 1 <= n && y + w >= 1 && y + w <= m))
			return true;
		else
			return false;
	}
	else if (dir == 2) //좌
	{
		if ((x + 1 >= 1 && x + 1 <= n && y >= 1 && y <= m) && (x + 1 >= 1 && x + 1 <= n && y + w - 1 >= 1 && y + w - 1 <= m) && (x + h >= 1 && x + h <= n && y >= 1 && y <= m) && (x + h >= 1 && x + h <= n && y + w - 1 >= 1 && y + w - 1 <= m))
			return true;
		else
			return false;
	}
	else if (dir == 3) //우
	{
		if ((x >= 1 && x <= n && y - 1 >= 1 && y - 1 <= m) && (x >= 1 && x <= n && y + w >= 1 && y + w <= m) && (x + h - 1 >= 1 && x + h - 1 <= n && y - 1 >= 1 && y - 1 <= m) && (x + h - 1 >= 1 && x + h - 1 <= n && y + w >= 1 && y + w <= m))
			return true;
		else
			return false;
	}
}

bool notWall(int x, int y,int dir)
{
	//직사각형이 벽과 겹치면 안된다 == 직사각형이 움직여서 생긴 새로운 범위에 벽이 있으면 안된다
	//그 말은 다시 말해, 움직여서 생긴 새로운 부분의 합이 0이여야 한다. (합이 1 이상이면 움직인 부분에 벽이 최소 1개 이상 있다는 의미니까)
	//dir :  0  1  2  3
	//방향 : 상 우 하 좌

	if (dir == 0) //상
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
	else if (dir == 1) //우
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
	else if (dir == 2) //좌
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
	else if (dir == 3) //우
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

	// [백준] 16973번 : 직사각형 탈출 (bfs - 일반적인 미로 탈출과 다른 점)

	// 직사각형이 1 x 1 이었다면 , 그냥 일반적인 미로 탈출 문제이고 O(NM)의 시간이 소요 되므로 상관없지만, 
	// 이 문제는 직사각형이 H x W 이므로, 이 직사각형 내부에 벽이 있는지의 여부를 판단하는 데에도 O(HW)의 시간이 소요된다.
	// 즉, 일반적인 문제처럼 풀면 O(NMHW) 의 시간이 소요되므로, 시간초과가 난다!! (문제 제출 이력 아래에서 2번째 '시간초과' 제출 참고!)
	// 이 직사각형 내부에 벽이 있는지의 여부를 판단하는 시간은 O(HW)에서 O(H) or O(W)로 줄여야 한다! ( notWall() 부분 )

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

	//직사각형의 왼쪽 상단 꼭짓점을 기준으로 한다.
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


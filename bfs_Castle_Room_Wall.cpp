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

int arr[54][54]; // 칸 정보 입력
int d[54][54]; //각 칸이 속한 방의 번호
int room[50 * 50 + 4]; //방의 정보 : room[i] : i번째 방의 크기

//i=0 서쪽, i=1 북쪽, i=2 동쪽, i=3 남쪽이다. 순서 지켜야 함!
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

int m, n;

int bfs(int i, int j, int  rooms) //(i,j)번째에서 시작된 rooms번째 방의 크기를 return
{
	int size = 1;

	d[i][j] = rooms;
	queue<pi> q;
	q.push(make_pair(i, j));

	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && nx < m)
			{
				if ((d[nx][ny] == 0) && !(arr[x][y] & (1 << i))) //(x,y)행에서 (nx,ny)행 쪽으로 이동하는 데에 벽이 있으면 안되니까.
					//arr[x][y] & (1 << i) 이 1이면, i번째가 가르키는 방향에 벽이 있다는 의미인데,
					//i=0 서쪽, i=1 북쪽, i=2 동쪽, i=3 남쪽이다.
				{
					size += 1;
					d[nx][ny] = rooms;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	return size; //방 크기 return
}

int main()
{
	F_I;

	//[백준] 2234번 : 성곽 (비트마스킹, BFS)

	cin >> m >> n; //입력 순서 주의! n>>m 아니고 m>>n 이다.

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
	
	memset(d, 0, sizeof(d));

	//1번
	int rooms = 0; //방 번호

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (d[i][j] == 0) //(i,j)행의 방 번호가 정해지지 않았으면
			{
				rooms += 1;
				int cnt = bfs(i, j, rooms); //(i,j)번째에서 시작된 rooms번째 방의 크기를 return
				room[rooms] = cnt; //rooms 번째 방의 크기는 cnt 이다.
			}
		}
	}


	cout << rooms << '\n'; //방 개수

	//2번
	int mx = -1;
	for (int i = 1; i <= rooms; i++)
	{
		if (mx == -1 || mx < room[i])
			mx = room[i];
	}

	cout << mx << '\n'; //가장 큰 방의 크기


	//3번
	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int x = i + dx[k];
				int y = j + dy[k];
				if (x >= 0 && x < n && y >= 0 && y < m)
				{
					if (d[i][j] != d[x][y]) //(i,j)칸의 방 번호와 (x,y) 칸의 방 번호가 다를 때 (서로 다른 방일때, 벽을 제거하고 합칠 수 있을 때)
					{
						//d[i][j]번 방의 크기와 d[x][y]번 방의 크기의 최대값을 구한다.
						int tmp = room[d[i][j]] + room[d[x][y]]; 
						if (ans == -1 || ans < tmp)
							ans = tmp;
					}
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
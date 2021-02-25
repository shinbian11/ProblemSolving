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

int arr[11][11];
int d[11][11][104][4]; //d[x][y][num][piece] >> num : num->num+1로 움직이는 상태 / piece : 0이면 나이트/ 1이면 비숍/ 2이면 룩

//나이트의 움직임
int kx[8] = { 2,1,1,2,-2,-1,-1,-2 }; 
int ky[8] = { 1,2,-2,-1,1,-2,2,-1 };
//비숍의 움직임
int bx[4] = { 1,-1,-1,1 };
int by[4] = { 1,-1,1,-1 };
//룩의 움직임
int rx[4] = { 1,-1,0,0 };
int ry[4] = { 0,0,1,-1 };

int main()
{
	F_I;

	/*
	[백준] 16959번 : 체스판 여행 1 (bfs_hard)

	- 말을 교체하거나/ 말(나이트/비숍/룩) 을 이동하거나 > 모든 상황에서 이 두가지의 경우를 고려해야 한다.

	d[x][y][num][piece] : (x,y)이고, num에서 num+1로 이동하려고 하는 상황이고, 그때의 말이 piece 일때의 필요한 최소 시간 
	이때  piece : 0이면 나이트/ 1이면 비숍/ 2이면 룩 이라고 잡기!

	참고) 말들의 움직임
	
	나이트 : 8가지의 움직임
	비숍 : 대각선으로 거리 상관 없이 이동
	룩 : 상하좌우로 거리 상관 없이 이동

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
			if (arr[i][j] == 1) //1에서 시작하므로, 1에서의 나이트, 비숍, 룩을 모두 큐에 넣는다. (3개 중 어떤 말을 1에 놓을 지 모르니까)
			{
				for (int piece = 0; piece < 3; piece++)
				{
					d[i][j][1][piece] = 0; //1->2 로 가는 과정이니까 num은 1이다.
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

		if (num == n * n) //num이 n*n이면, 도착한 것이므로 이 경우들 중에서의 최소를 구하기
		{
			if (ans > d[x][y][num][piece]) //최소값 비교!
			{
				ans = d[x][y][num][piece];
			}
		}

		//1. 말을 교체하는 경우 (이 경우도 1의 시간 소요된다.)
		for (int k = 0; k < 3; k++)
		{
			if (piece == k) continue; //같은 말끼리는 교체 못한다.

			if (d[x][y][num][k] == -1)
			{
				d[x][y][num][k] = d[x][y][num][piece] + 1;
				q.push({ x,y,num,k });
			}
		}

		//2. 말을 이동하는 경우 (나이트/ 비숍/ 룩)

		if (piece == 0) //나이트
		{
			for (int k = 0; k < 8; k++)
			{
				int nx = x + kx[k];
				int ny = y + ky[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n)
				{
					int next_num = num;
					if (arr[nx][ny] == num + 1) //원래의 자리의 수가 num이었는데, 그 다음에 이동한 자리의 수가 num+1 이라면,
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
		if (piece == 1) //비숍 (대각선으로 움직임. (거리 상관없이) )
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
						if (arr[nx][ny] == num + 1) //원래의 자리의 수가 num이었는데, 그 다음에 이동한 자리의 수가 num+1 이라면,
						{
							next_num += 1;
						}
						if (d[nx][ny][next_num][piece] == -1)
						{  
							d[nx][ny][next_num][piece] = d[x][y][num][piece] + 1;
							q.push({ nx,ny,next_num,piece });
						}
					}
					else //체스판 범위 벗어날때까지 계속 그 방향으로 움직일 수 있다.
						break;
				}
			}
		}
		if (piece == 2) //룩 (상하좌우로 움직임. (거리 상관없이) )
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
						if (arr[nx][ny] == num + 1) //원래의 자리의 수가 num이었는데, 그 다음에 이동한 자리의 수가 num+1 이라면,
						{
							next_num += 1; 
						}
						if (d[nx][ny][next_num][piece] == -1)
						{
							d[nx][ny][next_num][piece] = d[x][y][num][piece] + 1;
							q.push({ nx,ny,next_num,piece });
						}
					}
					else //체스판 범위 벗어날때까지 계속 그 방향으로 움직일 수 있다.
						break;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}

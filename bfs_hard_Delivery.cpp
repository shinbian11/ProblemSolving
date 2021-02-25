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

int d[51][51][4][4]; //d[x][y][s][k] : (x,y)이 현재 좌표이고, s는 c 방문 정보, k는 (x,y)로 왔을 때의 방향 정보(연속된 방향으로 이동하는 걸 금지시킨 조건 확인하기 위해)
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
	F_I;
	/*
	[백준] 1175번 : 배달 (bfs_hard)

		기존의 2차원 배달에서, 2개의 차원을 더 추가하여 4차원 배열로 푼다! d[x][y][s][k]

	=> s에 대한 설명 

		S에서 C로 배달을 가는데, S->C1->C2 방법이 있고, S->C2->C1 방법이 있다.

		현재 내 상황에서,

		C1,C2 둘다 배달을 가지 못한 상황 : s=0
		C1만 배달을 간 상황 : s=1
		C2만 배달을 간 상황 : s=2
		C1,C2 둘다 배달을 간 상황 : s=3

		-> 이 정보를 s에 담는다.

	=> k에 대한 설명 

		연속적으로 같은 방향으로 이동 할 수 없다는 조건을 처리하기 위해서 존재하는 부분이다.
		기존의 방향(0 ~ 4 중 하나)과 이번에 움직일 방향 (0 ~ 4 중 하나)이 일치하면 안된다.

	*/
	int n, m;
	cin >> n >> m;
	vector<string> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	queue< tuple<int, int, int, int> >q;
	memset(d, -1, sizeof(d));

	int x1 = -1, y1 = -1, x2 = -1, y2 = -1;

	//s와 c 2개 위치 정보 찾기!
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 'S') //S의 위치
			{
				for (int k = 0; k < 4; k++)
				{
					d[i][j][0][k] = 0;
					q.push({ i,j,0,k }); //모든 인접한 방향에서 (i,j)로 왔다고 생각해야 한다. s==0 인 이유는 아직 c1,c2에 방문하지 않았으니까! 
				}
			}
			if (arr[i][j] == 'C') //C의 위치 : 2개 찾기
			{
				if (x1 == -1 && y1 == -1)
				{
					x1 = i;
					y1 = j;
				}
				else
				{
					x2 = i;
					y2 = j;
				}
			}
		}
	}

	int ans = -1;

	while (!q.empty())
	{
		int x, y, st, dir;
		tie(x, y, st, dir) = q.front(); q.pop();

		if (st == 3) //c1,c2 모두 방문했으면 그것이 답이다!
		{
			ans = d[x][y][st][dir];
			break;
		}

		for (int k = 0; k < 4; k++)
		{
			if (k == dir) //조건 1 : 직전 이동했던 방향과 이번에 이동하려고 하는 방향이 같으면, 이동할 수 없다.
				continue;

			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) //범위 체크!
			{
				if (arr[nx][ny] == '#') continue; //조건 2 : 이동하고자 하는 곳이 # 이면 이동 불가!

				//st는 일단 이동하기 전과 똑같이 복사해놓고, 만약 이동한 곳이 c라면 그때 nst 값을 변경시켜주기!
				//이동한 곳이 C가 아니면 그냥 st는 그대로니까!
				int nst = st;

				if (arr[nx][ny] == 'C') //이동한 곳이 c 라면,
				{
					if (nx == x1 && ny == y1) // 이동한 곳이 c1이라면
					{
						nst |= 1; //+로 하면 안된다.
						//nst가 0인 상황에서 c1을 방문했다면 nst는 1이 됨
						//nst가 2인 상황에서 c1을 방문했다면 nst는 3이 됨
					}
					else //이동한 곳이 c2라면
					{
						nst |= 2; //+로 하면 안된다.
						//nst가 0인 상황에서 c2을 방문했다면 nst는 2이 됨
						//nst가 1인 상황에서 c2을 방문했다면 nst는 3이 됨
					}
				}

				if (d[nx][ny][nst][k] == -1) //방문한 적이 없다면,
				{
					d[nx][ny][nst][k] = d[x][y][st][dir] + 1;
					q.push({ nx,ny,nst,k });
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}

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

int arr[24][24];
bool visited[24][24];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m;

int bfs()
{
	int ans = 0;

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 2 && visited[i][j] == false) //처음 방문되는, 상대편의 바둑돌 일때
			{
				queue<pi> q;
				q.push(make_pair(i, j));
				visited[i][j] = true; //방문했으니까

				bool dead = true; //해당 그룹이 죽임을 당할 수 있는 그룹인지를 판단.
				int tmp = 0; //죽일 수 있는 상대편 바둑돌의 개수. 최종적으로 dead 가 true인 경우에만 이 개수가 답에 더해지는 것이 인정된다.

				while (!q.empty())
				{
					tmp += 1; //개수 세기!

					int x, y;
					tie(x, y) = q.front();
					q.pop();

					for (int i = 0; i < 4; i++)
					{
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (nx >= 0 && nx < n && ny >= 0 && ny < m)
						{
							if (arr[nx][ny] == 2 && visited[nx][ny] == false)  //주변에 또다른 상대편 바둑돌이 있다면, push 하기!
							{
								visited[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
							if (arr[nx][ny] == 0) //주변에 빈칸(0) 이 하나라도 있다면 => 그 해당 arr[x][y] 점에서 시작한 그룹은 죽일 수 있는 그룹이 아니다.
								dead = false;
						}
					}
				}
				if (dead) //arr[x][y]점에서 시작한 그룹이 최종적으로도 죽일 수 있는 그룹이면
				{
					ans += tmp; //그 그룹에서 죽일 수 있는 상대편 돌의 개수를 더해준다.
				}
			}
		}
	}

	return ans;
}

int main()
{
	F_I;

	//[백준] 16988번 : Baaaaaaaaaduk2 (Easy) (브루트 포스)
	// 두개의 돌을 놓을 위치를 정하는 경우의 수 > NM * NM
	// 두개의 돌을 놓을 위치를 정한 이후, bfs를 통해 죽일 수 있는 상대편 돌 개수를 세는 경우 > NM
	// 즉 O((NM)^3) => 시간 내에 가능!

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	int ans = 0;

	for (int i1 = 0; i1 < n; i1++) //첫번째 돌 
	{
		for (int j1 = 0; j1 < m; j1++)
		{
			if (arr[i1][j1] != 0) continue; //첫번째 돌을 놓고자 하는 위치가 빈칸이 아니면 넘기기!

			for (int i2 = 0; i2 < n; i2++) //두번째 돌
			{
				for (int j2 = 0; j2 < m; j2++)
				{
					if (arr[i2][j2] != 0) continue; //두번째 돌을 놓고자 하는 위치가 빈칸이 아니면 넘기기!

					if (i1 == i2 && j1 == j2) continue; // 첫번째 돌을 놓고자 하는 위치와 두번째 돌을 놓고자 하는 위치가 같으면 안돼!

					//두 곳에 돌을 놓았을 때
					arr[i1][j1] = 1;
					arr[i2][j2] = 1;

					int tmp = bfs();
					if (ans < tmp)
						ans = tmp;

					//두 곳에 놓았던 돌을 다시 원상복귀 시키기!
					arr[i1][j1] = 0;
					arr[i2][j2] = 0;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
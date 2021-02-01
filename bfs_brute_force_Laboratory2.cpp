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

int n, m;
int arr[54][54];
int d[54][54];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int ans_res = -1; //최종 답

vector<pi> virus; //바이러스를 놓을 수 있는 위치들 저장

void bfs()
{
	queue<pi> q;

	memset(d, -1, sizeof(d));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 2) //바이러스가 실제로 설치되어 있는 공간
			{
				d[i][j] = 0;
				q.push(make_pair(i, j));
			}
		}
	} 

	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if (arr[nx][ny] != 1 && d[nx][ny] == -1) //벽이 아니고, 처음 방문하는 곳이라면
				{
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	int ans = -1e9;

	// d 배열에 모두 바이러스가 퍼졌을 때, 최종적으로 모든 칸에 바이러스가 퍼졌을 때의 '최종 시간'을 구한다
	// 벽이 아닌데도 방문하지 못한 점은, 다시 말해 고립된 점이라서 바이러스가 도달할 수 없는 점이라는 의미인데, 그런 점이 존재한다면 이 경우는 그냥 종료하기!
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)  continue; //벽이 아니어야 하고,

			//벽이 아닌데도 방문하지 못한 점이 있다는 것은, 이 경우에는 바이러스가 도달하지 못하는 칸이 존재한다는 의미이므로 이 경우는 제외.
			//바이러스가 모든 칸에 퍼지는 경우들만 가지고 따져야 한다.
			if (d[i][j] == -1) return; //종료
			
			if (ans < d[i][j])
				ans = d[i][j];
		}
	}

	if (ans_res == -1 || ans_res > ans) //연구소의 모든 빈 칸에 바이러스가 있게 되는 최소 시간인지 판단
		ans_res = ans;

	return;
}

void permu(int idx, int cnt)
{
	if (idx == virus.size()) //모든 바이러스 칸 후보에 대해서 바이러스를 놓을지 말지를 결정했을 때 
	{
		if (cnt == m) //문제에서 놓아야 하는 개수 M개만큼 놓았을 때에만, 
		{
			bfs(); //bfs를 통해서 생각해본다.
		}
	}
	else //모든 바이러스 칸 후보에 대해서 바이러스를 놓을지 말지를 아직 다 결정하지 못했다면,
	{
		int x = virus[idx].first;
		int y = virus[idx].second;

		//바이러스를 놓을 수 있는 후보가 들어있는 벡터의 idx번째 자리에 바이러스를 놓았을 때
		arr[x][y] = 2;
		permu(idx + 1, cnt + 1);

		//바이러스를 놓을 수 있는 후보가 들어있는 벡터의 idx번째 자리에 바이러스를 놓지 않았을 때
		arr[x][y] = 0;
		permu(idx + 1, cnt);
	}
	
	
	return;
}

int main()
{
	F_I;

	//[백준] 17141번 : 연구소 2 (bfs)
	//바이러스를 놓을 수 있는 경우의 수 : 2^M 가지. 각각의 경우에 대해 bfs를 해본다.

	cin >> n >> m;
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				arr[i][j] = 0; //빈칸으로 취급
				virus.emplace_back(i, j); //바이러스를 놓을 수 있는 장소들의 정보들만 따로 저장
			}
		}
	}

	permu(0, 0);

	cout << ans_res << '\n';

	return 0;
}
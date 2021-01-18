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

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector< vector<int> > bfs(vector<string>& arr, int x, int y)
{
	int m = arr[0].length();
	int n = arr.size();
	vector< vector<int> > res(n, vector<int>(m, -1));

	queue<pi> q;
	q.push(make_pair(x, y));
	res[x][y] = 0;

	while (!q.empty())
	{
		int sx, sy;
		tie(sx, sy) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (res[nx][ny] == -1 && arr[nx][ny] != 'x') //이동하고자 하는 곳이 가구('x')면 이동 못함
				{
					res[nx][ny] = res[sx][sy] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	return res;
}
int main()
{
	/*
	
	[백준] 4991번 : 로봇 청소기 (BFS + 조합(permutation))
	
	- 먼지의 위치는 바뀌지 않는다.
	- 그러므로 로봇 청소기의 위치와 먼지들의 위치, 그리고 각각의 번호를 매겨서 정보를 저장해놓고,
	- 최단거리의 합을 구한다.
	
	- 먼지를 치우는 순서도 중요하다.
	e.g.) 먼지가 3개이고, 1번 먼지, 2번 먼지, 3번 먼지라고 하고,
	    로봇 청소기를 0번 먼지 라고 가정한다면 (물론 로봇을 0번 먼지라 가정해도 치울 때의 최단거리의 합에는 영향을 안 미치게 설계)
		0번을 시작점으로 고정 시켜놓고,
		1->2->3
		1->3->2
		2->1->3
		2->3->1
		3->1->2
		3->2->1
		=> 이 6가지의 순서에 따라 최단거리의 합이 달라질 수 있다.
		=> 그러므로, 먼지와 먼지 사이의 최단거리를 bfs를 통해서 구해놓고, 그 이후에 permutation을 돌려서 최단 거리의 합을 찾는다.

	*/
	
	while (true)
	{
		int n, m;
		cin >> m >> n;

		if (n == 0 && m == 0)
			return 0;

		vector<string> arr(n);
		vector<pi> dirty(1);

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 'o')
				{
					dirty[0] = make_pair(i, j); //로봇은 0번먼지
				}
				else if (arr[i][j] == '*') //먼지는 1번 부터
				{
					dirty.push_back(make_pair(i, j));
				}
			}
		}

		int cnt = dirty.size(); //로봇 + 먼지의 개수
		bool ok = true;
		vector< vector<int> > dist(cnt, vector<int>(cnt)); // dist[i][j] = i번째 먼지가 있는 장소에서 j번째 먼지가 있는 장소로 이동할때의 최소 거리

		for (int i = 0; i < cnt; i++)
		{
			/*
			i번 먼지를 시작점으로 한 bfs를 구한다. 
			시작점은 dirty에 들어있는 모든 점이 가능하므로, 각각에 대한 bfs를 실행해야 한다.
			
			i가 0일때만 bfs를 돌리면, 0번 먼지에서 나머지 먼지로 가는 경로는 저장되었지만, 
			예를 들어 1번 먼지에서 3번 먼지로 가는 dist[1][3]과 같은 값은 아직 저장이 되지 않았으므로, bfs는 각각에 대해 cnt번 실행해야 한다.
			*/
			vector< vector<int> > res = bfs(arr, dirty[i].first, dirty[i].second); 
			for (int j = 0; j < cnt; j++)
			{
				dist[i][j] = res[dirty[j].first][dirty[j].second]; 
				//(i번 먼지에서) j번 먼지로 이동하는 최소 거리(== res[dirty[j].first][dirty[j].second]) 를 dist[i][j] 에 기록한다.

				if (dist[i][j] == -1) //만약에 이동할 수 없는 먼지가 있다면, bfs 반환값을 받았을 때 이미 그 res 배열의 해당 위치에는 -1이 있을 것이다. (== dist[i][j]==-1)
				{
					ok = false;
				}
			}
		}

		if (ok == false) // 이동 할 수 없는 먼지가 있다면 -1 출력
		{
			cout << "-1" << '\n';
			continue;
		}
		else
		{
			int ans = 1e9;
			vector<int> permu(cnt);
			for (int i = 0; i < cnt; i++)
			{
				permu[i] = i;
			}
			
			do
			{
				int sum = dist[0][permu[0]];

				for (int i = 0; i < cnt - 1; i++)
				{
					sum += dist[permu[i]][permu[i + 1]];
				}

				if (ans > sum)
				{
					ans = sum;
				}
				
			} while (next_permutation(permu.begin(), permu.end()));

			/*
			int ans = 1e9;
			vector<int> permu(cnt - 1);
			for (int i = 0; i < cnt-1; i++)
			{
				permu[i] = i+1;
			}

			do
			{
				int sum = dist[0][permu[0]];
				for (int i = 0; i < cnt - 2; i++)
				{
					sum += dist[permu[i]][permu[i + 1]];
				}
				if (ans > sum)
				{
					ans = sum;
				}

			} while (next_permutation(permu.begin(), permu.end()));
			*/
			cout << ans << '\n';
		}
	}
	return 0;
}
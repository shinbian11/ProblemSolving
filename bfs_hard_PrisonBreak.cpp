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


int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };

//x행 y열에서 배열 v를 통해 움직였을 때 문을 여는 최소 횟수가 담긴 배열을 구하는 함수
vector< vector<int> > bfs(vector<string>& v, int x, int y)
{
	int n = v.size();
	int m = v[0].size();

	vector< vector<int> > dist(n, vector<int>(m));


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dist[i][j] = -1;
		}
	}
	deque<pi> q; 

	q.push_back(make_pair(x, y));
	dist[x][y] = 0;

	while (!q.empty())
	{
		tie(x, y) = q.front();
		q.pop_front();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dir[k][0];
			int ny = y + dir[k][1];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{

				//그 다음으로 이동할 후보들 중에서,
				if (dist[nx][ny] != -1) continue; //한번 방문한 놈이면 안돼!
				if (v[nx][ny] == '*') continue; //벽이면 안돼!

				if (v[nx][ny] == '#') //문이면 횟수+1 만 하고 가면 돼!
				{
					dist[nx][ny] = dist[x][y] + 1;
					q.push_back(make_pair(nx, ny));
				}
				else
				{
					dist[nx][ny] = dist[x][y];
					q.push_front(make_pair(nx, ny));
				}
			}
		}
	}

	return dist; //횟수가 담겨있는 배열을 리턴

}

int main()
{
	F_I;
	/*
	9376번 탈옥 : 각각의 도둑에 대해서 일일히 bfs를 취하고, 감옥 밖에 있는 목적지에도 사람이 있다고 가정을 하고
	각각의 bfs를 취해서 더한 값들의 최소값이 답이다!
	*/
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m;
		cin >> n >> m;

		vector<string> v(n + 2);

		string padding = "";
		for (int i = 0; i < m + 2; i++)
			padding += ".";

		for (int i = 1; i <= n; i++)
		{
			cin >> v[i];
			v[i] = "." + v[i] + ".";
		}


		v[0] += padding;
		v[n + 1] += padding;

		n += 2;
		m += 2;

		vector< vector<int> > d1 = bfs(v, 0, 0); //감옥밖의 사람(목적지)이 꼭 0행 0열이 아니어도 된다!


		int x1 = -1, y1 = -1;
		int x2 = -1, y2 = -1;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (v[i][j] == '$') //도둑을 찾고
				{
					if (x1 == -1 && y1 == -1) //찾은 도둑이 첫번째 도둑이라면
					{
						x1 = i;
						y1 = j;
					}
					else //찾은 도둑이 두번째 도둑이라면
					{
						x2 = i;
						y2 = j;
					}
				}

			}
		}

		vector< vector<int> > d2 = bfs(v, x1, y1);
		vector< vector<int> > d3 = bfs(v, x2, y2);

		int ans = 1e9;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{

				if (d1[i][j] == -1) continue; //*이 있는 공간이라는 뜻 (벽인 부분은 제외)

				int sum = (d1[i][j] + d2[i][j] + d3[i][j]);
				if (v[i][j] == '#') sum -= 2;

				if (ans > sum)
					ans = sum;
			}
		}
		cout << ans << '\n';

	}

	return 0;
}
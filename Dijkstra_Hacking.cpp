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

int INF = 987654321;
vector<pi> v[10004];
int d[10004];
bool visited[10004];

int main()
{
	F_I;

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m, start;
		cin >> n >> m >> start;

		memset(v, 0, sizeof(v));
		fill(d, d + sizeof(d) / sizeof(int), INF);
		fill(visited, visited + sizeof(visited) / sizeof(bool), false);

		for (int i = 0; i < m; i++)
		{
			int a, b, cost;
			cin >> a >> b >> cost;
			v[b].push_back({ a,cost });
		}

		priority_queue< pi, vector<pi>, greater<pi> > q;
		d[start] = 0;

		q.push({ 0,start });
		while (!q.empty())
		{
			auto t = q.top();
			q.pop();
			int x = t.second;
			if (visited[x])
				continue;
			visited[x] = true;

			for (auto k : v[x])
			{
				int y = k.first;
				int cost = k.second;
				if (d[y] > d[x] + cost)
				{
					d[y] = d[x] + cost;
					q.push({ d[y],y });
				}
			}
		}

		//일반적인 다익스트라 구현 한 다음, 
		//한 줄에 걸쳐 총 감염되는 컴퓨터 수 : INF 가 아닌 컴퓨터의 수
		//마지막 컴퓨터가 감염되기까지 걸리는 시간 : INF 가 아닌 d[i] 중에서의 최댓값

		int cnt = 0;
		int mx = -1;

		for (int i = 1; i <= n; i++)
		{
			if (d[i] == INF) continue;
			cnt += 1;
			if (mx < d[i])
				mx = d[i];
		}

		cout << cnt << ' ' << mx << '\n';
	}
	return 0;
}
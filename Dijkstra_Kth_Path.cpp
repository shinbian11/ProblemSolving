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

vector<pi> v[1004];
priority_queue<int> d[1004];
//bool visited[1004];

int main()
{
	F_I;

	//[백준] 1854번 : K번째 최단경로 찾기 (다익스트라 응용)

	//한 정점에서 다른 정점으로 가는 1번째 최단거리를 찾는 알고리즘 >> 다익스트라
	//한 정점에서 다른 정점으로 가는 k번째 최단거리를 찾는 알고리즘 >> 다익스트라의 응용!
	//원래의 다익스트라에서, dist[i]는 시작점에서 i정점까지의 1번째 최단거리의 정보들만 담았지만,
	//dist[i]를 큐와 같은 자료구조(여기서는 우선순위 큐) 로 두면, 시작점에서 i정점까지의 1~k번째 최단거리의 정보들을 순차적으로 관리할 수 있다는 아이디어!

	//dist[i]의 사이즈가 k보다 아직 작으면, 아직 시작점에서 i정점까지의 k번째 최단거리의 정보가 담기지 않은 것이므로, dist[i]에 정보를 담아주고,
	//dist[i]의 사이즈가 k와 같으면, dist[i]의 맨 top 정보(현재까지의 k번째 최단거리의 정보) 와 비교하여 최소값을 k번째 최단거리의 정보로 하는 식으로 구현!

	//이해가 안되면 백준 pdf 파일 참고! 직접 그림 그려가며 비교하기!

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost });
	}

	int start = 1;
	//int end = n;
	
	d[start].push(0);

	priority_queue<pi, vector<pi>, greater<pi> > q;
	q.push({ 0,start }); //{cost, 정점}

	while (!q.empty())
	{
		auto t = q.top();
		q.pop();
		
		int cur_cost = t.first;
		int x = t.second;

		//방문했던 정점을 한번 이상 추가적으로 더 방문할 수도 있으므로 visited 배열은 여기서 사용하지 않는다.
		//if (visited[x]) continue;
		//visited[x] = true;

		for (auto t : v[x])
		{
			int y = t.first;
			int cost = t.second;

			//d[y]의 k번째 최단거리가 채워지지 않았거나,
			//d[y]의 사이즈가 k인데, k번째 최단거리와 비교했을 때 이번에 구한 거리가 더 최단거리인 경우에만! 
			// -> d[y]에 push 해준다.
			if (d[y].size() < k || d[y].top() > cur_cost + cost) 
			{
				if (d[y].size() == k)
				{
					d[y].pop();
				}

				d[y].push(cur_cost + cost);
				q.push({ cur_cost + cost, y });
			}
		}
	}


	for (int i = 1; i <= n; i++)
	{
		if (d[i].size() != k)
			cout << -1 << '\n';
		else
			cout << d[i].top() << '\n';
	}

	return 0;
}
#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수
struct Edge
{
	int to, cost;
};

vector<Edge> v[20004];
int dist[20004];
bool checked[20004];

int main()
{
	F_I;

	//[백준] 1753번 : 최단경로 (다익스트라, O(E* logE))
	//어떤 문제든 간에, 문제를 풀기 전에는 시간복잡도를 잘 따져야 한다.
	//이 문제는 V가 20000이라서, O(V^2) 방법으로 풀면 시간초과가 난다. 즉 O(E* log E)의 방법으로 해야 한다.
	
	//- 다익스트라 : 1. 정점을 선택 (방문하지 않은, 최소 dist의 정점) / 2. 선택된 정점과 인접한 정점들 간의 최소 비용 값 갱신
	// 이렇게 두 과정을 거치는데, 2번은 시간복잡도에서 줄일 수 있는 것이 없으므로, 1번 과정에서 시간복잡도를 줄이면 된다!
	
	// 우선순위 큐를 만들어서 가장 작은 정점이 바로 나올 수 있도록 한다는 아이디어를 이용한다! O(E* logE)

	int n, m;
	cin >> n >> m;
	int start;
	cin >> start;
	while (m--)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost });
	}

	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	dist[start] = 0;

	//우선순위 큐에 (dist, index) 형태로 push를 한다. 최소 dist를 가지는 정점을 '빠르게' 찾기 위해!! 
	//이미 방문한 정점인지의 판별 여부는 if(checked[x]) 에서 알 수 있다.

	priority_queue< pi,vector<pi>,greater<pi> > q;  //우선순위 큐의 기본값은 최대 힙인데, 여기서는 최소를 top으로 위치시켜야 한다.
	q.push({ 0,start }); 
	
	while (!q.empty())
	{
		auto t = q.top();
		q.pop();

		int x = t.second;
		if (checked[x]) //이미 방문한 정점이라면 넘기기!
			continue;

		checked[x] = true;

		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i].to;
			if (dist[y] > dist[x] + v[x][i].cost)
			{
				dist[y] = dist[x] + v[x][i].cost;
				q.push({ dist[y],y }); 
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == INF)
			cout << "INF";
		else
			cout << dist[i];
		cout << '\n';
	}

	return 0;
}
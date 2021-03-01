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

vector<pi> v[40004];
int depth[40004];
int dist[40004]; //dist[i] : 루트에서 i까지의 거리
int parent[40004];
bool visited[40004];
int p[40004][16];

int lca(int u, int v) //가장 가까운 공통 조상 찾는 알고리즘
{
	/*
	step 1: u,v 두 노드가 있을 때, 두 노드 중 더 깊게 있는 노드를 u 라고 고정시키고,
	step 2: u가 v와 같은 높이가 될때까지 끌어올린 후,
	step 3: u와 v가 같게 될때까지 동시에 끌어올린다.
	*/

	//step 1
	if (depth[u] < depth[v])
		swap(u, v);

	//step 2
	while (depth[u] != depth[v])
	{
		u = parent[u];
	}

	while (u != v)
	{
		u = parent[u];
		v = parent[v];
	}

	return u;
}

int main()
{
	F_I;

	//[백준] 1761번 : 정점들의 거리 (LCA)

	int n;
	cin >> n;

	//연결 관계 입력 받기
	for (int i = 0; i < n - 1; i++)
	{
		int s, e, cost;
		cin >> s >> e >> cost;
		v[s].push_back({ e,cost });
		v[e].push_back({ s,cost });
	}


	//1이 루트 노드이므로, 이를 시작으로 BFS 이용하여, 트리 만들기
	queue<int> q;
	q.push(1);
	depth[1] = 0;
	parent[1] = 0;
	visited[1] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto t : v[x])
		{
			int y, cost;
			tie(y, cost) = t;

			if (visited[y] == false)
			{
				visited[y] = true;

				depth[y] = depth[x] + 1; //y의 깊이는 x의 깊이 + 1 이다.
				parent[y] = x; //y의 부모는 x이다

				dist[y] = dist[x] + cost; //거리

				q.push(y);
			}
		}
	}

	int tc;
	cin >> tc;
	while (tc--)
	{
		int a, b;
		cin >> a >> b;

		//노드 a,b 가 있을 때, (a와 b 사이의 거리) = (루트에서 a 까지의 거리 + 루트에서 b 까지의 거리) - 2 * (루트에서 a,b의 LCA까지의 거리) 이다.
		cout << dist[a] + dist[b] - 2 * dist[lca(a, b)] << '\n';
	}

	return 0;
}
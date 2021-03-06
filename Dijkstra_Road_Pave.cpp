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

ll INF = 1000000LL * 50000LL; //최대 5만개의 간선이 모두 백만의 cost를 가질 수 있으므로 (최대의 경우)
vector<pi> v[10004];
ll d[10004][24];
bool visited[10004][24];

int main()
{
	F_I;

	//[백준] 1162번 : 도로포장 (다익스트라)

	//최단 거리를 구하는 문제이므로 다익스트라로 가능하고, u에서 v로 이동할 때, 도로를 포장하는 경우와 포장하지 않는 경우로 나누어서 처리해야 한다.
	//정점 정보 한개만으로는 도로 포장의 여부를 알 수 없으므로, 도로 포장의 개수인 step 이라는 변수를 항상 가지고 있어야 한다.
	//또한 d 배열의 값은 long long 범위로 넘어갈 수 있으므로 참고해야 한다! 

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;

		v[from].push_back({ to,cost });
		v[to].push_back({ from,cost });
	}

	int start = 1, end = n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
			d[i][j] = INF;
	}

	d[start][0] = 0;

	priority_queue< tuple<ll, int, int>, vector< tuple<ll, int, int> >, greater< tuple<ll, int, int> > > q;
	q.push({ d[start][0],start,0 }); //{cost, 정점, step}

	while (!q.empty())
	{
		auto t = q.top();
		q.pop();

		int x = get<1>(t);
		int step = get<2>(t);

		if (visited[x][step]) continue;
		visited[x][step] = true;

		for (auto t : v[x])
		{
			int y = t.first;
			int cost = t.second;

			if (step + 1 <= k && d[y][step + 1] > d[x][step]) //도로 포장을 하는 경우 (cost가 0이 된다.)
			{
				d[y][step + 1] = d[x][step];
				q.push({ d[y][step + 1],y,step + 1 });
			}
			if (d[y][step] > d[x][step] + cost) //도로 포장을 하지 않는 경우
			{
				d[y][step] = d[x][step] + cost;
				q.push({ d[y][step],y,step });
			}
		}
	}

	ll ans = INF; //long long 범위이다.
	for (int i = 0; i <= k; i++)
	{
		if (d[end][i] == INF) continue;
		if (ans > d[end][i])
			ans = d[end][i];
	}
	cout << ans << '\n';

	return 0;
}
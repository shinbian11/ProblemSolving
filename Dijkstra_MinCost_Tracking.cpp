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

vector<Edge> v[1004];
int dist[1004];
int from[1004];
bool visited[1004];

int main()
{
	F_I;

	//[백준] 11779번 : 최소비용 구하기 2 (다익스트라 + 경로 추적)
	//[백준] 1916번 : 최소비용 구하기 문제와 비슷하다! 경로 추적만 합쳐진 것이다.
	//경로 추적은, 최소 값으로 갱신이 될 때의 변화되는 경로의 움직임을 기록하면 되는 것이므로,
	//dist[to] > dist[mn_idx] + cost 되는 경우에 from 배열을 만들어서 넣어주면 된다!

	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost });
	}

	int start, end;
	cin >> start >> end;

	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	dist[start] = 0;
	from[start] = -1;

	for (int i = 0; i < n - 1; i++)
	{
		int mn = INF, mn_idx = -1;
		for (int j = 1; j <= n; j++)
		{
			if (!visited[j] && mn > dist[j])
			{
				mn = dist[j];
				mn_idx = j;
			}
		}

		visited[mn_idx] = true;

		for (auto t : v[mn_idx])
		{
			int to = t.to;
			int cost = t.cost;
			if (dist[to] > dist[mn_idx] + cost)
			{
				dist[to] = dist[mn_idx] + cost;
				from[to] = mn_idx;
			}
		}
	}

	cout << dist[end] << '\n';
	
	stack<int> st;
	int x = end;
	while (x != -1)
	{
		st.push(x);
		x = from[x];
	}
	cout << st.size() << '\n';

	while (!st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}
	return 0;
}
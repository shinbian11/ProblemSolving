#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

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

	//[����] 11779�� : �ּҺ�� ���ϱ� 2 (���ͽ�Ʈ�� + ��� ����)
	//[����] 1916�� : �ּҺ�� ���ϱ� ������ ����ϴ�! ��� ������ ������ ���̴�.
	//��� ������, �ּ� ������ ������ �� ���� ��ȭ�Ǵ� ����� �������� ����ϸ� �Ǵ� ���̹Ƿ�,
	//dist[to] > dist[mn_idx] + cost �Ǵ� ��쿡 from �迭�� ���� �־��ָ� �ȴ�!

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
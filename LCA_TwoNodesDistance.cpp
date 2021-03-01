#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

vector<pi> v[40004];
int depth[40004];
int dist[40004]; //dist[i] : ��Ʈ���� i������ �Ÿ�
int parent[40004];
bool visited[40004];
int p[40004][16];

int lca(int u, int v) //���� ����� ���� ���� ã�� �˰���
{
	/*
	step 1: u,v �� ��尡 ���� ��, �� ��� �� �� ��� �ִ� ��带 u ��� ������Ű��,
	step 2: u�� v�� ���� ���̰� �ɶ����� ����ø� ��,
	step 3: u�� v�� ���� �ɶ����� ���ÿ� ����ø���.
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

	//[����] 1761�� : �������� �Ÿ� (LCA)

	int n;
	cin >> n;

	//���� ���� �Է� �ޱ�
	for (int i = 0; i < n - 1; i++)
	{
		int s, e, cost;
		cin >> s >> e >> cost;
		v[s].push_back({ e,cost });
		v[e].push_back({ s,cost });
	}


	//1�� ��Ʈ ����̹Ƿ�, �̸� �������� BFS �̿��Ͽ�, Ʈ�� �����
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

				depth[y] = depth[x] + 1; //y�� ���̴� x�� ���� + 1 �̴�.
				parent[y] = x; //y�� �θ�� x�̴�

				dist[y] = dist[x] + cost; //�Ÿ�

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

		//��� a,b �� ���� ��, (a�� b ������ �Ÿ�) = (��Ʈ���� a ������ �Ÿ� + ��Ʈ���� b ������ �Ÿ�) - 2 * (��Ʈ���� a,b�� LCA������ �Ÿ�) �̴�.
		cout << dist[a] + dist[b] - 2 * dist[lca(a, b)] << '\n';
	}

	return 0;
}
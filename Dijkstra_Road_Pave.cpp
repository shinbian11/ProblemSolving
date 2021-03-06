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

ll INF = 1000000LL * 50000LL; //�ִ� 5������ ������ ��� �鸸�� cost�� ���� �� �����Ƿ� (�ִ��� ���)
vector<pi> v[10004];
ll d[10004][24];
bool visited[10004][24];

int main()
{
	F_I;

	//[����] 1162�� : �������� (���ͽ�Ʈ��)

	//�ִ� �Ÿ��� ���ϴ� �����̹Ƿ� ���ͽ�Ʈ��� �����ϰ�, u���� v�� �̵��� ��, ���θ� �����ϴ� ���� �������� �ʴ� ���� ����� ó���ؾ� �Ѵ�.
	//���� ���� �Ѱ������δ� ���� ������ ���θ� �� �� �����Ƿ�, ���� ������ ������ step �̶�� ������ �׻� ������ �־�� �Ѵ�.
	//���� d �迭�� ���� long long ������ �Ѿ �� �����Ƿ� �����ؾ� �Ѵ�! 

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
	q.push({ d[start][0],start,0 }); //{cost, ����, step}

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

			if (step + 1 <= k && d[y][step + 1] > d[x][step]) //���� ������ �ϴ� ��� (cost�� 0�� �ȴ�.)
			{
				d[y][step + 1] = d[x][step];
				q.push({ d[y][step + 1],y,step + 1 });
			}
			if (d[y][step] > d[x][step] + cost) //���� ������ ���� �ʴ� ���
			{
				d[y][step] = d[x][step] + cost;
				q.push({ d[y][step],y,step });
			}
		}
	}

	ll ans = INF; //long long �����̴�.
	for (int i = 0; i <= k; i++)
	{
		if (d[end][i] == INF) continue;
		if (ans > d[end][i])
			ans = d[end][i];
	}
	cout << ans << '\n';

	return 0;
}
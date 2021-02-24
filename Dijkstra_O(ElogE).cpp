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

vector<Edge> v[20004];
int dist[20004];
bool checked[20004];

int main()
{
	F_I;

	//[����] 1753�� : �ִܰ�� (���ͽ�Ʈ��, O(E* logE))
	//� ������ ����, ������ Ǯ�� ������ �ð����⵵�� �� ������ �Ѵ�.
	//�� ������ V�� 20000�̶�, O(V^2) ������� Ǯ�� �ð��ʰ��� ����. �� O(E* log E)�� ������� �ؾ� �Ѵ�.
	
	//- ���ͽ�Ʈ�� : 1. ������ ���� (�湮���� ����, �ּ� dist�� ����) / 2. ���õ� ������ ������ ������ ���� �ּ� ��� �� ����
	// �̷��� �� ������ ��ġ�µ�, 2���� �ð����⵵���� ���� �� �ִ� ���� �����Ƿ�, 1�� �������� �ð����⵵�� ���̸� �ȴ�!
	
	// �켱���� ť�� ���� ���� ���� ������ �ٷ� ���� �� �ֵ��� �Ѵٴ� ���̵� �̿��Ѵ�! O(E* logE)

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

	//�켱���� ť�� (dist, index) ���·� push�� �Ѵ�. �ּ� dist�� ������ ������ '������' ã�� ����!! 
	//�̹� �湮�� ���������� �Ǻ� ���δ� if(checked[x]) ���� �� �� �ִ�.

	priority_queue< pi,vector<pi>,greater<pi> > q;  //�켱���� ť�� �⺻���� �ִ� ���ε�, ���⼭�� �ּҸ� top���� ��ġ���Ѿ� �Ѵ�.
	q.push({ 0,start }); 
	
	while (!q.empty())
	{
		auto t = q.top();
		q.pop();

		int x = t.second;
		if (checked[x]) //�̹� �湮�� �����̶�� �ѱ��!
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
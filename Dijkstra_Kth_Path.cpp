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

vector<pi> v[1004];
priority_queue<int> d[1004];
//bool visited[1004];

int main()
{
	F_I;

	//[����] 1854�� : K��° �ִܰ�� ã�� (���ͽ�Ʈ�� ����)

	//�� �������� �ٸ� �������� ���� 1��° �ִܰŸ��� ã�� �˰��� >> ���ͽ�Ʈ��
	//�� �������� �ٸ� �������� ���� k��° �ִܰŸ��� ã�� �˰��� >> ���ͽ�Ʈ���� ����!
	//������ ���ͽ�Ʈ�󿡼�, dist[i]�� ���������� i���������� 1��° �ִܰŸ��� �����鸸 �������,
	//dist[i]�� ť�� ���� �ڷᱸ��(���⼭�� �켱���� ť) �� �θ�, ���������� i���������� 1~k��° �ִܰŸ��� �������� ���������� ������ �� �ִٴ� ���̵��!

	//dist[i]�� ����� k���� ���� ������, ���� ���������� i���������� k��° �ִܰŸ��� ������ ����� ���� ���̹Ƿ�, dist[i]�� ������ ����ְ�,
	//dist[i]�� ����� k�� ������, dist[i]�� �� top ����(��������� k��° �ִܰŸ��� ����) �� ���Ͽ� �ּҰ��� k��° �ִܰŸ��� ������ �ϴ� ������ ����!

	//���ذ� �ȵǸ� ���� pdf ���� ����! ���� �׸� �׷����� ���ϱ�!

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
	q.push({ 0,start }); //{cost, ����}

	while (!q.empty())
	{
		auto t = q.top();
		q.pop();
		
		int cur_cost = t.first;
		int x = t.second;

		//�湮�ߴ� ������ �ѹ� �̻� �߰������� �� �湮�� ���� �����Ƿ� visited �迭�� ���⼭ ������� �ʴ´�.
		//if (visited[x]) continue;
		//visited[x] = true;

		for (auto t : v[x])
		{
			int y = t.first;
			int cost = t.second;

			//d[y]�� k��° �ִܰŸ��� ä������ �ʾҰų�,
			//d[y]�� ����� k�ε�, k��° �ִܰŸ��� ������ �� �̹��� ���� �Ÿ��� �� �ִܰŸ��� ��쿡��! 
			// -> d[y]�� push ���ش�.
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
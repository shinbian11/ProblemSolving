#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

ll n, m, b, e;
vector<pl> a[10001];
bool visit[10001];

//bfs�� �ذ�!

bool q_operation(ll node, ll limit_weight) 
{
	queue<ll> q;
	q.push(node);

	visit[node] = true;

	while (!q.empty())
	{
		ll x = q.front();

		if (x == e) //���ʿ� b���� e�� ���°� ��ǥ�ε�, �̹� node �� e��� ������ ���̹Ƿ� true ��ȯ
			return true;

		q.pop();
		for (auto& k : a[x])
		{
			ll next = k.first;
			ll weight = k.second;

			if ((visit[next] == 0) && (weight >= limit_weight))
			{
				visit[next] = true;
				q.push(next);
			}
		}
	}
	return false;

}
int main()
{
	F_I;

	//���� 1939�� �߷� ���� : �׷��� ���� + �׷��� Ž�� + ���� ���Ը� �����ϴ� �κ��� �̺� Ž������ ����!

	//ll n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) //���� ����Ʈ ����
	{
		ll t, v, cost;
		cin >> t >> v >> cost;
		a[t].push_back(make_pair(v, cost));
		a[v].push_back(make_pair(t, cost));
	}

	//ll b, e;
	cin >> b >> e;

	ll start = 1;
	ll end = 1e9;
	ll ans = 0;

	ll mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		memset(visit, false, sizeof(visit)); //bfs�� �ѹ� �ϰ� �� �� ���� , �湮����� ��ϵǾ� �ִ� �迭�� �ʱ�ȭ�ؾ� �Ѵ�.

		if (q_operation(b, mid))
		{
			ans = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1; //�ƴϸ� mid ���� ������.
		}
	}

	cout << ans << '\n';
	return 0;
}
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

//dfs�� �ذ�!
bool binary_search(int node, int weight_limit)
{
	if (visit[node]) // �̹� �湮�� ���� false ��ȯ (�ѹ� ��ģ ��带 �� ��ġ�� �� �Ұ���)
		return false;
	if (node == e) //���ʿ� b���� e�� ���°� ��ǥ�ε�, �̹� node �� e��� ������ ���̹Ƿ� true ��ȯ
		return true;

	visit[node] = true;

	for (auto k : a[node])
	{
		ll next = k.first; //a[node]�� ����� �ٸ� ���� ����
		ll cost = k.second; // �� ���̸� �����ϴ� �ٸ��� ���� ���� ����
		if (cost >= weight_limit) // �ٸ��� �ο��Ǿ��ִ� ���� ���� ���԰� �츮�� ���Ƿ� ������ ���Ժ��� ���ſ��, ��� ������ �ٸ���� ���̴�!
		{
			if (binary_search(next, weight_limit))
			{
				return true;
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
		memset(visit, false, sizeof(visit)); //dfs�� �ѹ� �ϰ� �� �� ����, �湮����� ��ϵǾ� �ִ� �迭�� �ʱ�ȭ�ؾ� �Ѵ�.

		if (binary_search(b, mid)) // ���ѹ��Ը� mid �� ������ ��, b���� e���� �� �� �ִٸ�, 
		{
			ans = mid;  //�ϴ� ���� mid�� �ϰ�,
			start = mid + 1; //mid ���� �÷�����
		}
		else
		{
			end = mid - 1; //�ƴϸ� mid ���� ������.
		}
	}

	cout << ans << '\n';
	return 0;
}
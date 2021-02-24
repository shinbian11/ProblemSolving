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


vector<pi> v[504];
int d[504];

void solve()
{
	int n, m, w;
	cin >> n >> m >> w;

	//vector<vector<pair<int, int>>> v(n + 1);
	//vector<int> d(n + 1, INF);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	for (int i = 0; i < w; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({ b,-c });
	}

	d[1] = 0;

	bool negative = false;

	for (int vertex = 1; vertex <= n; vertex++) // ��� ������ ���ؼ� ���� ����Ŭ�� �����ϴ��� Ȯ���ϱ� ���ؼ� vertex �� for������ ����
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				int x = i;
				int y = v[i][j].first;
				int cost = v[i][j].second;

				if (d[y] > d[x] + cost)
				{
					d[y] = d[x] + cost;

					if (vertex == n)
					{
						negative = true;
					}
				}
			}
		}
	}

	if (negative)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	return;
}

int main()
{
	F_I;

	//[����] 1865�� : ��Ȧ (��������)

	//���� ����Ŭ�� �����ϴ��� ����� ����

	int tc;
	cin >> tc;
	while (tc--)
	{
		//testcase �� ������ v�� d �ʱ�ȭ!
		for (int i = 0; i < 504; i++)
			v[i].clear();
		//fill(d, d + sizeof(d) / sizeof(int), INF);
		memset(d, INF, sizeof(d));

		solve();
	}

	return 0;
}
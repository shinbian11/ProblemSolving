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

	for (int vertex = 1; vertex <= n; vertex++) // 모든 정점에 대해서 음의 사이클이 존재하는지 확인하기 위해서 vertex 를 for문으로 돌림
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

	//[백준] 1865번 : 웜홀 (벨만포드)

	//음의 사이클이 존재하는지 물어보는 문제

	int tc;
	cin >> tc;
	while (tc--)
	{
		//testcase 할 때마다 v와 d 초기화!
		for (int i = 0; i < 504; i++)
			v[i].clear();
		//fill(d, d + sizeof(d) / sizeof(int), INF);
		memset(d, INF, sizeof(d));

		solve();
	}

	return 0;
}
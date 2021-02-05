#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int d[104];
int n, m, a, b;

int main()
{
	cin >> n >> a >> b >> m;

	// [백준] 2644번 : 촌수 계산 (bfs)
	// 주어진 두 사람의 간선의 개수가 곧 촌수라는 점을 이용한다.

	vector< vector<int> > arr(n+1, vector<int>(n + 1));
	
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	memset(d, -1, sizeof(d));

	queue<int> q;
	
	d[a] = 0;
	q.push(a);
	
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto t : arr[x])
		{
			if (d[t] == -1)
			{
				d[t] = d[x] + 1;
				q.push(t);
			}
		}
	}

	if (d[b] == -1)
		cout << -1 << '\n';
	else
		cout << d[b] << '\n';

	return 0;
}
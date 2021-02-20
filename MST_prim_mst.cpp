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

vector<pi> v[10004];
bool checked[10004];

struct cmp
{
	bool operator() (const pi& a, const pi& b)
	{
		return a.second > b.second;
	}
};

int main()
{
	F_I;
	
	//[백준] 1197번 : 최소 스패닝 트리 
	// 1. 프림으로 해결

	int vertex, edge;
	cin >> vertex >> edge;
	while (edge--)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	}

	priority_queue< pi, vector<pi>, cmp> q;

	checked[1] = true;

	for (auto k : v[1])
	{
		q.push(k);
	}

	int min_cost = 0;

	while (!q.empty())
	{
		pi x = q.top();
		q.pop();

		if (checked[x.first])
			continue;

		checked[x.first] = true;
		min_cost += x.second;

		int now = x.first;
		for (auto k : v[now])
			q.push(k);
	}

	cout << min_cost << '\n';

	return 0;
}
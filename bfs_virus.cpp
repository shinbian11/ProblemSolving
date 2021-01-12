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

bool visited[102];
vector<int> v[102];

int main()
{
	F_I;
	
	/*
	백준 2606번 : 바이러스 (BFS)
	*/

	int computer;
	int edge;
	cin >> computer >> edge;

	for (int i = 0; i < edge; i++)
	{
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}

	queue<int> q;
	q.push(1);
	visited[1] = true;
	int cnt = 0;

	while (!q.empty())
	{
		int x = q.front();
		visited[x] = true;
		q.pop();
		for (int i = 0; i < v[x].size(); i++)
		{
			if (!visited[v[x][i]])
			{
				visited[v[x][i]] = true;
				cnt += 1;
				q.push(v[x][i]);
			}
		}
	}

	cout << cnt << '\n';

	return 0;

}
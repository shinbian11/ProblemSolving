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

vector<int> v[504];
int depth[504];

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	
	depth[x] = 0;
	
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		for (int t : v[x])
		{
			if (depth[t] == -1)
			{
				depth[t] = depth[x] + 1;
				q.push(t);
			}
		}
	}
}
int main()
{
	F_I;

	//[백준] 5567번 : 결혼식 (bfs로 해결)
	//자신의 친구와 친구의 친구의 명수를 세는 문제  >> 친구(depth 1) , 친구의 친구 (depth 2)인 노드의 개수
	//문제에 나온대로 양방향 연결을 해야 한다. 단방향을 하면 틀린다.
	
	/*
	 - 단방향 연결만 했을 때의 반례
	5
	4
	1 2
	1 5
	2 5
	3 5
	- 이 방향으로 단방향 연결만 했다면 2라는 출력결과가 나온다. 하지만 정답은 3이다.
	*/

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	memset(depth, -1, sizeof(depth));

	bfs(1); //1을 기준으로 나머지 동기들의 depth 조사.
	
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (depth[i] == 1 || depth[i] == 2)
			cnt += 1;
	}
	cout << cnt << '\n';

	return 0;
}
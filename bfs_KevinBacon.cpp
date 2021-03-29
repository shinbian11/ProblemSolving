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

vector<int> v[104];
bool visited[104];
int depth[104];

void bfs(int x) //bfs 함수 : x를 depth가 0인 노드로 할 때, 다른 노드들의 깊이를 체크하는 용도로 사용한다.
{
	queue<int> q;
	q.push(x);
	visited[x] = true;
	depth[x] = 0;

	while (!q.empty())
	{
		int x = q.front(); q.pop();
		for (int t : v[x])
		{
			if (visited[t] == false)
			{
				visited[t] = true;
				q.push(t);
				depth[t] = depth[x] + 1;
			}
		}
	}
}

int main()
{
	F_I;
	
	//[백준] 1389번 : 케빈 베이컨의 6단계 법칙 (bfs로 풀이)

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int to, from;
		cin >> to >> from;
		v[to].push_back(from);
		v[from].push_back(to);
	}

	vector<pi> ans;
	int sum;
	for (int i = 1; i <= n; i++)
	{
		memset(visited, false, sizeof(visited));
		memset(depth, 0, sizeof(depth));

		bfs(i); 

		sum = 0;

		for (int j = 1; j <= n; j++)
		{
			sum += depth[j];
		}

		ans.push_back({ i, sum });
	}
	
	int X = -1;
	int tmp = 1000;
	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i].second < tmp)
		{
			tmp = ans[i].second;
			X = ans[i].first;
		}
	}

	cout << X << '\n';
	
	return 0;
}
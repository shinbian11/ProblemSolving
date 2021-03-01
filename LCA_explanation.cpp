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

int depth[50004];
int parent[50004];
bool visited[50004];
vector<int> v[50004];

int lca(int x, int y)
{
	/*
	step 1: u,v 두 노드가 있을 때, 두 노드 중 더 깊게 있는 노드를 u 라고 고정시키고,
	step 2: u가 v와 같은 높이가 될때까지 끌어올린 후,
	step 3: u와 v가 같게 될때까지 동시에 끌어올린다.
	*/
	if (depth[x] < depth[y]) //step 1
		swap(x, y);

	while (depth[x] != depth[y]) //step 2
	{
		x = parent[x];
	}

	while (x != y) //step 3
	{
		x = parent[x];
		y = parent[y];
	}

	return x;
}

int main()
{
	/*

	[백준] 11437번 : LCA ( 가장 가까운 공통 조상 찾기 (LCA : Lowest Common Ancestor) 개념 설명)

	- 여러 노드들의 가장 가까운 공통 조상(부모) 찾는 알고리즘

	- 가장 깊게 있는 노드가 루트 노드의 높이까지 올라오는 경우에, 
	(최악의 경우) 가장 깊게 있는 노드가 올라오는데 노드의 개수만큼(O(n))의 시간이 들 수 있기 때문에,
	이는 시간복잡도 O(n) 의 방법이다.

	*/
	F_I;

	int n;
	cin >> n;

	n -= 1;

	//간선 입력 (연결 관계 입력받기)
	while (n--)
	{
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}

	//1이 루트
	queue<int> q;
	q.push(1);
	depth[1] = 0;
	visited[1] = true;

	//bfs를 통해서 각 노드의 부모와 depth 계산
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int y : v[x])
		{
			if (visited[y] == false)
			{
				visited[y] = true;
				depth[y] = depth[x] + 1;
				parent[y] = x;
				q.push(y);
			}
		}
	}

	int tc;
	cin >> tc;
	while (tc--)
	{
		int s, e;
		cin >> s >> e;
		//s와 e의 LCA 찾기!
		cout << lca(s, e) << '\n';
	}

	return 0;
}
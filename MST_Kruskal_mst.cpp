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

int root[10004];

struct Edge
{
	int from, to, cost;
	bool operator < (const Edge& other) const
	{
		return cost < other.cost; //가중치 기준으로 오름차순
	}
};

int Find(int x)
{
	if (x == root[x])
		return x;
	else
		return root[x] = Find(root[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x != y)
		root[x] = y;

	return;
}

int main()
{
	F_I;
	
	//[백준] 1197번 : 최소 스패닝 트리 (by Kruskal)
	//2. 크루스칼 로 해결

	/*
	크루스칼(Kruskal) : 간선의 가중치를 기준으로 오름차순 정렬한 다음, 작은 가중치부터 차례대로 사이클을 생성하지 않고 추가해나가는 MST 알고리즘
	- 사이클 생성을 방지하기 위해, Union-Find 알고리즘을 이용한다.
	*/

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) //Union-Find 이용하기 위해 처음 초기화 작업!
		root[i] = i;


	vector<Edge> v(m);

	for(int i=0;i<m;i++)
	{
		cin >> v[i].from >> v[i].to >> v[i].cost;
	}

	sort(v.begin(), v.end()); //가중치 기준으로 정렬!

	int min_cost = 0;

	//가중치 기준으로 오름차순 정렬되었으므로, 다시 말해 i가 0부터 순서대로 탐색되면 가중치가 작은 간선부터 차례대로 탐색하는 꼴이 된다는 의미이다!
	for (int i = 0; i < m; i++) 
	{
		Edge a = v[i];
		
		int x = Find(a.from); 
		int y = Find(a.to);
		
		//같은 부모가 아니면 (간선을 추가해도 사이클이 생기지 않으면)
		if (x != y)
		{
			Union(a.from, a.to); //간선을 추가하고,
			min_cost += a.cost; //가중치를 더한다.
		}
	}
	
	cout << min_cost << '\n';

	return 0;
}
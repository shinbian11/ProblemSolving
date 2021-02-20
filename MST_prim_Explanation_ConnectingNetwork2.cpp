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

vector<pi> v[1004];
bool visited[1004];

struct cmp
{
	bool operator() (const pi& a, const pi& b)
	{
		return a.second > b.second; //cost에 의해 오름차순
	}
};

int main()
{
	F_I;
	
	/*
	* 프림 알고리즘!!
	
	MST(최소 신장 트리) 중에서 PRIM 알고리즘에 대해서! 
	1. 맨 처음 아무 정점을 잡고, 
	2. 선택한 정점(u)과 선택하지 않은 정점(v)들을 잇는 간선들 중 최소 가중치의 간선을 택한다.
	3. 선택한 간선을 MST에 추가하고, v를 선택한다. 이제 이 v가 선택한 정점이 된다.
	4. 모든 간선을 선택할 때까지 2~3번 과정을 반복한다.
	*/

	//[백준] 1922번 : 네트워크 연결 (MST - prim) - 2번째 방법

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back(make_pair(to, cost)); 
		v[to].push_back(make_pair(from, cost));
	}
	
	visited[1] = true;

	priority_queue< pi, vector<pi>, cmp> q; //cmp함수 따로 정의해주는 틀 알고있기!
	
	for (auto k : v[1])
	{
		q.push(k);
	}

	int cost_sum = 0;

	while (!q.empty())
	{
		pi x = q.top();
		q.pop();

		if (visited[x.first])
			continue;

		visited[x.first] = true;
		cost_sum += x.second;

		int now = x.first;
		for (auto k : v[now])
			q.push(k);
	}

	cout << cost_sum << '\n';
	
	return 0;
}
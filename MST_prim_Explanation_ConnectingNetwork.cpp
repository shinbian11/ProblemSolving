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

struct Edge
{
	//int from
	int to;
	int cost;

	//구조체 내에서의 연산자 오버로딩 (구조 알고 있으면 좋다!)
	bool operator < (const Edge& other) const {
		return cost > other.cost; 
		//우선순위 큐는 기본적으로 최대 힙이라 내림차순 정렬인데, 여기서는 cost에 의해 오름차순 되기를 원하므로, 부등호 방향을 바꿔준다!
	}

};

vector<Edge> v[1004];
bool checked[1004];

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

	//[백준] 1922번 : 네트워크 연결 (MST - prim)
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost }); //구조체 형식을 vector에 push_back 할 때의 구조! 알고있기! Edge({to,cost}) 형식으로 push_back 해도 된다!
		v[to].push_back({from,cost }); //양방향 그래프니까!	
	}
	
	checked[1] = true; //1번 정점에서 시작하기!
	
	priority_queue<Edge> q;

	for (auto t : v[1]) //{1과 연결된 정점들, cost} 을 push 한다. 이 정보들은 가중치 오름차순을 기준으로 차례차례 우선순위 큐에 저장된다.
	{
		q.push(t);
	}

	int cost_sum = 0; // 최소 가중치

	while (!q.empty())
	{	
		Edge e = q.top(); //가장 가중치가 작은 Edge 부터 꺼낸다. 우선순위 큐는 front()가 아니라 top()으로 최상단 원소를 참조한다.
		q.pop();
		
		//그 전 정점과 연결된 점들 중 이미 방문한 점이 있다면 skip한다. 선택된 점과 선택되지 않은 점을 잇고 있는 간선들 중 최소 가중치 간선을 택해야 하므로!
		if (checked[e.to]) 
			continue;

		checked[e.to] = true; //그 정점도 방문처리 해주고,
		cost_sum += e.cost; //가중치를 더해주고,

		int now = e.to;
		for (auto t : v[now]) // 그 정점에서 또 연결된 간선들을 모두 push 해준다. 이 과정을 반복한다!
			q.push(t);
	}

	cout << cost_sum << '\n';

	return 0;
}
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
struct Edge
{
	int to, cost;
};
vector<Edge> v[1004];
int dist[1004];
bool checked[1004];

int main()
{
	F_I;

	//[백준] 1916번 : 최소비용 구하기 (+ 다익스트라 (O(V^2) 개념 설명)

	/*
	벨만 포드와 다익스트라는 둘 다 최단 거리를 구하는 알고리즘이다. 하지만 벨만포드는 음수의 가중치가 있을 때에도 사용 가능하고, 다익스트라는 그렇지 않다.
	이 문제는 다익스트라 문제로 풀 수 있다. 이 문제에서의 다익스트라는 시간복잡도가 O(V^2)이다. 이를 O(E *logE) 까지도 줄일 수 있다.
	
	<다익스트라 개념 순서 설명>
	1 - 시작점을 잡고, 시작점에서부터 '인접'한 정점들 사이의 최소 비용을 계산하고 갱신한다.
	2 - '방문하지 않은' 노드들 중에서 '비용이 가장 작은 노드'를 선택한다.
	3 - 해당 노드를 거쳐 특정한 노드로 가는 경우를 고려하여 최소 비용을 갱신한다.
	4 - 2,3번 과정을 반복한다.
 	*/

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from>> to >> cost;
		v[from].push_back(Edge{ to,cost });
	}

	int start, end;
	cin >> start >> end;
	
	for (int i = 1; i <= n; i++) //무한대로 모두 초기화
		dist[i] = INF;
	
	dist[start] = 0; //시작점은 비용이 0이다.

	for (int iterate = 0; iterate < n-1; iterate++) //최단 거리 찾는데에 n번 반복 할 필요 없이 n-1번 반복해도 된다.
	{
		int mn = INF, mn_idx = -1;

		//정점 선택 기준 : dist가 최소이며, 방문되지 않은 정점!
		for (int j = 1; j <= n; j++)
		{
			if (!checked[j] && mn > dist[j]) 
			{
				mn = dist[j];
				mn_idx = j;
			}
		}

		checked[mn_idx] = true; //선택된 정점을 true로!

		//선택된 정점 주변의 인접한 정점들 간의 dist값 갱신해주기
		for (auto t : v[mn_idx])
		{
			int to = t.to;
			int cost = t.cost;

			if (dist[to]> dist[mn_idx] + cost)
			{
				dist[to] = dist[mn_idx] + cost;
			}
		}
	}

	cout << dist[end] << '\n';

	return 0;
}
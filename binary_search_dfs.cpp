#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

ll n, m, b, e;
vector<pl> a[10001];
bool visit[10001];

//dfs로 해결!
bool binary_search(int node, int weight_limit)
{
	if (visit[node]) // 이미 방문한 노드면 false 반환 (한번 거친 노드를 또 거치는 건 불가능)
		return false;
	if (node == e) //애초에 b에서 e로 가는게 목표인데, 이번 node 가 e라면 도착한 것이므로 true 반환
		return true;

	visit[node] = true;

	for (auto k : a[node])
	{
		ll next = k.first; //a[node]와 연결된 다른 인접 노드들
		ll cost = k.second; // 그 사이를 연결하는 다리의 실제 제한 무게
		if (cost >= weight_limit) // 다리에 부여되어있는 실제 제한 무게가 우리가 임의로 설정한 무게보다 무거우면, 통과 가능한 다리라는 뜻이다!
		{
			if (binary_search(next, weight_limit))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	F_I;

	//백준 1939번 중량 제한 : 그래프 문제 + 그래프 탐색 + 제한 무게를 설정하는 부분을 이분 탐색으로 구현!

	//ll n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) //인접 리스트 구현
	{
		ll t, v, cost;
		cin >> t >> v >> cost;
		a[t].push_back(make_pair(v, cost));
		a[v].push_back(make_pair(t, cost));
	}
	//ll b, e;
	cin >> b >> e;

	ll start = 1;
	ll end = 1e9;
	ll ans = 0;

	ll mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		memset(visit, false, sizeof(visit)); //dfs를 한번 하고 올 때 마다, 방문기록이 기록되어 있는 배열은 초기화해야 한다.

		if (binary_search(b, mid)) // 제한무게를 mid 로 정했을 때, b에서 e까지 갈 수 있다면, 
		{
			ans = mid;  //일단 답을 mid로 하고,
			start = mid + 1; //mid 값을 올려본다
		}
		else
		{
			end = mid - 1; //아니면 mid 값을 내린다.
		}
	}

	cout << ans << '\n';
	return 0;
}
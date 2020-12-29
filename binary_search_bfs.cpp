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

//bfs로 해결!

bool q_operation(ll node, ll limit_weight) 
{
	queue<ll> q;
	q.push(node);

	visit[node] = true;

	while (!q.empty())
	{
		ll x = q.front();

		if (x == e) //애초에 b에서 e로 가는게 목표인데, 이번 node 가 e라면 도착한 것이므로 true 반환
			return true;

		q.pop();
		for (auto& k : a[x])
		{
			ll next = k.first;
			ll weight = k.second;

			if ((visit[next] == 0) && (weight >= limit_weight))
			{
				visit[next] = true;
				q.push(next);
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
		memset(visit, false, sizeof(visit)); //bfs를 한번 하고 올 때 마다 , 방문기록이 기록되어 있는 배열은 초기화해야 한다.

		if (q_operation(b, mid))
		{
			ans = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1; //아니면 mid 값을 내린다.
		}
	}

	cout << ans << '\n';
	return 0;
}
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

int n, m;
int d[1004];
int a[1004][1004];
bool visited[1004];
int INF = 100000000; // 주의점) INF를 987654321로 하면, ans1과 ans2를 구하는 과정에서, 경로가 없는 경우엔 INF를 3번 더하는 경우도 생기는데,
//987654321를 3번 더하면 오버플로우가 생기므로, 3번 더해도 오버플로우가 나지 않는 1억 정도의 수로 초기화해야 한다!

vector<int> dijkstra(int start)
{
	for (int i = 1; i <= n; i++)
	{
		d[i] = INF;
		visited[i] = false;
	}

	d[start] = 0;

	for (int k = 0; k < n - 1; k++) {

		int mn = INF + 1;
		int idx = -1;

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i] && mn > d[i])
			{
				mn = d[i];
				idx = i;
			}
		}

		visited[idx] = true;

		for (int i = 1; i <= n; i++)
		{
			if (d[i] > d[idx] + a[idx][i])
				d[i] = d[idx] + a[idx][i];
		}
	}

	return vector<int>(d, d + n + 1);

}

int main()
{
	F_I;

	//[백준] 1504번 : 특정한 최단 경로 (다익스트라)
	//정점의 개수가 작으므로, 다익스트라의 O(V^2)의 시간복잡도를 가지는 간단한 구현으로 해도 된다.

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			a[i][j] = INF;
	}

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;

		if (a[from][to] > cost)
			a[from][to] = cost;

		if (a[to][from] > cost)
			a[to][from] = cost;
	}

	int v1, v2;
	cin >> v1 >> v2;

	//방법 1 : 1->v1->v2->n
	//방법 2 : 1->v2->v1->n
	//즉, 1을 출발점으로, v1을 출발점으로, v2을 출발점으로 >> 다익스트라를 총 3번 해야한다!!

	vector<int> a1 = dijkstra(1); //a1[i] : 1에서 시작하여 i까지 가는 최단 거리
	vector<int> a2 = dijkstra(v1); //a2[i] : v1에서 시작하여 i까지 가는 최단 거리
	vector<int> a3 = dijkstra(v2); //a3[i] : v2에서 시작하여 i까지 가는 최단 거리


	int ans1 = a1[v1] + a2[v2] + a3[n];
	int ans2 = a1[v2] + a3[v1] + a2[n];

	int ans = min(ans1, ans2);

	if (ans >= INF)  //방법 1과 방법 2의 최소거리 조차도 INF 보다 크거나 같으면 경로가 없는것이다!
		ans = -1;

	cout << ans << '\n';

	return 0;
}
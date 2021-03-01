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

vector<int> v[100004];
int depth[100004];
int parent[100004];
bool visited[100004];
int p[100004][17];

int lca(int u, int v) //LCA 구현 부분이 시간복잡도 O(n) 짜리 LCA와 다르다.
{
	//u,v 두 노드 중 노드 u를 더 깊은 노드라고 고정하기!
	if (depth[u] < depth[v]) {
		swap(u, v);
	}
	//더 깊은 노드인 u의 높이를 찾아서, 그 u가 v와 같은 높이가 될 때까지 2^i 칸씩 위로 올린다. (i는 1씩 감소)
	int log = 1;
	for (log = 1; (1 << log) <= depth[u]; log++);

	log -= 1;
	for (int i = log; i >= 0; i--) {
		if (depth[u] - (1 << i) >= depth[v]) { //u가 v와 같은 높이가 될때까지
			u = p[u][i]; //2^i 칸씩 위로 올린다.
		}
	}

	//두 노드의 레벨이 같아졌다면, 두 노드가 "같아지기 직전까지" 두 노드 모두 2^i칸씩 위로 올린다.
	if (u == v) {
		return u;
	}
	else {
		for (int i = log; i >= 0; i--) {
			if (p[u][i] != 0 && p[u][i] != p[v][i]) { //p[u][i] == 0 인 경우 : u의 2^i 번째 부모가 없는 경우 (트리를 벗어남)
				u = p[u][i];
				v = p[v][i];
			}
		}

		//같아지기 직전에 for문을 탈출한 뒤, 한칸을 더 올린 값(parent[u])를 반환한다.
		return parent[u];
	}
}

int main()
{
	F_I;

	//[백준] 11438번 : LCA 2 (LCA)
	// 이 문제는 O(N) 시간복잡도를 가지는 LCA 알고리즘으로는 풀 수 없다. O(N)짜리 시간 제한이 총 M번 발생하므로, O(MN)인데, 시간제한에 걸리므로 안된다.
	//그러므로 O(log N) 이라는 시간복잡도를 가지고, 결론적으로 O( M * log N) 짜리 시간 복잡도를 가지는 LCA 방법으로 해결해야 한다.

	int n;
	cin >> n;

	//연결 관계 입력 받기
	for (int i = 0; i < n - 1; i++)
	{
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}


	//1이 루트 노드이므로, 이를 시작으로 BFS 이용하여, 트리 만들기
	queue<int> q;
	q.push(1);
	depth[1] = 0;
	parent[1] = 0;
	visited[1] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int y : v[x])
		{
			if (visited[y] == false)
			{
				visited[y] = true;
				depth[y] = depth[x] + 1; //깊이 1 증가
				parent[y] = x; //y의 부모는 x이다.
				q.push(y);
			}
		}
	}


	//dp로 처리하기!
	//p[i][j] : 노드 i 의 2^j 번째 조상
	for (int i = 1; i <= n; i++) {
		p[i][0] = parent[i]; //어떤 노드의 2^0 번째 조상 => 어떤 노드의 1번쨰 조상 => 어떤 노드의 부모!
	}
	for (int j = 1; (1 << j) < n; j++) {
		for (int i = 1; i <= n; i++) {
			if (p[i][j - 1] != 0) { //p[i][j - 1] == 0 인 경우 : i의 2^(j-1) 번째 부모가 없는 경우 (트리를 벗어남)

				//노드 i의 2^j번째 조상 => 노드 i의 2^(j-1)번째 조상의 2^(j-1)번째 조상
				p[i][j] = p[p[i][j - 1]][j - 1];
			}
		}
	}

	int tc;
	cin >> tc;
	while (tc--)
	{
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}

	return 0;
}
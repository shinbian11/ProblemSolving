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

int n, m, mx;
int node;

//vector<int> v[10004];
vector< vector<int> > v(10004);

bool visited[10004];
vector<int> save;

void dfs(int x)
{
	visited[x] = true;
	for (auto k : v[x])
	{
		if (visited[k] == false)
		{
			node += 1;
			dfs(k);
		}
	}
}

int main()
{
	F_I;

	//[백준] 1325번 : 효율적인 해킹 (DFS)

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		//a b >> a가 b의 자식이므로, v[a].push_back(b)는 포함시키지 않는다.
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		//각각 다른 dfs 작업을 수행할 때마다 visited와 node의 개수는 초기화 시켜줘야 한다.
		memset(visited, false, sizeof(visited));
		node = 0;


		dfs(i);

		if (mx < node) //1번 컴퓨터부터 n번 컴퓨터까지의 자식 컴퓨터들의 개수를 구한 뒤, 그 최대값을 mx 에 담는다.
			mx = node;

		save.push_back(node);
	}

	for (int i = 0; i < save.size(); i++)
	{
		if (mx == save[i])
			cout << i + 1 << ' '; //i가 1일 때, save의 인덱스로는 0번으로 저장이 되었기 때문에, 출력할 때는 1을 더해준다!
	}

	return 0;
}
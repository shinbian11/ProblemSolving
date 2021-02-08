#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

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

	//[����] 1325�� : ȿ������ ��ŷ (DFS)

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		//a b >> a�� b�� �ڽ��̹Ƿ�, v[a].push_back(b)�� ���Խ�Ű�� �ʴ´�.
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		//���� �ٸ� dfs �۾��� ������ ������ visited�� node�� ������ �ʱ�ȭ ������� �Ѵ�.
		memset(visited, false, sizeof(visited));
		node = 0;


		dfs(i);

		if (mx < node) //1�� ��ǻ�ͺ��� n�� ��ǻ�ͱ����� �ڽ� ��ǻ�͵��� ������ ���� ��, �� �ִ밪�� mx �� ��´�.
			mx = node;

		save.push_back(node);
	}

	for (int i = 0; i < save.size(); i++)
	{
		if (mx == save[i])
			cout << i + 1 << ' '; //i�� 1�� ��, save�� �ε����δ� 0������ ������ �Ǿ��� ������, ����� ���� 1�� �����ش�!
	}

	return 0;
}
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

int depth[50004];
int parent[50004];
bool visited[50004];
vector<int> v[50004];

int lca(int x, int y)
{
	/*
	step 1: u,v �� ��尡 ���� ��, �� ��� �� �� ��� �ִ� ��带 u ��� ������Ű��,
	step 2: u�� v�� ���� ���̰� �ɶ����� ����ø� ��,
	step 3: u�� v�� ���� �ɶ����� ���ÿ� ����ø���.
	*/
	if (depth[x] < depth[y]) //step 1
		swap(x, y);

	while (depth[x] != depth[y]) //step 2
	{
		x = parent[x];
	}

	while (x != y) //step 3
	{
		x = parent[x];
		y = parent[y];
	}

	return x;
}

int main()
{
	/*

	[����] 11437�� : LCA ( ���� ����� ���� ���� ã�� (LCA : Lowest Common Ancestor) ���� ����)

	- ���� ������ ���� ����� ���� ����(�θ�) ã�� �˰���

	- ���� ��� �ִ� ��尡 ��Ʈ ����� ���̱��� �ö���� ��쿡, 
	(�־��� ���) ���� ��� �ִ� ��尡 �ö���µ� ����� ������ŭ(O(n))�� �ð��� �� �� �ֱ� ������,
	�̴� �ð����⵵ O(n) �� ����̴�.

	*/
	F_I;

	int n;
	cin >> n;

	n -= 1;

	//���� �Է� (���� ���� �Է¹ޱ�)
	while (n--)
	{
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}

	//1�� ��Ʈ
	queue<int> q;
	q.push(1);
	depth[1] = 0;
	visited[1] = true;

	//bfs�� ���ؼ� �� ����� �θ�� depth ���
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int y : v[x])
		{
			if (visited[y] == false)
			{
				visited[y] = true;
				depth[y] = depth[x] + 1;
				parent[y] = x;
				q.push(y);
			}
		}
	}

	int tc;
	cin >> tc;
	while (tc--)
	{
		int s, e;
		cin >> s >> e;
		//s�� e�� LCA ã��!
		cout << lca(s, e) << '\n';
	}

	return 0;
}
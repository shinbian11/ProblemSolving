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

vector<int> v[504];
int depth[504];

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	
	depth[x] = 0;
	
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		for (int t : v[x])
		{
			if (depth[t] == -1)
			{
				depth[t] = depth[x] + 1;
				q.push(t);
			}
		}
	}
}
int main()
{
	F_I;

	//[����] 5567�� : ��ȥ�� (bfs�� �ذ�)
	//�ڽ��� ģ���� ģ���� ģ���� ����� ���� ����  >> ģ��(depth 1) , ģ���� ģ�� (depth 2)�� ����� ����
	//������ ���´�� ����� ������ �ؾ� �Ѵ�. �ܹ����� �ϸ� Ʋ����.
	
	/*
	 - �ܹ��� ���Ḹ ���� ���� �ݷ�
	5
	4
	1 2
	1 5
	2 5
	3 5
	- �� �������� �ܹ��� ���Ḹ �ߴٸ� 2��� ��°���� ���´�. ������ ������ 3�̴�.
	*/

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	memset(depth, -1, sizeof(depth));

	bfs(1); //1�� �������� ������ ������� depth ����.
	
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (depth[i] == 1 || depth[i] == 2)
			cnt += 1;
	}
	cout << cnt << '\n';

	return 0;
}
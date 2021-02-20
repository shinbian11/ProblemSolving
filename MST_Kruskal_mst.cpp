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

int root[10004];

struct Edge
{
	int from, to, cost;
	bool operator < (const Edge& other) const
	{
		return cost < other.cost; //����ġ �������� ��������
	}
};

int Find(int x)
{
	if (x == root[x])
		return x;
	else
		return root[x] = Find(root[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x != y)
		root[x] = y;

	return;
}

int main()
{
	F_I;
	
	//[����] 1197�� : �ּ� ���д� Ʈ�� (by Kruskal)
	//2. ũ�罺Į �� �ذ�

	/*
	ũ�罺Į(Kruskal) : ������ ����ġ�� �������� �������� ������ ����, ���� ����ġ���� ���ʴ�� ����Ŭ�� �������� �ʰ� �߰��س����� MST �˰���
	- ����Ŭ ������ �����ϱ� ����, Union-Find �˰����� �̿��Ѵ�.
	*/

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) //Union-Find �̿��ϱ� ���� ó�� �ʱ�ȭ �۾�!
		root[i] = i;


	vector<Edge> v(m);

	for(int i=0;i<m;i++)
	{
		cin >> v[i].from >> v[i].to >> v[i].cost;
	}

	sort(v.begin(), v.end()); //����ġ �������� ����!

	int min_cost = 0;

	//����ġ �������� �������� ���ĵǾ����Ƿ�, �ٽ� ���� i�� 0���� ������� Ž���Ǹ� ����ġ�� ���� �������� ���ʴ�� Ž���ϴ� ���� �ȴٴ� �ǹ��̴�!
	for (int i = 0; i < m; i++) 
	{
		Edge a = v[i];
		
		int x = Find(a.from); 
		int y = Find(a.to);
		
		//���� �θ� �ƴϸ� (������ �߰��ص� ����Ŭ�� ������ ������)
		if (x != y)
		{
			Union(a.from, a.to); //������ �߰��ϰ�,
			min_cost += a.cost; //����ġ�� ���Ѵ�.
		}
	}
	
	cout << min_cost << '\n';

	return 0;
}
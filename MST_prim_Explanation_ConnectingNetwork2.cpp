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

vector<pi> v[1004];
bool visited[1004];

struct cmp
{
	bool operator() (const pi& a, const pi& b)
	{
		return a.second > b.second; //cost�� ���� ��������
	}
};

int main()
{
	F_I;
	
	/*
	* ���� �˰���!!
	
	MST(�ּ� ���� Ʈ��) �߿��� PRIM �˰��� ���ؼ�! 
	1. �� ó�� �ƹ� ������ ���, 
	2. ������ ����(u)�� �������� ���� ����(v)���� �մ� ������ �� �ּ� ����ġ�� ������ ���Ѵ�.
	3. ������ ������ MST�� �߰��ϰ�, v�� �����Ѵ�. ���� �� v�� ������ ������ �ȴ�.
	4. ��� ������ ������ ������ 2~3�� ������ �ݺ��Ѵ�.
	*/

	//[����] 1922�� : ��Ʈ��ũ ���� (MST - prim) - 2��° ���

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back(make_pair(to, cost)); 
		v[to].push_back(make_pair(from, cost));
	}
	
	visited[1] = true;

	priority_queue< pi, vector<pi>, cmp> q; //cmp�Լ� ���� �������ִ� Ʋ �˰��ֱ�!
	
	for (auto k : v[1])
	{
		q.push(k);
	}

	int cost_sum = 0;

	while (!q.empty())
	{
		pi x = q.top();
		q.pop();

		if (visited[x.first])
			continue;

		visited[x.first] = true;
		cost_sum += x.second;

		int now = x.first;
		for (auto k : v[now])
			q.push(k);
	}

	cout << cost_sum << '\n';
	
	return 0;
}
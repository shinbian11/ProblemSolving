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

struct Edge
{
	//int from
	int to;
	int cost;

	//����ü �������� ������ �����ε� (���� �˰� ������ ����!)
	bool operator < (const Edge& other) const {
		return cost > other.cost; 
		//�켱���� ť�� �⺻������ �ִ� ���̶� �������� �����ε�, ���⼭�� cost�� ���� �������� �Ǳ⸦ ���ϹǷ�, �ε�ȣ ������ �ٲ��ش�!
	}

};

vector<Edge> v[1004];
bool checked[1004];

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

	//[����] 1922�� : ��Ʈ��ũ ���� (MST - prim)
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost }); //����ü ������ vector�� push_back �� ���� ����! �˰��ֱ�! Edge({to,cost}) �������� push_back �ص� �ȴ�!
		v[to].push_back({from,cost }); //����� �׷����ϱ�!	
	}
	
	checked[1] = true; //1�� �������� �����ϱ�!
	
	priority_queue<Edge> q;

	for (auto t : v[1]) //{1�� ����� ������, cost} �� push �Ѵ�. �� �������� ����ġ ���������� �������� �������� �켱���� ť�� ����ȴ�.
	{
		q.push(t);
	}

	int cost_sum = 0; // �ּ� ����ġ

	while (!q.empty())
	{	
		Edge e = q.top(); //���� ����ġ�� ���� Edge ���� ������. �켱���� ť�� front()�� �ƴ϶� top()���� �ֻ�� ���Ҹ� �����Ѵ�.
		q.pop();
		
		//�� �� ������ ����� ���� �� �̹� �湮�� ���� �ִٸ� skip�Ѵ�. ���õ� ���� ���õ��� ���� ���� �հ� �ִ� ������ �� �ּ� ����ġ ������ ���ؾ� �ϹǷ�!
		if (checked[e.to]) 
			continue;

		checked[e.to] = true; //�� ������ �湮ó�� ���ְ�,
		cost_sum += e.cost; //����ġ�� �����ְ�,

		int now = e.to;
		for (auto t : v[now]) // �� �������� �� ����� �������� ��� push ���ش�. �� ������ �ݺ��Ѵ�!
			q.push(t);
	}

	cout << cost_sum << '\n';

	return 0;
}
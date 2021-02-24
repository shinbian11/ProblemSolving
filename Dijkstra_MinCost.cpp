#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 987654321

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
	int to, cost;
};
vector<Edge> v[1004];
int dist[1004];
bool checked[1004];

int main()
{
	F_I;

	//[����] 1916�� : �ּҺ�� ���ϱ� (+ ���ͽ�Ʈ�� (O(V^2) ���� ����)

	/*
	���� ����� ���ͽ�Ʈ��� �� �� �ִ� �Ÿ��� ���ϴ� �˰����̴�. ������ ��������� ������ ����ġ�� ���� ������ ��� �����ϰ�, ���ͽ�Ʈ��� �׷��� �ʴ�.
	�� ������ ���ͽ�Ʈ�� ������ Ǯ �� �ִ�. �� ���������� ���ͽ�Ʈ��� �ð����⵵�� O(V^2)�̴�. �̸� O(E *logE) ������ ���� �� �ִ�.
	
	<���ͽ�Ʈ�� ���� ���� ����>
	1 - �������� ���, �������������� '����'�� ������ ������ �ּ� ����� ����ϰ� �����Ѵ�.
	2 - '�湮���� ����' ���� �߿��� '����� ���� ���� ���'�� �����Ѵ�.
	3 - �ش� ��带 ���� Ư���� ���� ���� ��츦 ����Ͽ� �ּ� ����� �����Ѵ�.
	4 - 2,3�� ������ �ݺ��Ѵ�.
 	*/

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from>> to >> cost;
		v[from].push_back(Edge{ to,cost });
	}

	int start, end;
	cin >> start >> end;
	
	for (int i = 1; i <= n; i++) //���Ѵ�� ��� �ʱ�ȭ
		dist[i] = INF;
	
	dist[start] = 0; //�������� ����� 0�̴�.

	for (int iterate = 0; iterate < n-1; iterate++) //�ִ� �Ÿ� ã�µ��� n�� �ݺ� �� �ʿ� ���� n-1�� �ݺ��ص� �ȴ�.
	{
		int mn = INF, mn_idx = -1;

		//���� ���� ���� : dist�� �ּ��̸�, �湮���� ���� ����!
		for (int j = 1; j <= n; j++)
		{
			if (!checked[j] && mn > dist[j]) 
			{
				mn = dist[j];
				mn_idx = j;
			}
		}

		checked[mn_idx] = true; //���õ� ������ true��!

		//���õ� ���� �ֺ��� ������ ������ ���� dist�� �������ֱ�
		for (auto t : v[mn_idx])
		{
			int to = t.to;
			int cost = t.cost;

			if (dist[to]> dist[mn_idx] + cost)
			{
				dist[to] = dist[mn_idx] + cost;
			}
		}
	}

	cout << dist[end] << '\n';

	return 0;
}
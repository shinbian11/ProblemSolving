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

int n, m;
int d[1004];
int a[1004][1004];
bool visited[1004];
int INF = 100000000; // ������) INF�� 987654321�� �ϸ�, ans1�� ans2�� ���ϴ� ��������, ��ΰ� ���� ��쿣 INF�� 3�� ���ϴ� ��쵵 ����µ�,
//987654321�� 3�� ���ϸ� �����÷ο찡 ����Ƿ�, 3�� ���ص� �����÷ο찡 ���� �ʴ� 1�� ������ ���� �ʱ�ȭ�ؾ� �Ѵ�!

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

	//[����] 1504�� : Ư���� �ִ� ��� (���ͽ�Ʈ��)
	//������ ������ �����Ƿ�, ���ͽ�Ʈ���� O(V^2)�� �ð����⵵�� ������ ������ �������� �ص� �ȴ�.

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

	//��� 1 : 1->v1->v2->n
	//��� 2 : 1->v2->v1->n
	//��, 1�� ���������, v1�� ���������, v2�� ��������� >> ���ͽ�Ʈ�� �� 3�� �ؾ��Ѵ�!!

	vector<int> a1 = dijkstra(1); //a1[i] : 1���� �����Ͽ� i���� ���� �ִ� �Ÿ�
	vector<int> a2 = dijkstra(v1); //a2[i] : v1���� �����Ͽ� i���� ���� �ִ� �Ÿ�
	vector<int> a3 = dijkstra(v2); //a3[i] : v2���� �����Ͽ� i���� ���� �ִ� �Ÿ�


	int ans1 = a1[v1] + a2[v2] + a3[n];
	int ans2 = a1[v2] + a3[v1] + a2[n];

	int ans = min(ans1, ans2);

	if (ans >= INF)  //��� 1�� ��� 2�� �ּҰŸ� ������ INF ���� ũ�ų� ������ ��ΰ� ���°��̴�!
		ans = -1;

	cout << ans << '\n';

	return 0;
}
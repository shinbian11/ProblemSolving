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

vector<int> v[100004];
int depth[100004];
int parent[100004];
bool visited[100004];
int p[100004][17];

int lca(int u, int v) //LCA ���� �κ��� �ð����⵵ O(n) ¥�� LCA�� �ٸ���.
{
	//u,v �� ��� �� ��� u�� �� ���� ����� �����ϱ�!
	if (depth[u] < depth[v]) {
		swap(u, v);
	}
	//�� ���� ����� u�� ���̸� ã�Ƽ�, �� u�� v�� ���� ���̰� �� ������ 2^i ĭ�� ���� �ø���. (i�� 1�� ����)
	int log = 1;
	for (log = 1; (1 << log) <= depth[u]; log++);

	log -= 1;
	for (int i = log; i >= 0; i--) {
		if (depth[u] - (1 << i) >= depth[v]) { //u�� v�� ���� ���̰� �ɶ�����
			u = p[u][i]; //2^i ĭ�� ���� �ø���.
		}
	}

	//�� ����� ������ �������ٸ�, �� ��尡 "�������� ��������" �� ��� ��� 2^iĭ�� ���� �ø���.
	if (u == v) {
		return u;
	}
	else {
		for (int i = log; i >= 0; i--) {
			if (p[u][i] != 0 && p[u][i] != p[v][i]) { //p[u][i] == 0 �� ��� : u�� 2^i ��° �θ� ���� ��� (Ʈ���� ���)
				u = p[u][i];
				v = p[v][i];
			}
		}

		//�������� ������ for���� Ż���� ��, ��ĭ�� �� �ø� ��(parent[u])�� ��ȯ�Ѵ�.
		return parent[u];
	}
}

int main()
{
	F_I;

	//[����] 11438�� : LCA 2 (LCA)
	// �� ������ O(N) �ð����⵵�� ������ LCA �˰������δ� Ǯ �� ����. O(N)¥�� �ð� ������ �� M�� �߻��ϹǷ�, O(MN)�ε�, �ð����ѿ� �ɸ��Ƿ� �ȵȴ�.
	//�׷��Ƿ� O(log N) �̶�� �ð����⵵�� ������, ��������� O( M * log N) ¥�� �ð� ���⵵�� ������ LCA ������� �ذ��ؾ� �Ѵ�.

	int n;
	cin >> n;

	//���� ���� �Է� �ޱ�
	for (int i = 0; i < n - 1; i++)
	{
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}


	//1�� ��Ʈ ����̹Ƿ�, �̸� �������� BFS �̿��Ͽ�, Ʈ�� �����
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
				depth[y] = depth[x] + 1; //���� 1 ����
				parent[y] = x; //y�� �θ�� x�̴�.
				q.push(y);
			}
		}
	}


	//dp�� ó���ϱ�!
	//p[i][j] : ��� i �� 2^j ��° ����
	for (int i = 1; i <= n; i++) {
		p[i][0] = parent[i]; //� ����� 2^0 ��° ���� => � ����� 1���� ���� => � ����� �θ�!
	}
	for (int j = 1; (1 << j) < n; j++) {
		for (int i = 1; i <= n; i++) {
			if (p[i][j - 1] != 0) { //p[i][j - 1] == 0 �� ��� : i�� 2^(j-1) ��° �θ� ���� ��� (Ʈ���� ���)

				//��� i�� 2^j��° ���� => ��� i�� 2^(j-1)��° ������ 2^(j-1)��° ����
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
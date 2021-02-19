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

vector<int> v[10004];

int work[10004];
int ind[10004];
int d[10004]; //d[i] : i�� ���� ��ġ�� ���� ���� �ð�

int main()
{
	F_I;
	//[����] 2056�� : �۾� (���� ����)

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> work[i]; //work[i] : i��° �۾��� �ɸ��� �ð�
		d[i] = work[i]; //�ϴ� �����س���, ���߿� �񱳸� ���ؼ� ���� ������ �� ������ �����Ѵ�.
		int cnt;
		cin >> cnt;
		while (cnt--)
		{
			int e;
			cin >> e;
			v[i].push_back(e);
			ind[e] += 1;
		}
	}

	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (ind[i] == 0) //�Է� ������ 0�� ��츸 ť�� �ִ´�.
			q.push(i);
	}

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (auto t : v[x])
		{
			ind[t] -= 1;

			/*
			x->t�� ���� ��Ȳ����, d[x] + work[t] �� �ִ븦 d[t]�� ����!

			e.g.)
			i		 1 2 3
			work[i]	 2 4 3 �̰�,

			1->3, 2->3 �϶�,

			d[3] = max(d[1]+work[3] , d[2] + work[3]) = max(5,7) = 7 �̴�.
			�� ���� ���� d[1] + work[3]�� �ϸ� �Ǵ°� �ƴϳĴ� ������ ���� ���� ������,
			��¥�� 1->3 �� �����ϴ� �� �ƴ϶�, 2->3�� ������ �ؾ��ϴ� ���� bfs�� �̿��� �������� �̹Ƿ�,
			3���� �� �� �ִ� ��� ȭ��ǥ�� ���ؼ� ������ �غ��� �Ѵ�.

			- �� �κ� �����ϰ�� �Ϲ����� bfs�� �̿��� �������İ� �ڵ尡 ���� ����!
			*/

			if (d[t] < d[x] + work[t]) //������ �� ������ ���� �ϱ�!
				d[t] = d[x] + work[t];

			if (ind[t] == 0)
				q.push(t);
		}
	}

	int ans = -1;

	for (int i = 1; i <= n; i++)
	{
		if (ans == -1 || ans < d[i])
			ans = d[i];
	}

	cout << ans << '\n';

	return 0;
}
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

int button[1000001];
int visited[1000001];

int main()
{
	F_I;
	
	 /*
	 ���� 5014�� : ��ŸƮ��ũ (bfs)
	 */

	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	queue<int> q;
	q.push(s);
	visited[s] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		//���������Ͱ� u��ŭ �ö󰡴� ���
		if (now + u <= f && visited[now + u] == 0)
		{
			button[now + u] = button[now] + 1;
			visited[now + u] = 1;
			q.push(now + u);
		}

		//���������Ͱ� d��ŭ �������� ���
		if (now - d >= 1 && visited[now - d] == 0)
		{
			button[now - d] = button[now] + 1;
			visited[now - d] = 1;
			q.push(now - d);
		}
	}

	if (visited[g]) //visited[g]�� true��� ���� g���� �湮�ߴٴ� �ǹ��̴�.
		cout << button[g] << '\n';
	else
		cout << "use the stairs" << '\n';

	return 0;
}
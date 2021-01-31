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

int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { 1,-1,2,-2,2,-2,1,-1 };

void solve()
{
	int n;
	cin >> n;
	vector< vector<int> > arr(n, vector<int>(n,-1));

	int a,b;
	cin >> a >> b;
	arr[a][b] = 0;

	queue<pi> q;
	q.push(make_pair(a, b));

	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if (arr[nx][ny] == -1)
				{
					arr[nx][ny] = arr[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	int a1, b1;
	cin >> a1 >> b1;

	cout << arr[a1][b1] << '\n';

	return;
}

int main()
{
	F_I;

	//[����] 7562�� : ����Ʈ�� �̵� (bfs)

	int tc;
	cin >> tc;
	while (tc--)
		solve();
	return 0;
}
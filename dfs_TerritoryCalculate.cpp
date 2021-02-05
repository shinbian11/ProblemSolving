#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int m, n, k;
int cnt;
int arr[104][104];
bool visited[104][104];

void dfs(int x, int y)
{
	visited[x][y] = true;
	cnt += 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < m && ny >= 0 && ny < n)
		{
			if (arr[nx][ny] != 1 && visited[nx][ny] == false)
			{
				dfs(nx, ny);
			}
		}
	}
}

int main()
{
	//[백준] 2583번 : 영역 구하기 (dfs)

	vector<int> group;

	//int m, n, k;
	cin >> m >> n >> k;
	
	for (int i = 0; i < k; i++)
	{
		int sx, sy, dx, dy;
		cin >> sx >> sy >> dx >> dy;

		for (int i = sx; i < dx; i++)
		{
			for (int j = sy; j < dy; j++)
			{
				arr[j][i] = 1;
			}
		}
	}

	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] != 1 && visited[i][j] == false)
			{
				cnt = 0;
				dfs(i, j);
				group.push_back(cnt);
			}
		}
	}

	cout << group.size() << '\n';

	sort(group.begin(), group.end());

	for (int i = 0; i < group.size(); i++)
		cout << group[i] << ' ';

	return 0;
}
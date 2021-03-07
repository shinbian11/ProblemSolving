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

int arr[504][504];
int d[504][504];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m;

int move(int x, int y)
{
	if (x == n - 1 && y == m - 1) return 1; //도착지에 도착하면 시작->도착으로 가는 경우가 + 1 된 것이므로 1 리턴한다.

	if (d[x][y] != -1) return d[x][y]; //memoization

	int ans = 0;

	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
		{
			if (arr[x][y] > arr[nx][ny])
			{
				ans += move(nx, ny); //(nx,ny)에서 (n-1,m-1)로 가는 방법의 개수를 더해준다.
			}
		}
	}

	return d[x][y] = ans;
}

int main()
{
	F_I;

	//[백준] 1520번 : 내리막 길 (dp, Top-down)
	//1937번 : 욕심쟁이 판다와 상당히 흡사한 문제이다! 욕심쟁이 판다 문제 먼저 풀어보고 돌아오기!

	cin >> n >> m;

	memset(d, -1, sizeof(d));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	cout << move(0, 0) << '\n'; //(0,0)에서 시작

	return 0;
}
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

int main()
{
	F_I;

	//11048번 : 이동하기 (dp)

	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			d[i][j] = max({ d[i - 1][j],d[i][j - 1],d[i - 1][j - 1] }) + arr[i][j];
			//d[i][j] = max({ d[i - 1][j],d[i][j - 1] }) + arr[i][j];
			//문제에서 사탕의 개수는 항상 0이거나 양수이기 때문에, 
			//대각선 방향으로 한번에 움직였을 때보다, 오른쪽->하단 or 하단->오른쪽으로 가는 경우가 반드시 더 큰 값이나 같은 값을 가지게 될 수 밖에 없다.
			//그러므로 d[i-1][j-1]은 빼도 된다.
		}
	}

	cout << d[n][m] << '\n';

	return 0;
}
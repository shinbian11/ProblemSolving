#include <bits/stdc++.h>
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

	/*

	백준 11050번 : 이항 계수 1  (파스칼의 삼각형)

	- 이항계수 : n 개 중에서 k개를 중복 없이 고르는 경우의 수 (nCk) => n! / (k!* (n-k)!)  => O(n)의 시간복잡도 소요.

	- 근데 n이 커지면 n! 값은 오버플로우가 날 정도로 엄청 커진다..
	 즉 , 시간은 좀 더 걸리지만, 팩토리얼을 이용하지 않는 방법을 강구해야 한다.

	- 파스칼의 삼각형을 이용하면, O(n^2)의 시간이 걸리긴 하지만, 오버플로우 없이 원하는 값을 구할 수 있다.
	참고 : https://m.blog.naver.com/PostView.nhn?blogId=whtrb_study&logNo=220771365785&proxyReferer=https:%2F%2Fwww.google.co.kr%2F
	*/

	int n, k;
	cin >> n >> k;

	vector< vector<int> > pascal(n + 1, vector<int>(n + 1));

	for (int i = 0; i <= n; i++)
	{
		pascal[i][0] = 1;
		pascal[i][i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			pascal[i + 1][j + 1] = pascal[i][j + 1] + pascal[i][j];
		}
	}

	cout << pascal[n][k] << '\n';

	return 0;
}
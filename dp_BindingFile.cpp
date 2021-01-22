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

int arr[504];
int d[504][504];

int file(int i, int j)
{
	if (i == j)
		return 0;

	if (d[i][j] != -1)
		return d[i][j];

	int sum = 0;
	int& ans = d[i][j]; //최대값 1e9로 하면 d값이 갱신이 안된다.

	for (int k = i; k <= j; k++)
		sum += arr[k];

	for (int k = i; k < j; k++)
	{
		int tmp = file(i, k) + file(k + 1, j) + sum;
		if (ans == -1 || ans > tmp)
			ans = tmp;
	}
	return ans;
}

int main()
{
	F_I;

	/*
	[백준] 11066번 : 파일 합치기 (dp, top-down)
	
	*/
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		int n;
		cin >> n;

		memset(arr, 0, sizeof(arr));
		memset(d, -1, sizeof(d));

		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		cout << file(1, n) << '\n';

	}

	return 0;
}
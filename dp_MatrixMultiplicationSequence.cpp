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


int arr[504][2];
int d[504][504];
int n;

int go(int i, int j)
{
	//d[i][j] : i번째 행렬부터 j번째 행렬까지 모두 곱셈을 할 때의 필요한 곱셈의 최소 연산 횟수

	if (d[i][j] != -1) //memoization
		return d[i][j];

	if (i == j)//n == 1
		return 0;

	if (i + 1 == j)//n == 2
		return d[i][j] = arr[i][0] * arr[i][1] * arr[j][1];

	int ans = -1;
	
	for (int k = i; k < j; k++) // n >= 3
	{
		int tmp = go(i, k) + go(k + 1, j) + (arr[i][0] * arr[k][1] * arr[j][1]);
		if (ans == -1 || ans > tmp)
			ans = tmp;
	}


	return d[i][j] = ans;

}

int main()
{
	F_I;
	/*
	[백준] 11049번 : 행렬 곱셈 순서 (dp, Top-down)
	- 11066번 파일합치기 문제와 매우 흡사한 문제이다. 
	*/

	//int n;
	cin >> n;

	memset(d, -1, sizeof(d));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 2; j++)
			cin >> arr[i][j];
	}

	cout << go(1, n);

	return 0;
}
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


//연산자 오버로딩! *을 정수의 곱셈이 아니라 행렬의 곱셈으로!
vector<vector<int>> operator *(const vector<vector<int>>& a, const vector<vector<int>>& b) 
{
	int n = a[0].size();
	vector<vector<int>> ans(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				ans[i][j] += (a[i][k] * b[k][j]);
				ans[i][j] %= 1000;
			}
		}
	}

	return ans;
}

int main()
{
	F_I;

	/* 
	백준 10830번 : 행렬 제곱 (수학 + 거듭제곱의 연산자 오버로딩)
	*/
	int n;
	ll m;
	cin >> n >> m;

	vector<vector<int>> arr(n, vector<int>(n));
	vector<vector<int>> matrix_init(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) //단위행렬
	{
		matrix_init[i][i] = 1;
	}

	//정수의 거듭제곱과 구조가 같다. 다만, 여기서는 행렬의 거듭제곱이므로 '연산자 오버로딩'을 이용하여, * 의 역할을 조금 변경해주어야 한다.
	while (true) 
	{
		if (m == 0)
			break;
		if (m % 2 != 0)
		{
			//정수의 거듭제곱에서는 matrix_init 자리에 1이 들어간다. 행렬의 거듭제곱에서의 단위행렬은 정수의 1과 같은 역할을 한다.
			matrix_init = matrix_init * arr; 
		}
		arr = arr * arr;
		m /= 2;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix_init[i][j] << ' ';

		cout << '\n';
	}

	return 0;
}
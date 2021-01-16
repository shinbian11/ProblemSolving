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

ll wave[1500005];
int mod = 1000000007;

vector< vector<ll> > operator *(const vector<vector<ll>>& a, const vector<vector<ll>>& b) //연산자 오버로딩 (정수의 곱셈기호 -> 행렬의 곱셈기호)
{
	int n = a.size();
	vector<vector<ll>> ret(n, vector<ll>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				ret[i][j] += (a[i][k] * b[k][j]) % mod;
				ret[i][j] %= mod;
			}
		}
	}

	return ret;
}

int main()
{
	F_I;
	
	/*
	
	백준 11444번 : 피보나치 수 6 (피보나치 수를 행렬 거듭제곱으로!)

	- n번째 피보나치 수를 구하는데, n은 10^18까지이다. 어마어마하게 크다.
	 일반적인 방법으로는 불가능하다.

	- 행렬을 이용해서 풀 수 있다.
	 
	e.g.) n번째 피보나치를 f(n)이라 표현할 때,

	-----------------------------------------------

	f(n)		
	f(n-1)  
	> 이 행렬은,

	1 1       
	1 0			
	> 이 행렬과
	
	f(n-1)
	f(n-2)
	> 이 행렬의 곱으로 나타낼 수 있다.
	-----------------------------------------------(연쇄적으로)

	또한,
	f(n-1)
	f(n-2)
	> 이 행렬은,

	1 1			
	1 0			
	> 이 행렬과 

	f(n-2)
	f(n-3)
	> 이 행렬의 곱으로 나타낼 수 있다.

	...

	-----------------------------------------------

	-연쇄적으로 쭉 하다보면, 이러한 결론이 나온다.
	
	f(n+1) f(n)
	f(n)  f(n-1) 

	> 이러한 2*2 행렬은, 

	1 1
	1 0

	> 이 행렬의 n번 거듭제곱과 같다.

	- 즉, f(n)은, 
	1 1
	1 0 

	모양의 2*2행렬을 n번 거듭제곱 한 다음, 0행 1열의 값이다.

	> 행렬의 거듭제곱의 시간복잡도는 O(n^3 * log b) 이고, 여기서는 O(2^3 * log 10^18) = O(8*18  * log 10) = O(log 10) 이다.


	- 참고 ) 10830번 : 행렬 제곱 (연산자 오버로딩)
	*/

	ll n;
	cin >> n;

	if (n <= 1)
	{
		cout << n << '\n';
		return 0;
	}

	vector< vector<ll> > matrix_init = { {1,0},{0,1} };
	vector< vector<ll> > ans = { {1,1},{1,0} };
	
	
	while (true)
	{
		if (n == 0)
			break;
		if (n % 2 != 0)
		{
			matrix_init = matrix_init * ans;
		}
		ans = ans * ans;
		n /= 2;
	}

	cout << matrix_init[0][1] << '\n';

	return 0;
}
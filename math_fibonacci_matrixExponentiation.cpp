#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

ll wave[1500005];
int mod = 1000000007;

vector< vector<ll> > operator *(const vector<vector<ll>>& a, const vector<vector<ll>>& b) //������ �����ε� (������ ������ȣ -> ����� ������ȣ)
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
	
	���� 11444�� : �Ǻ���ġ �� 6 (�Ǻ���ġ ���� ��� �ŵ���������!)

	- n��° �Ǻ���ġ ���� ���ϴµ�, n�� 10^18�����̴�. ���ϰ� ũ��.
	 �Ϲ����� ������δ� �Ұ����ϴ�.

	- ����� �̿��ؼ� Ǯ �� �ִ�.
	 
	e.g.) n��° �Ǻ���ġ�� f(n)�̶� ǥ���� ��,

	-----------------------------------------------

	f(n)		
	f(n-1)  
	> �� �����,

	1 1       
	1 0			
	> �� ��İ�
	
	f(n-1)
	f(n-2)
	> �� ����� ������ ��Ÿ�� �� �ִ�.
	-----------------------------------------------(����������)

	����,
	f(n-1)
	f(n-2)
	> �� �����,

	1 1			
	1 0			
	> �� ��İ� 

	f(n-2)
	f(n-3)
	> �� ����� ������ ��Ÿ�� �� �ִ�.

	...

	-----------------------------------------------

	-���������� �� �ϴٺ���, �̷��� ����� ���´�.
	
	f(n+1) f(n)
	f(n)  f(n-1) 

	> �̷��� 2*2 �����, 

	1 1
	1 0

	> �� ����� n�� �ŵ������� ����.

	- ��, f(n)��, 
	1 1
	1 0 

	����� 2*2����� n�� �ŵ����� �� ����, 0�� 1���� ���̴�.

	> ����� �ŵ������� �ð����⵵�� O(n^3 * log b) �̰�, ���⼭�� O(2^3 * log 10^18) = O(8*18  * log 10) = O(log 10) �̴�.


	- ���� ) 10830�� : ��� ���� (������ �����ε�)
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
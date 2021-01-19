#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

void solve()
{
	ll a, b, c;
	cin >> a >> b >> c;

	if (a >= c)
		cout << -1;
	else
	{
		cout << 1;
	}

	cout << ' ';

	if (a >= c)
		cout << b;
	else
	{
		if (a * b > c)
			cout << b;
		else
			cout << -1;
	}

	cout << '\n';
	
}

int main()
{

	F_I;

	//[코드포스] A. Donut Shops (Educational Codeforces Round 90 (Rated for Div. 2))
	//생각보다 어려워 보이지만, a,b,c의 값을 비교하기만 하면 되는 간단한 문제이다.

	ll tc;
	cin >> tc;
	while (tc--)
		solve();

	return 0;
}
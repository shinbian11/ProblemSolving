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

void solve()
{
	//codeforces : B. Different Divisors (Codeforces Round #696 (Div. 2))
	ll sum = 1LL;
	int d;
	cin >> d;

	int i, j;
	for (i = 1 + d;; i++)
	{
		bool flag = false;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			sum *= (ll)i;
			//cout << i << '\n';
			break;
		}
	}

	for (j = i + d;; j++)
	{
		bool flag2 = false;
		for (int k = 2; k < j; k++)
		{
			if (j % k == 0)
			{
				flag2 = true;
				break;
			}
		}
		if (!flag2)
		{
			sum *= (ll)j;
			break;
		}
	}
	cout << sum << '\n';
}

int main()
{

	F_I;
	int tc;
	cin >> tc;
	while (tc--)
		solve();
	return 0;
}
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

	/*
	- 백준 16968번 : 차량 번호판 1 (브루트 포스)
	idx=0일때와 아닐때로 나누고, 바로 앞의 인덱스와 같은 문자인지 아닌지로 또 나눠서 생각하면 된다.

	*/
	string s;
	cin >> s;
	int ans = 1;
	for (int i = 0; i < s.length(); i++)
	{
		if (i == 0)
		{
			if (s[i] == 'c')
				ans *= 26;
			else //s[i]=='d'
				ans *= 10;
		}
		else
		{
			if (s[i - 1] == s[i])
			{
				if (s[i] == 'c')
					ans *= 25;
				else
					ans *= 9;
			}
			else
			{
				if (s[i] == 'c')
					ans *= 26;
				else //s[i]=='d'
					ans *= 10;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
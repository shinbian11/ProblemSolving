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

ll tree[1000001];
ll n, m;

ll calc(ll mid)
{
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (tree[i] > mid)
			ans += (tree[i] - mid);
	}
	return ans;
}

int main() //백준 1654번 : 랜선 자르기 (이분 탐색), c++
{
	F_I;

	
	cin >> n >> m;

	ll mm = -1; //mm : 나무들의 최대길이

	for (int i = 0; i < n; i++)
	{
		cin >> tree[i];
		if (mm < tree[i])
			mm = tree[i];
	}

	ll x = -1;

	ll s = 0;
	ll e = mm;

	while (s <= e)
	{
		ll mid = (s + e) / 2;
		if (calc(mid)>=m)
		{
			if (x < mid)
				x = mid;
			s = mid + 1;
		}
		else
		{
			e = mid - 1;
		}
	}
	cout << x << '\n';
	return 0;

}
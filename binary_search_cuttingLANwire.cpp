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


ll k, n;
ll ran[10001];
ll calc(ll mid)
{
	ll ans = 0;
	for (int i = 0; i < k; i++)
	{
		ans += (ran[i] / mid);
	}
	return ans;
}
int main() //백준 1654번 : 랜선 자르기 (이분 탐색), c++

{
	F_I;

	
	ll m = -1; //m : 랜선들 중에서 가장 긴 길이.
	cin >> k >> n;
	for (ll i = 0; i < k; i++)
	{
		cin >> ran[i];
		if (m < ran[i])
			m = ran[i];
	}
	ll start = 1;
	ll end = m;
	ll mid;
	ll x = -1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		ll cnt = calc(mid);
		if (cnt >= n)
		{
			/* 임의의 길이로 랜선을 잘랐을 때, 
			
			1) 그 개수가 원하는 개수(n) 보다 많이 나올수도 있고, 
			2) 같을 수도 있고, 
			3) 적게 나올 수도 있는데,

			3)같이 적게 나오는 경우는, 밑의 else 문으로 처리를 하면 되는것이고, 1),2)번 경우에는 이 if문에 들어가는 경우인데,
			1), 2)번에 속하는 경우 중에서, 임의의 길이의 최대값을 구하는 문제(이 부분만 주의)이므로, 최대값을 구하는 처리를 따로 해주어야 한다.

			*/
			if (mid > x)    
				x = mid;
				
			start = mid + 1;
		}
		else if (cnt < n)
		{
			end = mid - 1;
		}
		
	}

	cout << x << '\n'; //최대값 출력

	return 0;

}
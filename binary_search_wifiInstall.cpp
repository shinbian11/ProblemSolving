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


ll n, c;
vector<ll> wifi;

ll calc(ll mid)
{
	ll ans = 0;
	ll cnt = 1;
	ll last = wifi[0];
	for (ll i = 0; i < n; i++)
	{
		if (wifi[i] - last >= mid)
		{
			cnt += 1;
			last = wifi[i];
		}
	}
	return cnt;
}

int main()  //백준 2110번 : 공유기 설치 (이분/이진 탐색)
{
	F_I;

	cin >> n >> c;
	ll l;
	for (ll i = 0; i < n; i++)
	{
		cin >> l;
		wifi.push_back(l);
	}

	sort(wifi.begin(), wifi.end());

	ll s = 1;
	ll e = wifi[n - 1] - wifi[0]; //그냥 wifi[n-1] 도 됨!
	ll idx = -1;
	/*
	* 공유기를 일일히 집에 설치하며 그때그때의 거리의 최솟값을 구하는 방식은 너무 복잡하므로, 생각을 전환하여,
	* 가장 인접한 두 공유기 사이의 거리를 정해놓은 상태로, 그 상황에서 놓을 수 있는 공유기의 개수를 체크하는 식으로 생각!
	* mid는 가장 인접한 두 공유기 사이의 거리 값이다.
	* 생각만 조금 다르게 하면, 기존의 랜선 자르기, 나무 자르기와 같은 이분/이진 탐색의 문제와 거의 같은 문제이다.
	*/
	while (s <= e)
	{
		ll mid = (s + e) / 2;
		if (calc(mid) >= c)
		{
			if (idx < mid)
				idx = mid;

			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	cout << idx << '\n';

	return 0;
}
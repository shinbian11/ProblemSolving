#include <bits/stdc++.h>

#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); // F_I 사용 시 주의) scanf 와 cin 혼합 사용 금지
#define INF 987654321

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

	// [백준] 2792번 : 보석 상자 (이분 탐색)
	
	/*
	* 이렇게 풀었습니다)
	
	보석이 a개, b개, c개, ... 있을 때,
	한 사람 당 x 개씩 나눠준다고 하면,
	a/x + b/x + c/x + ... 명이 필요하다! (물론 a % x 가 0 이 아니면, a/x 이 아니라 a/x + 1 가 더해져야 한다! 나머지를 처리하는 1명이 추가적으로 필요함)
	이 `a/x + b/x + c/x + ...` 를 `x개씩 나눴을 때 필요한 총 사람의 수` 라고 하자.

	이 a/x + b/x + c/x + ... 이 n 보다 크면 안되니까, 만약 n 보다 크다면, `x개씩 나눴을 때 필요한 총 사람의 수` 를 줄이기 위해 x 값을 올려야 한다.
	(한 사람당 나눠줘야 하는 사탕의 수가 크면, 더 적은 사람들만으로도 충분하니까)

	이때 이 x의 값을 이분탐색으로 정하자!!
	*/

	ll n, m;
	ll mx = -1e18;
	cin >> n >> m;
	vector<ll> j(m);

	for (int i = 0; i < m; i++) {
		cin >> j[i];
		mx = max(mx, j[i]);
	}

	ll s = 1;
	ll e = mx;
	ll ans = 1e9;

	while (s <= e) {
		ll x = (s + e) / 2; // 한 사람당 나눠줄 사탕의 개수 : x개
		ll sum = 0;
		for (int i = 0; i < m; i++) {
			sum += j[i] / x;
			if (j[i] % x != 0)
				sum += 1;

			//if (sum > n) {
			//	break;
			//}
		}

		if (sum > n) {
			s = x + 1;
		}
		else {
			ans = min(ans, x);
			e = x - 1;
		}
	}

	cout << ans << '\n';

	return 0;

}
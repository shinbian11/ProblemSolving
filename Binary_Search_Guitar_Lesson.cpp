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
	// https://www.acmicpc.net/board/view/83220 참고
	// [백준] 2343번 - 기타 레슨 (이진 탐색)

	F_I;

	ll n, m;
	ll mx = -1e18;
	cin >> n >> m;
	vector<ll> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}

	ll s = mx;
	ll e = 1e18;

	while (s <= e) {

		ll mid = (s + e) / 2;
		ll cnt = 0;
		ll tmp = 0;

		for (int i = 0; i < n; i++) {
			if (tmp + v[i] > mid) {
				cnt += 1;
				tmp = 0;
			}
			tmp += v[i];
		}
		cnt += 1;

		if (cnt > m) {
			s = mid + 1;
		}
		else if (cnt < m) {
			e = mid - 1;
		}
		else { // cnt == m 
			e = mid - 1;
		}

		/*
		e = mid - 1의 역할은 조건을 만족하는 값의 범위를 점점 작게 만드는 것..
		cnt == M 일때, e = mid - 1; 을 하고, 답으로 s 를 취한다 => cnt == M 인 블루레이 중 최소 값을 찾음.

		역으로 cnt == M 인 블루레이 중 최대 값을 찾으려면
		s = mid + 1을 취하고 (조건을 만족하는 값의 범위를 점점 크게 만드는 것), 답으로 e 를 취한다.
		*/
	}

	cout << s << '\n';

	return 0;

}
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
	백준 16917번 : 양념 반 후라이드 반 (브루트 포스 + 계산)
	- 양념,후라이드 치킨이 각각 최대 10만 마리까지만 가능하므로 일일히 다 따져봐도 제한시간내에 답이 나올 수 있다는 사실을 알아야 한다.
	- 브루트 포스 이용!
	*/

	int a, b, c, x, y;
	ll ans = 1e18;
	cin >> a >> b >> c >> x >> y;
	for (int i = 0; i <= 100000; i++)
	{
		int A = Max(0, x - i) * a; //x보다 i가 커지는 경우는 존재하지 않는다. 즉 그럴 때에는 그냥 0으로 바꾸기.
		int B = Max(0, y - i) * b; ///y보다 i가 커지는 경우는 존재하지 않는다. 즉 그럴 때에는 그냥 0으로 바꾸기.
		int C = (2 * c * i);
		if (ans > (ll)A + B + C)
			ans = (ll)A + B + C;
	}
	cout << ans << '\n';
	return 0;
}
#include <bits/stdc++.h>
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
	1629번 : 곱셈 (수학 + 거듭제곱을 하는 방법)

	- a^b의 거듭제곱을 할 때,
	
	int ans = 1;
	for (int i = 0; i < b; i++)
		ans *= a;

	- 이 방법은 O(b)의 시간복잡도가 소요된다.
	
	- 이 방법보다 좀 더 효율적인 방법이 있다.

	- '이진수'를 이용하는 방법

	e.g.) 3^27를 할 때, 3^27 = 3^(16+8+2+1) = 3^16 + 3^8 + 3^2 + 3^1 이다.

	a		3	3^2  3^4  3^8  3^16	
	b		27   13   6    3    1 
	나머지   1    1	  0	   1    1

	b를 2로 나눴을 때, 나머지가 1이 나오면 그때의 a는 거듭제곱 작업을 하는데에 있어서 꼭 필요한 존재이다.
	- 이 방법을 이용하면 O(log(b)) 시간복잡도로 거듭제곱 작업을 해결 가능하다.

	*/
	ll a, b, c;
	ll ans = 1;
	cin >> a >> b >> c;

	while (true)
	{
		if (b == 0)
			break;
		if (b % 2 != 0)
		{
			ans *= a;
			ans %= c;
		}
		a *= a;
		a %= c;
		b /= 2;
	}

	cout << ans << '\n';
	return 0;
}
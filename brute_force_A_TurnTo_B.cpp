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

	//[백준] 16953번 : A -> B (브루트 포스)
	ll a, b;
	cin >> a >> b;
	int cnt = 0;
	
	//a로 b를 만들 수 있으면, b로도 a를 역으로 만들 수 있다.
	//만들 수 없거나, a>b가 되어버리는 경우 >> -1
	while (true)
	{
		if (a > b)
			break;
		if (a == b)
		{
			cout << cnt + 1 << '\n';
			return 0;
		}
		if (b % 2 == 0)
			b /= 2;
		else if (b % 10 == 1)
			b = (b - 1) / 10;
		else
			break;

		cnt += 1;
	}

	cout << -1 << '\n';

	return 0;
}
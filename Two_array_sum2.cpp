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

	//[백준] 7453번 : 합이 0인 네 정수
	//2143번 : 두 배열의 합과 거의 비슷한 문제이다.
	//O(n^4)로 풀면 시간초과가 나게 되므로, 변형해야 한다.
	//a,b 배열을 하나로 묶고, c,d 배열을 하나로 묶어서, 두 배열의 합과 같은 문제로 취급해서 풀기!
	//O(n^2* logn) 으로 가능하다.

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);
	vector<int> d(n);

	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	vector<int> x;
	vector<int> y;

	//x : a,b 배열로 만들 수 있는 모든 경우의 수를 저장
	//y : c,d 배열로 만들 수 있는 모든 경우의 수를 저장
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			x.push_back(a[i] + b[j]);
			y.push_back(c[i] + d[j]);
		}
	}

	//sort
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	//x를 탐색하면서, 0 - x[i] 값이 y 벡터에서 총 몇개가 있는지 구해서 더하기
	ll ans = 0;
	for (int a : x)
	{
		ans += upper_bound(y.begin(), y.end(), -a) - lower_bound(y.begin(), y.end(), -a);
	}

	cout << ans << '\n';

	return 0;
}
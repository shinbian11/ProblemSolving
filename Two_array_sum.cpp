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

	//[백준] 2143번 : 두 배열의 합 

	int t;
	cin >> t;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int m;
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}

	vector<int> ans1;
	vector<int> ans2;

	//a 배열의 부분 합 나열해서 저장
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += a[j];
			ans1.push_back(sum);
		}
	}

	//b 배열의 부분 합 나열해서 저장
	for (int i = 0; i < m; i++)
	{
		int sum = 0;
		for (int j = i; j < m; j++)
		{
			sum += b[j];
			ans2.push_back(sum);
		}
	}

	sort(ans1.begin(), ans1.end());
	sort(ans2.begin(), ans2.end());

	ll ans = 0;

	//t-ans[i] 값이 ans2에서 몇개가 있는지 찾아서 더해주기!
	for (int i = 0; i < ans1.size(); i++)
	{
		ans += upper_bound(ans2.begin(), ans2.end(), t - ans1[i]) - lower_bound(ans2.begin(), ans2.end(), t - ans1[i]);
	}

	cout << ans << '\n';

	return 0;
}
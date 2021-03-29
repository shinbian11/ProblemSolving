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

int arr[100004];
int d[100004];

int main()
{
	F_I;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		d[i] = arr[i];
	}
	
	int ans = -1e9;

	//i-1번째를 선택했는지 하지 않았는지를 고려!
	for (int i = 0; i < n; i++)
	{
		d[i] = max(arr[i], d[i - 1] + arr[i]);
		if (ans < d[i])
			ans = d[i];
	}
	
	cout << ans << '\n';

	return 0;
}

#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

ll calc(ll n) //1 ���� n ���� ���ڸ� �� ���� ���� ����
{
	ll ans = 0;
	bool flag = false;

	for (ll start = 1, len = 1;; start *= 10, len++)
	{
		ll end = start * 10 - 1;
		if (end > n)
		{
			flag = true;
			end = n;
		}
		ans += (ll)(end - start + 1) * (ll)len;
		if (flag)
			return ans;
	}
	return ans;
}

int main() //���� 1790�� : �� �̾� ���� 2 (�̺� Ž��), c++

{
	F_I;
	ll n, k;
	cin >> n >> k;
	if (calc(n) < k)
	{
		cout << -1 << '\n';
		return 0;
	}
	ll s = 1;
	ll e = n;
	ll ans = 0;

	while (s <= e)
	{
		ll mid = (s + e) / 2;
		if (calc(mid) < k)
		{
			ans = mid; //if ���� ������, 64~65���� �°� ���� ���Ѿ� �Ѵ�.
			s = mid + 1;
		}
		else
		{
			//ans = mid; //if ���� �־ ���� �ʳ�? ����!
			e = mid - 1;
		}
	}
	ll l = calc(ans + 1);
	string a = to_string(ans + 1);
	cout << a[a.length() - (l - k) - 1] << '\n';

	return 0;

}
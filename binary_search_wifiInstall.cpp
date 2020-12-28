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

int main()  //���� 2110�� : ������ ��ġ (�̺�/���� Ž��)
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
	ll e = wifi[n - 1] - wifi[0]; //�׳� wifi[n-1] �� ��!
	ll idx = -1;
	/*
	* �����⸦ ������ ���� ��ġ�ϸ� �׶��׶��� �Ÿ��� �ּڰ��� ���ϴ� ����� �ʹ� �����ϹǷ�, ������ ��ȯ�Ͽ�,
	* ���� ������ �� ������ ������ �Ÿ��� ���س��� ���·�, �� ��Ȳ���� ���� �� �ִ� �������� ������ üũ�ϴ� ������ ����!
	* mid�� ���� ������ �� ������ ������ �Ÿ� ���̴�.
	* ������ ���� �ٸ��� �ϸ�, ������ ���� �ڸ���, ���� �ڸ���� ���� �̺�/���� Ž���� ������ ���� ���� �����̴�.
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
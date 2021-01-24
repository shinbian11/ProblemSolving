#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����


int main()
{
	F_I;

	/*
	[����] 11058�� : ũ������ (dp, bottom-up)

	- ũ�������� 1���� ������ ���
	- ũ�������� 2,3,4���� �������� ������ ���

	�� 2������ �ൿ�� ���� �� �ִ�.

	d[n]�� n�� ��ư�� ������ �� ������ A�� �ִ� ������� �Ѵٸ�, 

	1���� �����ٰ� �������� : d[n]�� d[n-1] + 1 �̴�. 

	2,3,4���� �������� �����ٰ� ���� ����:

	ctrl-a, ctrl-c, ctrl-v �� ������ >> d[n] = d[n-3]+d[n-3] >> d[n-3]�� ������ ���� A�� ctrl-a,c,v �� �����ν� �ѹ� �� ��� �ϴϱ�..
	ctrl-a, ctrl-c, ctrl-v, ctrl-v �� ������ >> d[n] = d[n-4] + (d[n-4] * 2) >> d[n-4]�� ������ ���� A�� ctrl- a,c, �ϰ� v�� �� �� ������ �ι� �� ��� �ϴϱ�.
	....

	d[n] = d[n-(j+2)]*(j+1) �̴�. (�̶� 1<=j<=n-3)

	>> ��, d[i] = max( d[i-1] + 1, d[i-(j+2)]*(j+1) ) �̴�. (1<=j<=i-3)

	*/

	ll d[104];

	int n;
	cin >> n;

	memset(d, 0, sizeof(d));	

	d[0] = 0;
	d[1] = 1;
	d[2] = 2;
	d[3] = 3;

	for (int x = 4; x <= n; x++)
	{
		ll ans = -1e18;
		for (int y = 1; y <= x - 3; y++)
		{
			if (ans < d[x - (y + 2)] * (y + 1))
				ans = d[x - (y + 2)] * (ll)(y + 1);
		}
		if (ans < d[x - 1] + 1)
			d[x] = d[x - 1] + 1;
		else
			d[x] = ans;
	}

	cout << d[n] << '\n';

	return 0;
}
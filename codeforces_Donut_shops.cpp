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

void solve()
{
	ll a, b, c;
	cin >> a >> b >> c;

	if (a >= c)
		cout << -1;
	else
	{
		cout << 1;
	}

	cout << ' ';

	if (a >= c)
		cout << b;
	else
	{
		if (a * b > c)
			cout << b;
		else
			cout << -1;
	}

	cout << '\n';
	
}

int main()
{

	F_I;

	//[�ڵ�����] A. Donut Shops (Educational Codeforces Round 90 (Rated for Div. 2))
	//�������� ����� ��������, a,b,c�� ���� ���ϱ⸸ �ϸ� �Ǵ� ������ �����̴�.

	ll tc;
	cin >> tc;
	while (tc--)
		solve();

	return 0;
}
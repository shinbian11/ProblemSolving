#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

int mod = 1000000009;

ll d[1000004];

ll dp(int x)
{
	if (d[x] >= 0)
		return d[x] %= mod;

	if (x == 0)
		return d[x] = 1;
	else if (x == 1)
		return d[x] = 1;
	else if (x == 2)
		return d[x] = 2;
	else
	{
		d[x] = dp(x - 1) + dp(x - 2) + dp(x - 3);
		return d[x] %= mod;
	}

}
int main()
{
	F_I;
	/*
	���� 15988�� : 1, 2, 3 ���ϱ� 3 (dp)

	d[i] = 1,2,3�� ������ i�� ���� �� �ִ� ����� ��
	*/
	int n;
	cin >> n;
	int arr[3] = { 1,2,3 };
	memset(d, -1, sizeof(d));
	d[0] = 1;
	while (n--)
	{
		int m;
		cin >> m;

		cout << dp(m) << '\n';
	}
	return 0;
}
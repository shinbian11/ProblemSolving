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

int d[1500081];

int main()
{
	F_I;

	/*
	���� 15486�� ��� 2 (dp)
	*/

	int n;
	cin >> n;
	vector<pi> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	//d[i] : i�ϱ��� ������� ���� �ִ� ����

	for (int i = 0; i < n; i++)
	{
		d[i + 1] = Max(d[i], d[i + 1]); //��� ���� x
		d[i + v[i].first] = Max(d[i + v[i].first], d[i] + v[i].second); //��� ���� o
	}

	cout << d[n] << '\n';
	return 0;
}
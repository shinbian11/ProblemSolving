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
	
int n;
int a[10004];
int d[10004];

int main()
{
	F_I;

	//[����] 2156�� : ������ �ý� (dp - bottom-up)
	/*
	d[i] : i ��° �����ֱ��� ������ �ִ� �ִ� ��
	e.g.) d[1] = a[1]
	d[2] = a[1]+a[2]

	and, d[3] = (a[1]+a[2] , a[1]+a[3], a[2]+a[3]) �� �ִ밪

	...

	��, d[n] ��
	1. d[n - 3] + a[n - 1] + a[n] , 
	2. d[n - 2] + a[n]
	3. d[n - 1] 
	�� �߿����� �ִ밪�̴�.

	���� 3���� �����ָ� ������ �ȵȴٴ� ���Ǹ� �����ϸ� �ȴ�!
	*/
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	d[0] = 0;
	d[1] = a[1];
	d[2] = a[1] + a[2];


	for (int i = 3; i <= n; i++)
	{
		d[i] = max(max(d[i - 3] + a[i - 1] + a[i], d[i - 2] + a[i]), d[i - 1]);
	}

	cout << d[n] << '\n';

	return 0;
}
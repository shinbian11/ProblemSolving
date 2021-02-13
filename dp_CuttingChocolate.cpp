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

int d[400][400];
int n, m;

int go(int x, int y)
{
	/*
	��� n*m-1 �ϸ� Ǯ���� �ſ� ������ ��������, ���� dp�� ���ٸ� �̷��� �ذ� �����ϴ�!

	d[n][m] : ���� n , ���� m ¥�� ���ݸ��� 1 * 1 �� �ڸ��� �ּ� Ƚ��
	1. d[n][m] �� ���η� �ڸ��� ��� : d[i][m] + d[n-i][m] + 1 
	2. d[n][m] �� ���η� �ڸ��� ��� : d[n][i] + d[n][m-i] + 1 
	- 1. �� 2. >> �� ���� �ּ� �� d[n][m]�� ���� ���� �ָ� �ȴ�.
	
	*/
	if (x == 1 && y == 1) return 0;

	int& ans = d[x][y];
	if (ans != -1) return ans;

	ans = 1e9;

	//���ݸ��� ���η� �ڸ��� ���
	for (int i = 0; i <= x; i++)
	{
		if (ans > go(i, y) + go(x - i, y) + 1)
			ans = go(i, y) + go(x - i, y) + 1;
	}
	//���ݸ��� ���η� �ڸ��� ���
	for (int i = 0; i <= y; i++)
	{
		if (ans > go(x, i) + go(x, y - i) + 1)
			ans = go(x, i) + go(x, y - i) + 1;
	}

	return ans;
}

int main()
{
	//[����] 2163�� : ���ݸ� �ڸ��� (Top-down)

	F_I;

	int n, m;
	cin >> n >> m;

	memset(d, -1, sizeof(d));

	cout << go(n, m) << '\n';

	return 0;
}
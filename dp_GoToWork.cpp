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

int d[51][51][51][4][4];

string st;
int len;

int a;
int b;
int c;

int go(int a, int b, int c, int p1, int p2)
{
	/*
	- [����] 12969�� : ABC (dp, Top-down) �� ����� �����̴�.

	d[a][b][c][p1][p2] : A�� a��, B�� b��, C�� c�� �̰�, ���� �ٹ��� ����� p1, ������ �ٹ��� ����� p2�϶��� ������ �����ϸ� 1, �ƴϸ� 0�̴�.
	
	- �̶� p1,p2 ���� A : 1, B : 2, C: 3�̶�� ����.

	 ______p2 p1 : d[a][b][c][p1][p2] �� �Ѵٸ�,

	 ______p2 p1 a : d[a+1][b][c][a][p1]
	 ______p2 p1 b : p1 != b �̸�, d[a][b+1][c][b][p1]
	 ______p2 p1 c : p1 != c �̰�, p2 != c �̸�, d[a][b][c+1][c][p1]

	*/
	if (a + b + c == 0) //��������
	{
		return d[a][b][c][p1][p2] = 1; //������ �����Ѵٴ� �ǹ�!
	}

	if (d[a][b][c][p1][p2] != -1) //memoization
		return d[a][b][c][p1][p2];

	if (a > 0 && go(a - 1, b, c, 1, p1) == 1)
		return d[a][b][c][p1][p2] = 1;
	if (b > 0 && p1 != 2)
	{
		if (go(a, b - 1, c, 2, p1) == 1)
			return d[a][b][c][p1][p2] = 1;
	}
	if (c > 0 && p1 != 3 && p2 != 3)
	{
		if (go(a, b , c-1, 3, p1) == 1)
			return d[a][b][c][p1][p2] = 1;
	}

	return d[a][b][c][p1][p2] = 0;
}

string build(int a, int b, int c, int p1, int p2) //go�Լ��� ���� �����Ѵٴ� ����� ����Ǿ��ٸ�, build �Լ��� ���� �� ���ڿ��� �����!
{
	if (a + b + c == 0)
	{
		return "";
	}

	if (a > 0 && go(a - 1, b, c, 1, p1) == 1)
		return "A" + build(a - 1, b, c, 1, p1);
	if (b > 0 && p1 != 2)
	{
		if (go(a, b - 1, c, 2, p1) == 1)
			return "B" + build(a, b - 1, c, 2, p1);
	}
	if (c > 0 && p1 != 3 && p2 != 3)
	{
		if (go(a, b, c - 1, 3, p1) == 1)
			return "C" + build(a, b, c - 1, 3, p1);
	}

	return "";
}

int main()
{
	//[����] 14238�� : ��� ��� (DP, TOP_DOWN)
	
	cin >> st;

	len = st.length();

	for (int i = 0; i < len; i++)
	{
		if (st[i] == 'A')
			a += 1;
		if (st[i] == 'B')
			b += 1;
		if (st[i] == 'C')
			c += 1;
	}

	memset(d, -1, sizeof(d));

	if (go(a,b,c, 0, 0)) 
		cout << build(a, b, c, 0, 0) << '\n';
	else
		cout << -1 << '\n';

	return 0;
}
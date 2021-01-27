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

int n, k;
int d[34][34][34][(34 * 35) / 2];
char ans[34];

bool go(int idx, int a, int b, int p)
{
	/*
	*
	> d[idx][a][b][p] : ���̰� idx�� �̰�, A�� a��, B�� b��, C�� idx-a-b���� ���ڿ��� p�� �����ϸ� 1. �������� ������ 0. ���� �𸣸� -1(�ʱⰪ)

	 ______ : d[idx][a][b][p] �� �Ѵٸ�,

	 ______a : d[idx+1][a+1][b][p]
	 ______b : d[idx+1][a][b+1][p+a]
	 ______c : d[idx+1][a][b][p+a+b] �̴�.

	*/

	if (idx == n) //���������� ���� n�� ���ڿ��� ������� ��, 
	{
		if (p == k) //���࿡ ���ǿ� �����ϴ� ���� ������
			return d[idx][a][b][p] = 1; //1 ��ȯ (����)
		else //������
			return  d[idx][a][b][p] = 0; //0 ��ȯ (���� X)
	}

	if (d[idx][a][b][p] != -1) //memoization
		return d[idx][a][b][p];

	d[idx][a][b][p] = 0;

	ans[idx] = 'A';
	if (go(idx + 1, a + 1, b, p)) return d[idx][a][b][p] = 1; //�����ϸ� 1 �����ؼ� ��ȯ

	ans[idx] = 'B';
	if (go(idx + 1, a, b + 1, p + a)) return d[idx][a][b][p] = 1; //�����ϸ� 1 �����ؼ� ��ȯ

	ans[idx] = 'C';
	if (go(idx + 1, a, b, p + a + b)) return d[idx][a][b][p] = 1; //�����ϸ� 1 �����ؼ� ��ȯ

	return d[idx][a][b][p] = 0; //�ƴϸ� 1 �����ؼ� ��ȯ
}

int main()
{
	//[����] 12969�� : ABC (dp, Top-down)
	cin >> n >> k;

	memset(d, -1, sizeof(d));

	if (go(0, 0, 0, 0))
		cout << ans << '\n';
	else
		cout << -1 << '\n';
	return 0;
}
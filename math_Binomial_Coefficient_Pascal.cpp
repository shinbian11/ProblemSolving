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

int main()
{
	F_I;

	/*

	���� 11050�� : ���� ��� 1  (�Ľ�Į�� �ﰢ��)

	- ���װ�� : n �� �߿��� k���� �ߺ� ���� ���� ����� �� (nCk) => n! / (k!* (n-k)!)  => O(n)�� �ð����⵵ �ҿ�.

	- �ٵ� n�� Ŀ���� n! ���� �����÷ο찡 �� ������ ��û Ŀ����..
	 �� , �ð��� �� �� �ɸ�����, ���丮���� �̿����� �ʴ� ����� �����ؾ� �Ѵ�.

	- �Ľ�Į�� �ﰢ���� �̿��ϸ�, O(n^2)�� �ð��� �ɸ��� ������, �����÷ο� ���� ���ϴ� ���� ���� �� �ִ�.
	���� : https://m.blog.naver.com/PostView.nhn?blogId=whtrb_study&logNo=220771365785&proxyReferer=https:%2F%2Fwww.google.co.kr%2F
	*/

	int n, k;
	cin >> n >> k;

	vector< vector<int> > pascal(n + 1, vector<int>(n + 1));

	for (int i = 0; i <= n; i++)
	{
		pascal[i][0] = 1;
		pascal[i][i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			pascal[i + 1][j + 1] = pascal[i][j + 1] + pascal[i][j];
		}
	}

	cout << pascal[n][k] << '\n';

	return 0;
}
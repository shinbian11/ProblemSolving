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

	//[����] 16953�� : A -> B (���Ʈ ����)
	ll a, b;
	cin >> a >> b;
	int cnt = 0;
	
	//a�� b�� ���� �� ������, b�ε� a�� ������ ���� �� �ִ�.
	//���� �� ���ų�, a>b�� �Ǿ������ ��� >> -1
	while (true)
	{
		if (a > b)
			break;
		if (a == b)
		{
			cout << cnt + 1 << '\n';
			return 0;
		}
		if (b % 2 == 0)
			b /= 2;
		else if (b % 10 == 1)
			b = (b - 1) / 10;
		else
			break;

		cnt += 1;
	}

	cout << -1 << '\n';

	return 0;
}
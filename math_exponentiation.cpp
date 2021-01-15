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
	1629�� : ���� (���� + �ŵ������� �ϴ� ���)

	- a^b�� �ŵ������� �� ��,
	
	int ans = 1;
	for (int i = 0; i < b; i++)
		ans *= a;

	- �� ����� O(b)�� �ð����⵵�� �ҿ�ȴ�.
	
	- �� ������� �� �� ȿ������ ����� �ִ�.

	- '������'�� �̿��ϴ� ���

	e.g.) 3^27�� �� ��, 3^27 = 3^(16+8+2+1) = 3^16 + 3^8 + 3^2 + 3^1 �̴�.

	a		3	3^2  3^4  3^8  3^16	
	b		27   13   6    3    1 
	������   1    1	  0	   1    1

	b�� 2�� ������ ��, �������� 1�� ������ �׶��� a�� �ŵ����� �۾��� �ϴµ��� �־ �� �ʿ��� �����̴�.
	- �� ����� �̿��ϸ� O(log(b)) �ð����⵵�� �ŵ����� �۾��� �ذ� �����ϴ�.

	*/
	ll a, b, c;
	ll ans = 1;
	cin >> a >> b >> c;

	while (true)
	{
		if (b == 0)
			break;
		if (b % 2 != 0)
		{
			ans *= a;
			ans %= c;
		}
		a *= a;
		a %= c;
		b /= 2;
	}

	cout << ans << '\n';
	return 0;
}
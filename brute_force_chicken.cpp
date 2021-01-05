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
 
	/*
	���� 16917�� : ��� �� �Ķ��̵� �� (���Ʈ ���� + ���)
	- ���,�Ķ��̵� ġŲ�� ���� �ִ� 10�� ���������� �����ϹǷ� ������ �� �������� ���ѽð����� ���� ���� �� �ִٴ� ����� �˾ƾ� �Ѵ�.
	- ���Ʈ ���� �̿�!
	*/

	int a, b, c, x, y;
	ll ans = 1e18;
	cin >> a >> b >> c >> x >> y;
	for (int i = 0; i <= 100000; i++)
	{
		int A = Max(0, x - i) * a; //x���� i�� Ŀ���� ���� �������� �ʴ´�. �� �׷� ������ �׳� 0���� �ٲٱ�.
		int B = Max(0, y - i) * b; ///y���� i�� Ŀ���� ���� �������� �ʴ´�. �� �׷� ������ �׳� 0���� �ٲٱ�.
		int C = (2 * c * i);
		if (ans > (ll)A + B + C)
			ans = (ll)A + B + C;
	}
	cout << ans << '\n';
	return 0;
}
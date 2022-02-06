#include <bits/stdc++.h>

#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); // F_I ��� �� ����) scanf �� cin ȥ�� ��� ����
#define INF 987654321

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

	// [����] 2792�� : ���� ���� (�̺� Ž��)
	
	/*
	* �̷��� Ǯ�����ϴ�)
	
	������ a��, b��, c��, ... ���� ��,
	�� ��� �� x ���� �����شٰ� �ϸ�,
	a/x + b/x + c/x + ... ���� �ʿ��ϴ�! (���� a % x �� 0 �� �ƴϸ�, a/x �� �ƴ϶� a/x + 1 �� �������� �Ѵ�! �������� ó���ϴ� 1���� �߰������� �ʿ���)
	�� `a/x + b/x + c/x + ...` �� `x���� ������ �� �ʿ��� �� ����� ��` ��� ����.

	�� a/x + b/x + c/x + ... �� n ���� ũ�� �ȵǴϱ�, ���� n ���� ũ�ٸ�, `x���� ������ �� �ʿ��� �� ����� ��` �� ���̱� ���� x ���� �÷��� �Ѵ�.
	(�� ����� ������� �ϴ� ������ ���� ũ��, �� ���� ����鸸���ε� ����ϴϱ�)

	�̶� �� x�� ���� �̺�Ž������ ������!!
	*/

	ll n, m;
	ll mx = -1e18;
	cin >> n >> m;
	vector<ll> j(m);

	for (int i = 0; i < m; i++) {
		cin >> j[i];
		mx = max(mx, j[i]);
	}

	ll s = 1;
	ll e = mx;
	ll ans = 1e9;

	while (s <= e) {
		ll x = (s + e) / 2; // �� ����� ������ ������ ���� : x��
		ll sum = 0;
		for (int i = 0; i < m; i++) {
			sum += j[i] / x;
			if (j[i] % x != 0)
				sum += 1;

			//if (sum > n) {
			//	break;
			//}
		}

		if (sum > n) {
			s = x + 1;
		}
		else {
			ans = min(ans, x);
			e = x - 1;
		}
	}

	cout << ans << '\n';

	return 0;

}
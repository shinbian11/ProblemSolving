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
	// https://www.acmicpc.net/board/view/83220 ����
	// [����] 2343�� - ��Ÿ ���� (���� Ž��)

	F_I;

	ll n, m;
	ll mx = -1e18;
	cin >> n >> m;
	vector<ll> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}

	ll s = mx;
	ll e = 1e18;

	while (s <= e) {

		ll mid = (s + e) / 2;
		ll cnt = 0;
		ll tmp = 0;

		for (int i = 0; i < n; i++) {
			if (tmp + v[i] > mid) {
				cnt += 1;
				tmp = 0;
			}
			tmp += v[i];
		}
		cnt += 1;

		if (cnt > m) {
			s = mid + 1;
		}
		else if (cnt < m) {
			e = mid - 1;
		}
		else { // cnt == m 
			e = mid - 1;
		}

		/*
		e = mid - 1�� ������ ������ �����ϴ� ���� ������ ���� �۰� ����� ��..
		cnt == M �϶�, e = mid - 1; �� �ϰ�, ������ s �� ���Ѵ� => cnt == M �� ��緹�� �� �ּ� ���� ã��.

		������ cnt == M �� ��緹�� �� �ִ� ���� ã������
		s = mid + 1�� ���ϰ� (������ �����ϴ� ���� ������ ���� ũ�� ����� ��), ������ e �� ���Ѵ�.
		*/
	}

	cout << s << '\n';

	return 0;

}
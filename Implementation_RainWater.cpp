#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
	
	// [min(���� �������� ���ʿ��� ���� ū ž & ���� �������� �����ʿ��� ���� ū ž) - ���� ����]�� ���� ���ϸ� �ȴ�.
	// https://hwan-shell.tistory.com/276 �����ϱ�
	// ���� �������� �ϳ��ϳ��� ������ ���̴� ������ ���ذ���

	int h, w;
	int ans = 0;
	cin >> h >> w;
	vector<int> v(w);
	for (int i = 0; i < w; i++)
		cin >> v[i];

	for (int i = 1; i < w - 1; i++) {
		int left = 0, right = 0;
		for (int j = 0; j < i; j++) { // ���� �������� ���ʿ��� ���� ū ž
			left = max(left, v[j]);
		}
		for (int j = i + 1; j < w; j++) { // ���� �������� �����ʿ��� ���� ū ž
			right = max(right, v[j]);
		}
		int cmp = min(left, right);
		if (cmp - v[i] > 0) { //min(����, ������)�� ���� ���̺��� ������, �� ��ġ������ ���� ����� �ʴ´ٴ� �ǹ��̴�.
			ans += (cmp - v[i]);
		}
	}
	cout << ans << '\n';

	return 0;
}
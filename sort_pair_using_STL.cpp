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

	//���� 11651�� ��ǥ �����ϱ� 2
	//c++ sort �� ��!
	//x��ǥ, y��ǥ ������ �Է� �޾Ƽ� ���� ������ �켱������ x��ǥ�� �ƴ϶� y��ǥ�� �ǰ� �Ϸ���, �Է��� �Ųٷ� ������ �ȴ�.
	//y��ǥ�� ���� �� ���� �켱������ x��ǥ�� ���ϴ� �κ��� �ڵ��� ���� �ʿ� ����. sort �Լ��� �װ͵� ����!

	int n;
	cin >> n;

	vector<pi> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].second >> v[i].first;
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		cout << v[i].second << ' ' << v[i].first << '\n';
	}
	return 0;
}
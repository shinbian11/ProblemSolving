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

struct Point
{
	int x, y;
};

bool cmp(Point& a, Point& b)
{
	if (a.y > b.y)
		return false;
	else if (a.y < b.y)
		return true;
	else if (a.y == b.y)
	{
		if (a.x > b.x)
			return false;
		else
			return true;
	}
}

int main()
{
	F_I;

	//���� 11651�� ��ǥ �����ϱ� 2
	//c++ sort�� ����ص�, �Է��� �Ųٷ� ���� �ʰ�, ����ü�� �����, cmp ����� ���� �Լ��� �����Ͽ� ���� �켱������ ������ֱ�.

	int n;
	cin >> n;

	vector<Point> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].x >> v[i].y;
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		cout << v[i].x << ' ' << v[i].y << '\n';
	}
	return 0;
}
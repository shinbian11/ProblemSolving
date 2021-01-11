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
	11060�� : ���� ���� (dp + bottom-up 2)
	*/

	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> d(n, -1);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	d[0] = 0;

	for (int i = 0; i < n; i++)
	{
		if (d[i] == -1)
			continue;
		for (int j = 0; j <= v[i]; j++)
		{ 
			//���ʿ� ������ �� �ִ� ������ 0���� v[i]������ ���س��� ���� ���ϴ� ����̹Ƿ�, 
			//������ �� Ž���ϰ� �� ���Ŀ� i-j <= v[j] �� ���� üũ�� �ϴ� ������ ��ĺ��� �� ȿ�����̴�.
			
			if (i + j >= n)
				break;

			if (d[i + j] == -1)
				d[i + j] = d[i] + 1;
			else
				d[i + j] = Min(d[i + j], d[i] + 1);
		}
	}

	cout << d[n - 1] << '\n';

	return 0;
}
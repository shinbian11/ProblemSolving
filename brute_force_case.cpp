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
	- ���� 16968�� : ���� ��ȣ�� 1 (���Ʈ ����)
	idx=0�϶��� �ƴҶ��� ������, �ٷ� ���� �ε����� ���� �������� �ƴ����� �� ������ �����ϸ� �ȴ�.

	*/
	string s;
	cin >> s;
	int ans = 1;
	for (int i = 0; i < s.length(); i++)
	{
		if (i == 0)
		{
			if (s[i] == 'c')
				ans *= 26;
			else //s[i]=='d'
				ans *= 10;
		}
		else
		{
			if (s[i - 1] == s[i])
			{
				if (s[i] == 'c')
					ans *= 25;
				else
					ans *= 9;
			}
			else
			{
				if (s[i] == 'c')
					ans *= 26;
				else //s[i]=='d'
					ans *= 10;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
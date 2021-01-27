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
	//[����] 12026�� : BOJ �Ÿ� (dp, Bottom_up)

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> d(n, -1);
	d[0] = 0;

	for (int i = 1; i < n; i++)
	{
		char now = s[i];
		char prev_predict;
		if (now == 'B')
			prev_predict = 'J';
		else if (now == 'O')
			prev_predict = 'B';
		else if (now == 'J')
			prev_predict = 'O';

		for (int j = 0; j < i; j++)
		{
			if (d[j] == -1)
				continue;

			if (s[j] == prev_predict)
			{
				int tmp = d[j] + (i - j) * (i - j);

				if (d[i] == -1 || d[i] > tmp)
					d[i] = tmp;
			}
		}
	}

	cout << d[n - 1] << '\n';

	return 0;
}
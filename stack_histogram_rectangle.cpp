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
	���� 6549�� : ������׷����� ���� ū ���簢�� (����)
	������ ���� : ���簢���� width�� ���� ��, ������ ��𼭺��� ���������� �����ִ� ����(s.top()+1 ��°����)
	*/
	while (true)
	{
		ll n;
		cin >> n;

		vector<ll> s;
		stack<ll> st;

		for (ll i = 0; i < n; i++)
		{
			ll num;
			cin >> num;
			s.push_back(num);
		}

		if (n == 0)
			return 0;

		ll ans = 0;
		ll width, height;

		for (ll i = 0; i < n; i++)
		{

			if (st.empty())
				st.push(i);
			else
			{
				while (!st.empty() && s[st.top()] > s[i])
				{
					height = s[st.top()];
					width = i; 

					st.pop();

					//width�� ���Ҷ�, st.top()+1 ��° ����, i-1��° ������ width �� �ؾ��Ѵ�!
					if (!st.empty())
						width = (i - 1) - (st.top() + 1) + 1;

					if (ans < height * width)
						ans = height * width;

				}
				st.push(i);
			}
		}
		while (!st.empty())
		{
			height = s[st.top()];
			width = n;

			st.pop();
			if (!st.empty())
				width = (n - 1) - (st.top() + 1) + 1;

			if (ans < height * width)
				ans = height * width;
		}
		cout << ans << '\n';
	}
}
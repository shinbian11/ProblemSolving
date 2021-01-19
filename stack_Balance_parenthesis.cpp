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

	//F_I;
	/*
	 [����] 4949�� : �������� ���� (����)
	 - ���� ���� �̾߱� �ϴ� ��ȣ ������ �� �ϳ��̴�.
	*/
	while (true)
	{
		string s;
		getline(cin, s);

		int length = s.length();

		if (length == 1 && s[0] == '.')
			return 0;

		stack<int> st;
		bool flag = false;
		for (int i = 0; i < length; i++)
		{
			if (s[i] == '(' || s[i] == '[')
				st.push(s[i]);

			if (s[i] == ')')
			{
				if (!st.empty() && st.top() == '(')
				{
					st.pop();
				}
				else // (()))) ���� ���!
				{
					cout << "no" << '\n';
					flag = true;
					break;
				}
			}
			
			if (s[i] == ']')
			{
				if (!st.empty() && st.top() == '[')
				{
					st.pop();
				}
				else
				{
					cout << "no" << '\n';
					flag = true;
					break;
				}
			}

		}

		if (!flag)
		{
			if (st.empty())
				cout << "yes" << '\n';
			else
				cout << "no" << '\n';
		}
		
	}
	return 0;
}
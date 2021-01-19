#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int main()
{

	//F_I;
	/*
	 [백준] 4949번 : 균형잡힌 세상 (스택)
	 - 흔히 많이 이야기 하는 괄호 문제들 중 하나이다.
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
				else // (()))) 같은 경우!
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
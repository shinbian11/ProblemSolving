#include <bits/stdc++.h>
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
	F_I;
	/*
	백준 6549번 : 히스토그램에서 가장 큰 직사각형 (스택)
	스택의 역할 : 직사각형의 width를 구할 때, 왼쪽을 어디서부터 시작할지를 정해주는 역할(s.top()+1 번째부터)
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

					//width를 구할때, st.top()+1 번째 부터, i-1번째 까지를 width 라 해야한다!
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
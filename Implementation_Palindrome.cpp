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
	F_I;

	//[백준] 1213번 : 팰린드롬 만들기 (구현, 팰린드롬의 종류)

	vector<int> alpha(26);
	string str;
	cin >> str;
	int len = str.length();

	//팰린드롬의 종류 2가지

	//1. 모든 문자가 짝수개
	//2. 한 문자가 홀수개, 나머지 모든 문자는 짝수개

	for (int i = 0; i < len; i++)
		alpha[str[i]-'A'] += 1; //문자열이 가지고 있는 문자의 개수들을 기록

	int even = 0, odd = 0, odd_number_idx = 0;
	for (int i = 0; i < alpha.size(); i++)
	{
		if (alpha[i] == 0) continue;

		if (alpha[i] % 2 == 0) even += 1; //짝수 개수
		else
		{
			odd += 1; //홀수 개수 
			odd_number_idx = i; 
		}
	}

	string ans = "";

	if (odd <= 1) //1. 모든 문자가 짝수개, 2. 한 문자가 홀수개, 나머지 모든 문자는 짝수개인 경우
	{
		for (int i = 0; i < alpha.size(); i++)
		{
			for (int j = 0; j < alpha[i] / 2; j++) //각 알파벳의 개수를 반 씩만 사용한다.
			{
				ans += (char)((int)'A' + i);
			}

		}

		string ans2 = ans;
		reverse(ans2.begin(), ans2.end()); //팰린드롬을 만들어야 하므로, ans의 reverse 문자열을 붙인다.

		if (odd == 1) //2번의 경우에만
			ans += (char)((int)'A' + odd_number_idx); //홀수 개수를 가지는 문자열을 중간에 한 개 붙인다.

		ans += ans2; //뒤집은 문자열을 뒤에 붙인다. (팰린드롬을 위해)


	}
	else // 홀수 개수가 2개 이상. 팰린드롬 불가
	{
		ans = "I'm Sorry Hansoo";
	}
	
	cout << ans << '\n';

	return 0;
}
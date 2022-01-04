#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 987654321

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

	string str;
	cin >> str;
	vector<string> strArr;
	for (int i = 0; i < str.length(); i++) {
		strArr.push_back(str.substr(i)); //str.substr(i) : str의 i번째 idx부터 끝까지의 문자열만 slicing 하겠다는 의미!
	}
	sort(strArr.begin(), strArr.end());
	for (int i = 0; i < str.length(); i++)
		cout << strArr[i] << '\n';

	return 0;
}
#include <bits/stdc++.h>
//#include <unordered_set>
//#include <unordered_map>

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

	/*
	백준 1764번 : 듣보잡 (multiset 과 set)

	- 듣도 못한 이름을 n만큼 입력하고,
	- 보도 못한 이름을 m만큼 입력받으면서, 기존에 듣도 못한 이름에도 동일한 이름이 있었다면, ans set에다가 따로 옮겨놓기!
	*/

	multiset<string> a;
	set<string> ans;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		a.insert(name);
	}
	for (int i = 0; i < m; i++)
	{
		string name;
		cin >> name;
		a.insert(name);
		if (a.count(name) == 2)
			ans.insert(name);
	}

	cout << ans.size() << '\n';
	for (set<string>::iterator it = ans.begin(); it != ans.end(); it++)
	{
		cout << *it << '\n';
	}

	return 0;
}
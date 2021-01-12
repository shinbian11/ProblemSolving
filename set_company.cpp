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
	7785번 : 회사에 있는 사람 (set에 대해)
	- set을 이용하여 enter면 그 사람을 insert, leave면 그 사람을 erase 한다. 최종적으로 남아있는 사람들을 역순으로 출력
	- set을 이용하여 출력할 때, 원래의 순서와 역순으로 출력 하는 방법을 배움!
	*/

	set<string> s;
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name, state;
		cin >> name >> state;
		if (state == "enter")
			s.insert(name);
		else if (state == "leave")
			s.erase(name);
	}

	//(set<string>::iterator it = s.begin(); it != s.end(); it++) >> 원래 순서 출력
	//(set<string>::reverse_iterator it = s.rbegin(); it != s.rend(); it++) >> 역순 출력
	for (set<string>::reverse_iterator it = s.rbegin(); it != s.rend(); it++)
		cout << *it << '\n';

	return 0;
}
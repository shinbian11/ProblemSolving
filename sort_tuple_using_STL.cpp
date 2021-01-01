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

	//백준 10814번 : 나이순 정렬 (c++의 sort 함수는 우선순위를 알아서 정해준다. 그 우선순위는 맨 앞에 있는 field부터이다.)
	//여기서는 age, idx, name 순으로 저장했으므로, age순으로 오름차순, age가 같으면 idx순, 그 다음은 name순으로 정렬해준다!
	int n;
	cin >> n;
	vector<tuple<int, int, string>> v;
	for (int i = 0; i < n; i++)
	{
		int age;
		string name;
		cin >> age >> name;
		v.push_back(make_tuple(age, i, name));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		int age, idx;
		string name;
		tie(age, idx, name) = v[i];
		cout << age << ' ' << name << '\n';
	}
	return 0;
}
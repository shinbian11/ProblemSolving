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

	//C++ stl lower_bound, upper_bound 에 대해

	vector<int> a;

	a.push_back(4);
	a.push_back(6);
	a.push_back(1);
	a.push_back(2);
	a.push_back(9);
	a.push_back(2);

	sort(a.begin(), a.end());

	for (int i = 0; i < 6; i++)
		cout << a[i] << ' '; // 1 2 2 4 6 9

	cout << '\n';

	/*
	- 조건 : 오름차순 정렬
	
	lower_bound(a.begin(),a.end(),num) -> num보다 '크거나 같은' 원소의 최초의 위치를 가르킴
	upper_bound(a.begin(),a.end(),num) -> num보다 '큰' 원소의 최초의 위치를 가르킴

	[0] [1] [2] [3] [4] [5]
	 1   2   2   4   6   9 에서 num이 2면,  lower_bound는 [1]번째 인덱스를 가르키고, upper_bound는 [3]번째 인덱스를 가르킴.

	*/
	auto it = lower_bound(a.begin(), a.end(), 2);
	cout << *it << '\n'; // 2


	auto it2 = upper_bound(a.begin(), a.end(), 2);
	cout << *it2 << '\n'; // 4
	 
	return 0;
}
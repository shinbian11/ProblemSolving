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
	//백준 16943번 : 숫자 재배치 (브루트 포스 + stoi)

	/*
	* 
	정수 a를 string 으로 입력받아서, 각각의 원소들을 next_permutation으로 조합을 돌리면서 비교하면 된다.
	a의 최대가 1e9이므로, O(10!) = 3628800이므로 충분히 시간 내에 가능하다.
	
	- 문자열을 정수로 바꾸는 방법 (stoi) >> 중요한 함수이므로 꼭 잊어먹지 말 것!
	*/
	string a;
	int b;
	cin >> a >> b;
	int ans = -1;
	sort(a.begin(), a.end());

	do
	{
		int num = stoi(a);
		if (a[0] != '0' && num < b)
		{
			if (ans < num)
				ans = num;
		}

	} while (next_permutation(a.begin(), a.end()));

	cout << ans << '\n';

	return 0;
}
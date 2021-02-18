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

	// [백준] 1484번 : 다이어트 (투 포인터) 

	vector<int> ans; //ans에 가능한 현재 몸무게 넣어준다. ans가 empty 면 -1 출력!
	int G;
	cin >> G;
	int s = 1, e = 1;
	while (e >= s && e <= G && s <= G)
	{
		if (e * e - s * s > G)
			s += 1;
		if (e * e - s * s < G)
			e += 1;
		if (e * e - s * s == G)
		{
			ans.push_back(e);
			e += 1;
		}
	}

	if (ans.empty())
		cout << -1 << '\n';
	else
	{
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << '\n';
	}

	return 0;
}
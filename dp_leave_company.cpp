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

int d[1500081];

int main()
{
	F_I;

	/*
	백준 15486번 퇴사 2 (dp)
	*/

	int n;
	cin >> n;
	vector<pi> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	//d[i] : i일까지 상담했을 때의 최대 수익

	for (int i = 0; i < n; i++)
	{
		d[i + 1] = Max(d[i], d[i + 1]); //상담 선택 x
		d[i + v[i].first] = Max(d[i + v[i].first], d[i] + v[i].second); //상담 선택 o
	}

	cout << d[n] << '\n';
	return 0;
}
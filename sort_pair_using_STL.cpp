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

	//백준 11651번 좌표 정렬하기 2
	//c++ sort 의 힘!
	//x좌표, y좌표 순서로 입력 받아서 정렬 기준의 우선순위가 x좌표가 아니라 y좌표가 되게 하려면, 입력을 거꾸로 받으면 된다.
	//y좌표가 같을 때 다음 우선순위인 x좌표를 비교하는 부분의 코딩은 해줄 필요 없다. sort 함수가 그것도 해줌!

	int n;
	cin >> n;

	vector<pi> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].second >> v[i].first;
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		cout << v[i].second << ' ' << v[i].first << '\n';
	}
	return 0;
}
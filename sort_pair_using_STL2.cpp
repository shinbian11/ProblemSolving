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

struct Point
{
	int x, y;
};

bool cmp(Point& a, Point& b)
{
	if (a.y > b.y)
		return false;
	else if (a.y < b.y)
		return true;
	else if (a.y == b.y)
	{
		if (a.x > b.x)
			return false;
		else
			return true;
	}
}

int main()
{
	F_I;

	//백준 11651번 좌표 정렬하기 2
	//c++ sort를 사용해되, 입력을 거꾸로 받지 않고, 구조체를 만들고, cmp 사용자 정의 함수를 선언하여 직접 우선순위를 만들어주기.

	int n;
	cin >> n;

	vector<Point> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].x >> v[i].y;
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		cout << v[i].x << ' ' << v[i].y << '\n';
	}
	return 0;
}
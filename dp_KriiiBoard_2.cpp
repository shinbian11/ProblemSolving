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

ll d[104];

ll go(int x) //top-down 방법
{
	if (x == 0)
		return d[x] = 0;
	if (x == 1)
		return d[x] = 1;
	if (x == 2)
		return d[x] = 2;
	if (x == 3)
		return d[x] = 3;

	if (d[x] != -1)
		return d[x];

	ll &ans = d[x];

	if (ans < go(x - 1) + (ll)1)
		ans = go(x - 1) + (ll)1;

	for (int y = 1; y <= x - 3; y++)
	{
		if (ans < go(x - (y + 2)) * (ll)(y + 1))
			ans = go(x - (y + 2)) * (ll)(y + 1);
	}

	return ans;
}

int main()
{
	F_I;

	/*
	[백준] 11058번 : 크리보드 (dp, top-down)

	- 크리보드의 1번을 누르는 경우
	- 크리보드의 2,3,4번을 연속으로 누르는 경우

	이 2가지로 행동을 나눌 수 있다.

	d[n]을 n번 버튼을 눌렀을 때 나오는 A의 최대 개수라고 한다면, 

	1번을 누른다고 했을때는 : d[n]은 d[n-1] + 1 이다. 

	2,3,4번을 연속으로 누른다고 했을 때는:

	ctrl-a, ctrl-c, ctrl-v 를 누르면 >> d[n] = d[n-3]+d[n-3] >> d[n-3]번 눌렀을 때의 A를 ctrl-a,c,v 를 함으로써 한번 더 출력 하니까..
	ctrl-a, ctrl-c, ctrl-v, ctrl-v 를 누르면 >> d[n] = d[n-4] + (d[n-4] * 2) >> d[n-4]번 눌렀을 때의 A를 ctrl- a,c, 하고 v를 두 번 눌러서 두번 더 출력 하니까.
	....

	d[n] = d[n-(j+2)]*(j+1) 이다. (이때 1<=j<=n-3)

	>> 즉, d[i] = max( d[i-1] + 1, d[i-(j+2)]*(j+1) ) 이다. (1<=j<=i-3)

	*/

	

	int n;
	cin >> n;

	memset(d, -1, sizeof(d));	
	//memset(d, 0, sizeof(d));	

	cout << go(n) << '\n';


	//bottom-up 방법

	/*d[0] = 0;
	d[1] = 1;
	d[2] = 2;
	d[3] = 3;

	for (int x = 4; x <= n; x++)
	{
		ll ans = -1e18;
		for (int y = 1; y <= x - 3; y++)
		{
			if (ans < d[x - (y + 2)] * (y + 1))
				ans = d[x - (y + 2)] * (ll)(y + 1);
		}
		if (ans < d[x - 1] + 1)
			d[x] = d[x - 1] + 1;
		else
			d[x] = ans;
	}

	cout << d[n] << '\n';*/

	return 0;
}
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

	//AtCoder Beginner Contest 191 : C - Digital Graffiti
	
	//#으로 이루어진 다각형이 몇각형인지를 구하는 문제 -> 변의 개수를 세거나, 꼭짓점의 개수를 세어주면 된다.

	/*
	- 꼭짓점을 세는 기발한 방법!
	 
	- 일단 #을 1로, .을 0으로 변환한다.
	
	- 꼭짓점은 크게 두 가지 경우가 있는데,

##
#.
	>> 이 경우와,

..
.#
	>> 이 경우가 있다.

	- 첫번째 경우는 네 공간의 합이 3이고, 두번째 경우는 합이 1이다. 
	- 즉, 네 공간의 합을 구해 합이 1 or 3인 경우가 꼭짓점이므로, 그러한 경우의 개수를 세어주면 된다.

	*/

	int h, w;

	cin >> h >> w;

	vector<string> arr(h);
	vector< vector<int> >d(h, vector<int>(w, 0));

	for (int i = 0; i < h; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (arr[i][j] == '#')
			{
				d[i][j] = 1;
			}
			else
				d[i][j] = 0;
		}
	}
	int ans = 0;
	for (int i = 0; i < h - 1; i++)
	{
		for (int j = 0; j < w - 1; j++)
		{
			//인접한 네 공간의 합이 1 or 3이면 ans 1 증가시키기!
			int sum = d[i][j] + d[i + 1][j] + d[i][j + 1] + d[i + 1][j + 1];
			if (sum & 1)
				ans += 1;
		}
	}

	cout << ans << '\n';

	return 0;
}


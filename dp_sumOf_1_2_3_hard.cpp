#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int d[10004];

int main()
{
	F_I;
	/*
	백준 15989번 : 1, 2, 3 더하기 4 (dp)
	- 구성 요소가 같은 경우는 1가지로 생각해야 한다. 다시 말해
	1+1+2 와 2+1+2는 2가지가 아니라 1가지이다.
	- 입력 받은 수를 (1로만 구성하는 방법 + 2로만 구성하는 방법 + 3로만 구성하는 방법) >> 이 순서로 처리해야 한다.

	e.g.) 입력 받은 수가 4라면,

	(1로만)
	1  1
	2  1+1
	3  1+1+1
	4  1+1+1+1

	(2로만)

	1  (1)
	2  (1+1)   (2)
	3  1+1+1    (1)+2  
	4  1+1+1+1   (1+1)+2  (2)+2

	(3로만)

	1  (1)
	2  (1+1)   (2)
	3  1+1+1    (1)+2  3
	4  1+1+1+1   (1+1)+2  (2)+2  (1)+3  => 총 4가지이다.

	*/
	int n;
	cin >> n;
	int arr[3] = { 1,2,3 };

	while (n--)
	{
		int m;
		cin >> m;

		memset(d, 0, sizeof(d));

		d[0] = 1;

		for (int j = 0; j < 3; j++)
		{
			for (int i = 1; i <= m; i++)
			{
				if (i - arr[j] >= 0)
					d[i] += d[i - arr[j]];
			}
		}

		cout << d[m] << '\n';
	}
	return 0;
}
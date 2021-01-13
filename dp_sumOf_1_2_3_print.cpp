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

int d[14];
int n, k;

void print(int n, int k)
{
	/*n이 4일때, 가짓수는 7가지인데 이를 사전순으로 정렬하면,
	
	1+1+1+1
	1+1+2
	1+2+1
	1+3

	2+1+1
	2+2

	3+1

	-> 이 순서대로 나뉘어진다. 
	-> 잘 살펴보면 이런 규칙이 나온다.

	-> 1로 시작하는 개수 : 4개 (=d[3])
	-> 2로 시작하는 개수 : 2개 (=d[2])
	-> 3로 시작하는 개수 : 1개 (=d[1])

	*/
	for (int i = 1; i <= 3; i++)
	{
		if (d[n - i] < k)
			k -= d[n - i];
		else
		{
			if (n - i > 0)
			{
				cout << i;
				cout << '+';
				print(n - i, k);
			}
			else
				cout << i << '\n';
			break;
		}
	}
	return;
}

int main()
{
	F_I;

	//백준 12101번 : 1, 2, 3 더하기 2 (dp, 규칙성)

	cin >> n >> k;
	
	memset(d, 0, sizeof(d));

	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= 10; i++)
	{
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}

	print(n, k);
	return 0;
}
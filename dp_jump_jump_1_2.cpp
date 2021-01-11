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

	/*
	11060번 : 점프 점프 (dp + bottom-up 2)
	*/

	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> d(n, -1);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	d[0] = 0;

	for (int i = 0; i < n; i++)
	{
		if (d[i] == -1)
			continue;
		for (int j = 0; j <= v[i]; j++)
		{ 
			//애초에 점프할 수 있는 구간을 0부터 v[i]까지만 정해놓고 값을 비교하는 방법이므로, 
			//일일히 다 탐색하고 그 이후에 i-j <= v[j] 로 구간 체크를 하는 기존의 방식보다 더 효율적이다.
			
			if (i + j >= n)
				break;

			if (d[i + j] == -1)
				d[i + j] = d[i] + 1;
			else
				d[i + j] = Min(d[i + j], d[i] + 1);
		}
	}

	cout << d[n - 1] << '\n';

	return 0;
}
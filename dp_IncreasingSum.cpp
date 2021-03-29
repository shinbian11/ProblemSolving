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

ll arr[1004];
ll d[1004];

int main()
{
	F_I;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		d[i] = arr[i];
	}
	
	//d[i] : i번 인덱스까지의 가장 큰 부분 수열의 합
	//arr[j] < arr[i] : 증가하는 수열이라는 뜻
	//d[j] + arr[i] > d[i] : 지금까지의 최댓값 + arr[i]이 최대라면, 그것이 d[i]가 되어야 한다.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && d[j] + arr[i] > d[i])
			{
				d[i] = d[j] + arr[i];
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		if (ans < d[i])
			ans = d[i];
	}
	cout << ans << '\n';

	return 0;
}
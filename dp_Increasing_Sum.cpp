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
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			//'증가'하는 부분 수열에서 '합이 최대'인 수열의 합을 구하는 문제
			//arr[j] < arr[i] : '증가'하는 수열
			//d[j] + arr[i] > d[i] : 이전까지 더해왔던 합 + i번째 수 가 지금보다 크면 지금의 것을 그 합에 더해야 한다!
			
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

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

int main()
{
	F_I;

	/*

	백준 17436번 : 소수의 배수 (포함/배제의 원리 : Inclusion-exclusion Principle)

	- a와 b의 교집합 : a+b - a와 b의 교집합  =>  (한개씩의 집합) - (두개씩의 교집합)
	- a/b/c의 교집합 : a+b+c  - (두개씩의 교집합) + (3개씩의 교집합) => (한개씩의 집합) - (두개씩의 교집합) + (세개씩의 교집합)

	...

	- n개의 교집합 : (한개의 집합) - (두개씩의 교집합) + (세개씩의 교집합) - (4개씩의 교집합)+ ...
	=> 짝수개일때는 빼주고, 홀수개일때는 더해준다.

	*/

	ll arr[15];

	ll n, m;
	ll sum = 0;
	ll ans = 0;
	cin >> n >> m;
	

	for (ll i = 0; i < n; i++)
		cin >> arr[i];

	//이해 안되면 직접 써가면서 해보기!
	for (ll i = 1; i < ((ll)1 << n); i++)
	{
		ll cnt = 0;
		ll num = 1;

		for (ll j = 0; j < n; j++)
		{
			//j번째 소수를 선택하는 작업 => 소수 2와 3을 택했다는 건, m보다 작은 범위에서, 그것들의 곱인 6의 배수의 개수를 구하겠다는 의미이다!
			//그래서 num에다가 소수들을 곱하는 것이다.
			if (i & ((ll)1 << j))
			{
				num *= arr[j]; 
				cnt += 1;
			}
		}

		if (cnt % 2 == 0) //짝수개일때는 빼주고,
		{
			ans -= (m / num); //m이 100이고, num이 2*3 = 6이라면, 100보다 작은 6의 배수의 개수는 , 100/6 = 16개이다.
		}
		else // 홀수개일때는 더해준다.
			ans += (m / num);
	}

	cout << ans << '\n';

	return 0;
}
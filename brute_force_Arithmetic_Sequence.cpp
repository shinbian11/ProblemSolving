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
	
	[백준] 17088번 : 등차수열 변환 (브루트 포스 + 수학)

	등차수열 an은 an = a0+(n-1)*d인데, a0은 3가지가 나올 수 있다. (a0 / a0 + 1 / a0 - 1)
	또한, d = a1-a0인데, a1도 a0과 마찬가지로 3가지가 가능하고, a0은 앞에서 정해졌으므로,
	an의 경우의 수는 총 3*3 = 9가지 이다. 모두 시도해보면 된다. (브루트 포스)

	*/

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	if (n == 1)
	{
		cout << 0 << '\n';
		return 0;
	}

	int ans = 1e9;

	for (int d1 = -1; d1 <= 1; d1++) //a0의 항의 경우의 수 : 3가지  (a0-1 / a0 / a0+1)
	{
		for (int d2 = -1; d2 <= 1; d2++)  //a1의 항의 경우의 수 : 3가지  (a1-1 / a1 / a1+1)
		{
			int change = 0; //연산횟수의 합

			if (d1 != 0) change += 1; //d1 != 0이라는 건 + 1 이나 - 1 의 연산을 1번 했다는 거니까
			if (d2 != 0) change += 1; //d2 != 0이라는 건 + 1 이나 - 1 의 연산을 1번 했다는 거니까

			int a0 = (arr[0] + d1); //첫번째 항
			int d = (arr[1] + d2) - a0; //공차

			bool flag = true;
			int na = a0 + d;

			for (int i = 2; i < n; i++)
			{
				na += d;

				if (arr[i] == na) continue;

				if (arr[i] + 1 == na || arr[i] - 1 == na)
					change += 1;
				else
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				if (ans > change)
				{
					ans = change;
				}
			}
		}
	}

	if (ans == 1e9)
		cout << -1 << '\n';
	else
		cout << ans << '\n';

	return 0;
}
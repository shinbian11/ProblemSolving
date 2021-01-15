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

ll wave[1500005];

int main()
{
	F_I;
	
	/*
	
	백준 2749번 : 피보나치 수 3

	- n번째 피보나치 수를 m으로 나눈 나머지를 구하는 문제
	- 피보나치 수들을 m으로 나눈 나머지들을 담은 배열은 반드시 주기 k 를 가지고 반복된다.
	  그 배열에서 n번째 피보나치 수를 m으로 나눈 나머지는, n%k번째 피보나치 수와 같다!!

	  e.g.) 
	  n     0  1  2  3  4  5  6  7   |  8  9  10  11  12   13  14  15
	 fibo   0  1  1  2  3  5  8  13  |  21 34 55  89  144  233 377 610
	fibo%3  0  1  1  2  0  2  2  1   |  0  1   1   2   0    2   2   1

	- 3으로 나누었을 때의 주기는 8이므로, 예를 들어 13번째 피보나치 수를 3으로 나눈 나머지는, 13%8 => 5번째 피보나치 수와 같다.


	- 또한, m이 10의 거듭제곱 (10^p)의 형태이고, p>2 라면, 그때의 주기는 항상 15 * 10^(p-1) 이다.

	- 이 문제에서는 m이 1000000(10^6)이므로, 주기는 15 * 10^5 = 1500000이다.
	  n번째 피보나치 수를 m(10^6)으로 나눈 나머지는, n % 1500000 번째 피보나치 수와 같다!!

	*/ 

	int mod = 1e6;

	
	wave[0] = 0;
	wave[1] = 1;

	for (int i = 2; i < 1500000; i++)
	{
		wave[i] = wave[i - 1] + wave[i - 2];
		wave[i] %= mod;
	}

	ll n;
	cin >> n;

	cout << wave[n % 1500000] << '\n';

	return 0;
}
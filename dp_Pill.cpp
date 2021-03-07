#include <bits/stdc++.h>
#include <unordered_set>

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

//d[f][h] : 알약 한 조각이 f개, 알약 반 조각이 h개 일때, 먹을 수 있는 경우의 수 (문자열의 경우의 수)
//한 조각을 선택하는 경우: 한 조각은 -1 되지만, 반조각은 +1 된다.
//반 조각을 선택하는 경우: 한 조각은 그대로지만, 반조각은 -1 된다.
//즉 d[f][h] = d[f-1][h+1] + d[f][h-1]이다.
ll d[31][31]; 

ll calc(int f, int h)
{
	if (d[f][h] != -1) return d[f][h]; //memoization
	if (f == 0) return 1; //한 조각이 없고 반 조각만 있는 경우 > 반조각만 계속 먹으므로 경우의 수 1가지이다.
	if (h == 0) return calc(f - 1, 1); //반 조각이 없고 한 조각만 f 개 있는 경우 > 한 조각은 f-1 개, 반조각은 1개가 된다.
	return d[f][h] = calc(f - 1, h + 1) + calc(f, h - 1); //위 두 경우가 아닌 경우
}

int main()
{
	F_I;

	//[백준] 4811번 : 알약 (dp_ Top down)

	while (true)
	{
		memset(d, -1, sizeof(d));
		int n;
		cin >> n;
		if (n == 0)
			return 0;
		cout << calc(n, 0) << '\n'; //맨 처음에는 한조각이 n개, 반조각이 0개니까.
	}

	return 0;
}
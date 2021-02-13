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

ll d[54][54][54][54];
ll mod = 1e9 + 7;

/*
 e.g.)

n번째 곡을 a,b가 부른다고 했으면, d[n-1][a-1][b-1][c]가 되는 것이다.
n번째 곡을 a,c가 부른다고 했으면, d[n-1][a-1][b][c-1]가 되는 것이다.
....
....
....

- 즉, d[n][a][b][c] = d[n-1][a-i][b-j][c-k]의 합이다. (i,j,k는 0~1이다.)
*/

ll go(int n, int a, int b, int c)
{
	if (n == 0)
	{
		if (a == 0 && b == 0 && c == 0) //n개의 곡을 각자 a,b,c개 씩 다 조건에 맞게 잘 불렀으니, 1가지 방법 추가!
			return 1;
		else
			return 0;
	}

	if (a < 0 || b < 0 || c < 0) return 0; //범위 체크

	//memoization
	if (d[n][a][b][c] != -1)
		return d[n][a][b][c];

	ll ans = 0;

	//i,j,k가 1이다 >> 그 사람이 그 곡을 부른다는 의미!
	for (int i = 0; i <= 1; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			for (int k = 0; k <= 1; k++)
			{
				if (i == 0 && j == 0 && k == 0) continue; //모두가 곡을 안 부르는 경우 제외
				ans += go(n - 1, a - i, b - j, c - k);
			}
		}
	}

	ans %= mod;

	return d[n][a][b][c] = ans;
}

int main()
{
	//[백준] 12996번 : Acka (dp)
	F_I;
	int n, a, b, c;
	cin >> n >> a >> b >> c;

	memset(d, -1, sizeof(d)); //-1로 초기화 (메모이제이션을 취해서)

	cout << go(n, a, b, c) << '\n';

	return 0;
}
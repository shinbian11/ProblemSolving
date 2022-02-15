#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int p[3000][3000];
int cnt[3];

int same(int i, int j, int m)// i행 j열부터 m * m 행렬이 모두 같으면 1, 아니면 0 반환
{
	for (int x = i; x < i + m; x++)
	{
		for (int y = j ; y < j + m; y++)
		{
			if (p[i][j] != p[x][y])
				return 0;
		}
	}
	return 1;
}

void solve(int i, int j, int n) 
{
	if (same(i, j, n)) //i행 j열부터 n * n 행렬이 모두 같으면
	{
		cnt[p[i][j] + 1] += 1; // 그 i행 j열에 해당하는 숫자의 개수 기록해두기!
		return;
	}
	else
	{
		int m = n / 3;
		for (int x = 0; x < 3; x++) // i행 j열부터 n * n 행렬이 다른 값이 있으면
		{
			for (int y = 0; y < 3; y++)
			{
				solve(i + m * x, j + m * y, m); //각각을 9개의 종이로 각각 잘라서, 자른 9등분을 모두 재귀함수로 호출한다.
			}
		}
	}
}
int main() 
{
	F_I;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> p[i][j];
	}

	solve(0, 0, n);

	for (int i = 0; i < 3; i++)
		cout << cnt[i] << '\n';
	return 0;
}
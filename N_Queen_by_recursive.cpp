//c++

//qsort 사용법 : qsort(정렬할배열, 요소개수, 요소 하나의 크기, 비교함수); / qsort(정렬할메모리주소, 요소개수, 요소 하나의 크기, 비교함수);
// void qsort(void* _Base, size_t _NumOfElements, size_t _SizeOfElements, int (*_PtFuncCompare)(void const*, void const*));
//재귀
#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int n, ans;
int col[40];

int check(int row)
{
	for (int i = 0; i < row; i++)
	{
		if (col[row] == col[i])
			return 0;
		if (abs(col[row] - col[i]) == abs(row - i))
			return 0;
	}
	return 1;
}

void queen(int row)
{
	if (row == n)
	{
		ans++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		col[row] = i;
		if (check(row))
		{
			queen(row + 1);
		}
	}

}

int main()
{
	F_I;
	cin >> n;
	queen(0);
	cout << ans << '\n';
	return 0;
}
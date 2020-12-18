//c++

//qsort 사용법 : qsort(정렬할배열, 요소개수, 요소 하나의 크기, 비교함수); / qsort(정렬할메모리주소, 요소개수, 요소 하나의 크기, 비교함수);
// void qsort(void* _Base, size_t _NumOfElements, size_t _SizeOfElements, int (*_PtFuncCompare)(void const*, void const*));
//백트래킹
#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int column[20];
int dig_r[40];
int dig_l[40];
int arr[16][16];
int n;

int check(int row, int col)
{
	if (column[col])
		return 0;
	else if (dig_r[row + col])
		return 0;
	else if (dig_l[row - col + n])
		return 0;
	else
		return 1;
}
int queen(int row)
{
	if (row == n)
		return 1;
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (check(row, i)) //check == 1 이라는 건 두어도 된다는 뜻
		{
			column[i] = 1;
			dig_r[row + i] = 1;
			dig_l[row - i + n] = 1;
			arr[row][i] = 1;

			cnt += queen(row + 1);

			column[i] = 0;
			dig_r[row + i] = 0;
			dig_l[row - i + n] = 0;
			arr[row][i] = 0;
		}
	}
	return cnt;

}

int main()
{
	F_I;

	cin >> n;
	cout << queen(0) << '\n';

	return 0;
}
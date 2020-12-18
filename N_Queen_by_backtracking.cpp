//c++

//qsort ���� : qsort(�����ҹ迭, ��Ұ���, ��� �ϳ��� ũ��, ���Լ�); / qsort(�����Ҹ޸��ּ�, ��Ұ���, ��� �ϳ��� ũ��, ���Լ�);
// void qsort(void* _Base, size_t _NumOfElements, size_t _SizeOfElements, int (*_PtFuncCompare)(void const*, void const*));
//��Ʈ��ŷ
#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

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
		if (check(row, i)) //check == 1 �̶�� �� �ξ �ȴٴ� ��
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
#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

int arr[500001];
int brr[500001];
//���� c++ : 1517�� ���� ��Ʈ
/*
���� ������ �̿��Ͽ� ���� ���Ŀ����� swap Ƚ���� ���� �� �ִ�.
���� ������ �̿��Ͽ� mid�� �������� ���� ����, ���� ����� �����ʵ���� ���Ҹ� �Ѱ��� ���� ���Ͽ� ���� ���� ���ο� �迭�� �־��ִ� ������ �ݺ��Ҷ�,
������ ����� �ִ� ���Ҹ� �̵����Ѿ� �� ���� ���� ����� ���� ���� ������ �� ���ϸ� �װ��� swap �� Ƚ�� �̴�.
e.g.)
		3 5 2 9
		/     \
	  3 5     2 9

brr :   2 3 5 9

2�� brr�� �����Ҷ�, ���� �� [3 5] > 2�� �����ϱ� 2 ����
9�� brr�� �����Ҷ�, ���� ���� �ƹ��͵� �����ϱ� 0 ����
> �� : 2�� swap �ؾ� ��.

*/
ll solve(int s, int e)
{
	if (s == e) //��������
		return 0;

	int mid = (s + e) / 2;
	ll ans = solve(s, mid) + solve(mid + 1, e);

	int i = s;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= e)
	{
		if (arr[i] <= arr[j])
		{
			brr[k++] = arr[i++];
		}
		else
		{
			ans += (ll)((ll)mid - i + 1);
			brr[k++] = arr[j++];
		}
	}
	if (i > mid)
	{
		for (int l = j; l <= e; l++)
		{
			//ans += (ll)((ll)mid - i + 1);
			brr[k++] = arr[l];
		}
	}
	else if (j > e)
	{
		for (int l = i; l <= mid; l++)
			brr[k++] = arr[l];
	}

	// brr�� �ű� ������ �ٽ� ������ arr�迭�� �ű��.
	for (int i = s; i <= e; i++) {
		arr[i] = brr[i - s];
	}

	return ans;
}
int main()
{
	F_I;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	ll ans = solve(0, n - 1);
	cout << ans << '\n';
	return 0;

}
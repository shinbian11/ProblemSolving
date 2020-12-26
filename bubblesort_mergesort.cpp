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

int arr[500001];
int brr[500001];
//백준 c++ : 1517번 버블 소트
/*
병합 정렬을 이용하여 버블 정렬에서의 swap 횟수를 구할 수 있다.
병합 정렬을 이용하여 mid를 기준으로 나눈 이후, 왼쪽 덩어리와 오른쪽덩어리의 원소를 한개씩 각각 비교하여 작은 값을 새로운 배열에 넣어주는 과정을 반복할때,
오른쪽 덩어리에 있는 원소를 이동시켜야 할 때의 왼쪽 덩어리에 남은 원소 개수를 다 더하면 그것이 swap 총 횟수 이다.
e.g.)
		3 5 2 9
		/     \
	  3 5     2 9

brr :   2 3 5 9

2를 brr에 저장할때, 왼쪽 에 [3 5] > 2개 있으니까 2 저장
9를 brr에 저장할때, 왼쪽 에는 아무것도 없으니까 0 저장
> 답 : 2번 swap 해야 됨.

*/
ll solve(int s, int e)
{
	if (s == e) //종료조건
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

	// brr에 옮긴 값들을 다시 원래의 arr배열로 옮긴다.
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
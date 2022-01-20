#include <bits/stdc++.h>

#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); // F_I 사용 시 주의) scanf 와 cin 혼합 사용 금지
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int arr[1000004];
int lis[1000004];

int binary_search(int left, int right, int target) {

	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (lis[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}

	return right;

}

int main()
{

	// 12738번 : 가장 긴 증가하는 부분 수열 3 (LIS + Binary Search)
	// O(n log n) 소요 => while문 (n) * binarySearch(log n) : n이 클 때 사용 가능
	// 참고) https://chanhuiseok.github.io/posts/algo-49/

	F_I;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	lis[0] = arr[0];
	int i = 1;
	int j = 0;
	while (i < n) {

		if (lis[j] < arr[i]) {
			lis[j + 1] = arr[i];
			j++;
			//i++;
		}
		else {
			int idx = binary_search(0, j, arr[i]);
			lis[idx] = arr[i];
			//i++;
		}
		i++;
	}

	cout << j + 1 << '\n';

	return 0;
}
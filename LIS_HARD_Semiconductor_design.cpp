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

int arr[40004];
int lis[40004];

int binary_search(int left, int right, int target) { //O(log n)

	int mid;

	while (left < right) {

		mid = (left + right) / 2;

		if (lis[mid] < target)
			left = mid + 1;
		else
			right = mid;

	}

	return right;
}

int main()
{
	// 2352번 : 반도체 설계 (LIS + Binary Search)

	// O(n log n) 소요 => while문 (n) * binarySearch(log n) : n이 클 때 사용 가능

	// LIS 쉬운 버전 (O(n^2) 소요), 지금 문제의 해설은 밑 링크 참고
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
		if (arr[i] > lis[j]) {
			lis[j + 1] = arr[i];
			j += 1;
			//i += 1;
		}
		else {
			int index = binary_search(0, j, arr[i]);
			lis[index] = arr[i];
			//i += 1;
		}
		i += 1;
	}

	cout << j + 1 << '\n';

	return 0;
}
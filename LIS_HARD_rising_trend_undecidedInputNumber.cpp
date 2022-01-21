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

int arr[100004];
int lis[100004];

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

	F_I;
	// 백준 3745번 : 오름세
	// LIS + 이진탐색
	// 전형적인 O(nlogn)의 시간복잡도를 가지는 LIS + 이진탐색 문제이다.
	// 12738번의 가장 긴 증가하는 부분 수열 3 이나, 1365번의 꼬인 전깃줄 문제와 거의 같은 문제이다.

	// 중요) *** testcase 개수가 정해지지 않은 문제에서 입력 받는 방법 숙지하기!

	while (true) {

		// (시작) testcase 개수가 정해지지 않은 문제에서 입력 받는 방법!!

		//문자열로 첫 입력을 받고, 그 입력이 없으면 종료, 있으면 숫자로 변환하여 계속 진행!

		string num;
		cin >> num;

		if (num == "")
			break;

		int n = stoi(num);

		// 더 좋은 방법 : while 문 바깥쪽에 int n; 선언 이후, while문 조건식에 cin >> n 을 해도 된다.

		// (끝) testcase 개수가 정해지지 않은 문제에서 입력 받는 방법!!

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		lis[0] = arr[0];
		int i = 1;
		int j = 0;

		while (i < n) {
			if (arr[i] > lis[j]) {
				lis[j + 1] = arr[i];
				j += 1;
			}
			else {
				int idx = binary_search(0, j, arr[i]);
				lis[idx] = arr[i];
			}
			i += 1;
		}

		cout << j + 1 << '\n';
	}

	return 0;
}
#include <bits/stdc++.h>

#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); // F_I ��� �� ����) scanf �� cin ȥ�� ��� ����
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

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
	// 2352�� : �ݵ�ü ���� (LIS + Binary Search)

	// O(n log n) �ҿ� => while�� (n) * binarySearch(log n) : n�� Ŭ �� ��� ����

	// LIS ���� ���� (O(n^2) �ҿ�), ���� ������ �ؼ��� �� ��ũ ����
	// ����) https://chanhuiseok.github.io/posts/algo-49/

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
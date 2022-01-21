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

	// ���� 1365�� : ���� ������
	// LIS + ����Ž��
	// �������� O(nlogn)�� �ð����⵵�� ������ LIS + ����Ž�� �����̴�.
	// 12738�� ���� �� �����ϴ� �κ� ���� 3 �� ���� ���� �����̴�.

	int n;
	cin >> n;

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

	cout << n - (j + 1) << '\n';

	return 0;
}
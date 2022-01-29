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

int main()
{

	F_I;

	// [����] 2559�� : ���� (�� ������ + ��Ÿ ���� (undefined behavior, ���ڿ��� �����ͷ� �������� �� ������ �Ұ����� ����) )

	int n, k;
	cin >> n >> k;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ptrA = 0, ptrB = k - 1;
	int sum = 0;
	for (int i = ptrA; i <= ptrB; i++) sum += arr[i];

	int ans = -1e9;

	while (ptrB < n) {

		ans = max(ans, sum);

		sum -= arr[ptrA];

		ptrA += 1;
		ptrB += 1;

		// ���� ptrB >= n �̶�� ���ǹ� �κ��� �ּ� ó���ϸ�,
		// ptrB�� n-1�϶� while���� ���ͼ� ptrB +=1 �� �ϸ� arr[ptrB]�� arr[n]�� �ǹǷ� Index Out of Bound (�ε��� �����ʰ�) ������ �߻��ϴ� ���� �����̴�!
		// �׷���, �� ���ؿ����� �� ���ǹ� �κ��� �ּ�ó���ص� ���� ó���� �Ǵ���?

		// undefined behavior �̶�� ���� �����̴�!

		// ����) https://blog.naver.com/PostView.naver?blogId=cjw531&logNo=222088737540&categoryNo=6&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView

		// ���� 2) ���ڿ��� �迭�� �����ϸ� ������ �����ϰ�, �����ͷ� �����ϸ� ������ �Ұ����� ���� : https://hydroponicglass.tistory.com/181

		if (ptrB >= n) {
			break;
		}

		sum += arr[ptrB];
	}

	cout << ans << '\n';

	return 0;

}
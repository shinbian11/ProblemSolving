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

int main()
{

	F_I;

	// [백준] 2559번 : 수열 (투 포인터 + 기타 개념 (undefined behavior, 문자열을 포인터로 선언했을 때 수정이 불가능한 이유) )

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

		// 밑의 ptrB >= n 이라는 조건문 부분을 주석 처리하면,
		// ptrB가 n-1일때 while문에 들어와서 ptrB +=1 을 하면 arr[ptrB]가 arr[n]이 되므로 Index Out of Bound (인덱스 범위초과) 에러가 발생하는 것이 정상이다!
		// 그런데, 왜 백준에서는 이 조건문 부분을 주석처리해도 정답 처리가 되는지?

		// undefined behavior 이라는 개념 때문이다!

		// 참고) https://blog.naver.com/PostView.naver?blogId=cjw531&logNo=222088737540&categoryNo=6&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView

		// 참고 2) 문자열을 배열로 선언하면 수정이 가능하고, 포인터로 선언하면 수정이 불가능한 이유 : https://hydroponicglass.tistory.com/181

		if (ptrB >= n) {
			break;
		}

		sum += arr[ptrB];
	}

	cout << ans << '\n';

	return 0;

}
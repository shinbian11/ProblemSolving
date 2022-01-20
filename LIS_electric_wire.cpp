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
	// 2565번 : 전깃줄 (LIS)

	F_I;

	/*
	1번째 2번째
	1	  8
	3	  9
	2	  2
	4	  1
	6	  4
	10	  10
	9	  7
	7	  6

	=> 이러한 정보에서, 전봇줄이 교차하지 않으려면, 1번째 전봇대와 연결되는 위치의 번호를 기준으로 정렬하고, 
	2번째 전봇대와 연결되는 위치의 번호의 최장 증가 부분 수열(LIS, Longest Increasing Subsequence)을 찾고, 전체 개수에서 뺴주면 된다.

	=> 일단 1번째 전봇대와 연결되는 위치의 번호를 기준으로 정렬하기!

	1번째 2번째
	1	  8
	2	  2
	3	  9
	4	  1
	6	  4
	7	  6
	9	  7
	10	  10

	=> 예를 들어 (1,8)이 이어졌다면, 그 다음부터 이어져야 할 2번째 전봇대와 연결되는 위치의 번호는 8보다 커야 한다. (e.g. (3,9), (10,10))
	=> 즉, 2번째 전봇대와 연결되는 위치의 번호의 LIS를 찾으면, 5가 나온다.
	=> 즉, 전봇줄을 교차하지 않고, 최대 5개의 전봇줄을 연결 할 수 있다.
	=> 그러기 위해 없애야 하는 전봇줄의 최소 개수는 8-5 = 3개이다.

	참고) https://chanhuiseok.github.io/posts/algo-49/

	*/

	// n의 개수가 작을 떄 가능한 LIS 방법이다!! (시간복잡도 n^2)
	// n이 클 때? => 참고) https://chanhuiseok.github.io/posts/algo-49/

	int n, mx = 1;
	cin >> n;

	vector<pi> v(n);
	vector<int> arr(n);
	vector<int> length(n, 1);

	for (int i = 0; i < n; i++) {
		// v : (1번째 전봇대와 연결되는 위치의 번호 , 2번째 전봇대와 연결되는 위치의 번호)
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		arr[i] = v[i].second; // 2번째 전봇대와 연결되는 위치의 번호 들만 골라서 arr이라는 배열을 구성함
	}
	
	//LIS 구하는 부분
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				length[i] = max(length[i], length[j] + 1);
				mx = max(mx, length[i]); // mx : LIS
			}
		}
	}

	cout << n - mx << '\n';

	return 0;
}
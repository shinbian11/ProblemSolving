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

ll w[31], ans, n, c;
vector<ll> group1, group2;

void dfs(int start, int end, vector<ll>& v, ll sum) {

	// dfs 함수의 3번째 매개변수의 레퍼런스 기호 (&) 는 필수이다. call by reference!
	// 레퍼런스 기호(&)가 없다면 벡터 v가 호출될 때 인수를 통해 받아온 벡터를 복사해 오기는 하겠지만,
	// push_back()의 결과가 group1, group2가 아닌 v에만 적용되며, return을 지나고 v는 소멸된다.
	// 즉 & 를 붙이면 그 변수를 함수 내에서 변경해도 밖에서 변경된 부분이 유지되고, 그렇지 않다면 함수 내에서만 변했다가 소멸됨.

	if (start > end) {
		v.push_back(sum);
		return;
	}
	else {
		dfs(start + 1, end, v, sum + w[start]); // start 번째의 물건을 선택하는 경우
		dfs(start + 1, end, v, sum); // start 번째의 물건을 선택하지 않는 경우
	}
}

int main()
{

	F_I;

	// 백준 1450번 : 냅색문제 (시간복잡도, dfs, upper_bound, reference 기호 (&) 등등 학습)

	// 참고 링크 : https://cocoon1787.tistory.com/358

	/*
	시간복잡도를 고려해야 하는 문제이다. n 이 최대 30 이므로, 최대 2^30 ( 1073741824 )의 가짓수가 나올 수 있어서 시간초과가 나온다.

	일단 n개의 물건을 반반으로 나눈다.
	초반 n/2개의 물건으로 만들 수 있는 물건의 총 무게의 가짓수를 group1 에,
	후반 n/2개의 물건으로 만들 수 있는 물건의 총 무게의 가짓수를 group2 에 담는다.

	그리고 group2는 sorting 을 한다.

	group1의 i번째 값에다가 group2의 특정 값을 더했을 때 c를 넘기지 않는 group2의 인덱스의 최대를 구하면, 그것이 group1의 i번째에서 얻을 수 있는 경우의 수이다.

	예를 들어 group1의 0번째 값이 10이고, c가 15이며, 정렬된 group2 배열이 1 3 5 7 과 같다면,
	10+1, 10+3, 10+5 까지는 15를 넘기지 않으므로, group1의 0번째 값이 10일때 얻을 수 있는 경우의 수는 3가지이다.
	이 방식을 반복한다.

	i를 group1 의 처음부터 끝까지 반복하며, 그때마다 나오는 경우의 수를 모두 더한다.

	*/
	cin >> n >> c;

	for (int i = 0; i < n; i++)
		cin >> w[i];

	dfs(0, n / 2, group1, 0);
	dfs(n / 2 + 1, n - 1, group2, 0);

	sort(group2.begin(), group2.end()); // sort stl 의 시간복잡도 : O(nlogn)

	// 이중 for 문을 돌며 탐색하면 O(group1.size() * group2.size()) 의 시간복잡도를 가지게 된다.
	// group1.size()와 group2.size()는 최대 2^15이므로, 이런 경우에 O(2^30) = O(1073741824)가 나오므로 시간초과가 된다.
	// 그러므로, O(nlogn)의 시간복잡도를 가지게 하기 위해, 이진탐색 기반의 upper_bound를 사용한다.

	for (int i = 0; i < group1.size(); i++) {
		ans += upper_bound(group2.begin(), group2.end(), c - group1[i]) - group2.begin();

		// upper_bound : c - group[i] 값을 초과하는 숫자가 group2 배열의 몇 번째에서 처음 등장하는지 알 수 있음. 
		// lower_bound : c - group[i] 값과 같거나 큰 숫자가 group2 배열의 몇 번째에서 처음 등장하는지 알 수 있음.
		// 이걸 하기 위해 group2를 sort 해야 하는 것이다.
		// iterator 를 반환하므로, index를 알고 싶으면 group2.begin()을 빼주면 된다.

		// upper_bound, lower_bound의 시간복잡도 : 이진탐색 기반이므로 이진탐색과 동일한 O(logn)
		// 참고 링크 : https://chanhuiseok.github.io/posts/algo-55/
	}

	cout << ans << '\n';

	return 0;
}
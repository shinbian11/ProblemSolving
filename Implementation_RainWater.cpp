#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
	
	// [min(나를 기준으로 왼쪽에서 제일 큰 탑 & 나를 기준으로 오른쪽에서 제일 큰 탑) - 나의 높이]의 합을 구하면 된다.
	// https://hwan-shell.tistory.com/276 참고하기
	// 나를 기준으로 하나하나씩 빗물이 고이는 정도를 더해가기

	int h, w;
	int ans = 0;
	cin >> h >> w;
	vector<int> v(w);
	for (int i = 0; i < w; i++)
		cin >> v[i];

	for (int i = 1; i < w - 1; i++) {
		int left = 0, right = 0;
		for (int j = 0; j < i; j++) { // 나를 기준으로 왼쪽에서 제일 큰 탑
			left = max(left, v[j]);
		}
		for (int j = i + 1; j < w; j++) { // 나를 기준으로 오른쪽에서 제일 큰 탑
			right = max(right, v[j]);
		}
		int cmp = min(left, right);
		if (cmp - v[i] > 0) { //min(왼쪽, 오른쪽)이 나의 높이보다 작으면, 이 위치에서는 물이 담기지 않는다는 의미이다.
			ans += (cmp - v[i]);
		}
	}
	cout << ans << '\n';

	return 0;
}
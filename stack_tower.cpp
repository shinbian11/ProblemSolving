#include <bits/stdc++.h>

#define F_I ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); // F_I 사용 시 주의) scanf와 printf 사용 금지, 오로지 cin , cout 만 사용!
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

	// F_I : 코테 때 필수! ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 암기해놓기!
	F_I;


	// [백준] 2493번 : 탑 (Stack 이용 - Deque 보다 조금 덜 복잡함)

	int n;
	cin >> n;
	stack<pi> s;
	queue<int> res;
	for (int i = 1; i <= n; i++) {
		int h;
		cin >> h;
		while (true) {
			if (s.empty()) {
				res.push(0);
				s.push({ h,i });
				break;
			}
			else if (s.top().first > h) {
				res.push(s.top().second);
				s.push({ h,i });
				break;
			}
			else {
				s.pop();
			}
		}
		
	}

	while (!res.empty()) {
		cout << res.front() << " ";
		res.pop();
	}
	return 0;
}
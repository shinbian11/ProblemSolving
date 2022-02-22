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

	// [백준] 1874번 : 스택 수열 (스택)

	stack<int> s;
	vector<int> v;
	vector<char> res;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	int cur = 1;

	for (int i = 0; i < n; i++) {
		if (s.empty() || s.top() < v[i]) { // empty 거나, 입력에 주어진 v[i]의 수가 될때까지 계속 스택에 수를 넣으면서 +를 저장한다.
			while (cur <= v[i]) {
				s.push(cur++);
				res.push_back('+');
			}
			// v[i]와 s.top()이 같아지면, - 하면 됨.
			s.pop();
			res.push_back('-'); // res 배열에 결과를 담아놓고, 끝까지 NO가 나오지 않았을 때만 res 배열의 값을 출력한다.ㅏ
		}
		else { // s.top() >= v[i] 일 때
			if (s.top() != v[i]) { 
				// s.top() != v[i] 이면, 추가적인 숫자를 더 넣어서 s.top()을 v[i]로 만들 수는 없으므로, NO 이다.
				// s.top() 이 5인데, v[i]가 3이면, cur은 최소 6 이상일 것이고, 6보다 더 큰 수를 계속 넣어서 3을 만들 수는 없으므로 NO 이다.
				cout << "NO" << '\n';
				return 0;
			}
			else { // s.top() == v[i]이면, - 하면 됨
				s.pop();
				res.push_back('-');
			}
		}
	}

	for (int i = 0; i < res.size(); i++) cout << res[i] << '\n';

	return 0;
}
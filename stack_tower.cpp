#include <bits/stdc++.h>

#define F_I ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); // F_I ��� �� ����) scanf�� printf ��� ����, ������ cin , cout �� ���!
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

	// F_I : ���� �� �ʼ�! ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); �ϱ��س���!
	F_I;


	// [����] 2493�� : ž (Stack �̿� - Deque ���� ���� �� ������)

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
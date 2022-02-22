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

	// [����] 1874�� : ���� ���� (����)

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
		if (s.empty() || s.top() < v[i]) { // empty �ų�, �Է¿� �־��� v[i]�� ���� �ɶ����� ��� ���ÿ� ���� �����鼭 +�� �����Ѵ�.
			while (cur <= v[i]) {
				s.push(cur++);
				res.push_back('+');
			}
			// v[i]�� s.top()�� ��������, - �ϸ� ��.
			s.pop();
			res.push_back('-'); // res �迭�� ����� ��Ƴ���, ������ NO�� ������ �ʾ��� ���� res �迭�� ���� ����Ѵ�.��
		}
		else { // s.top() >= v[i] �� ��
			if (s.top() != v[i]) { 
				// s.top() != v[i] �̸�, �߰����� ���ڸ� �� �־ s.top()�� v[i]�� ���� ���� �����Ƿ�, NO �̴�.
				// s.top() �� 5�ε�, v[i]�� 3�̸�, cur�� �ּ� 6 �̻��� ���̰�, 6���� �� ū ���� ��� �־ 3�� ���� ���� �����Ƿ� NO �̴�.
				cout << "NO" << '\n';
				return 0;
			}
			else { // s.top() == v[i]�̸�, - �ϸ� ��
				s.pop();
				res.push_back('-');
			}
		}
	}

	for (int i = 0; i < res.size(); i++) cout << res[i] << '\n';

	return 0;
}
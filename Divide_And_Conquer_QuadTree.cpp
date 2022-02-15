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

char arr[70][70];

void DivideAndConquer(int x, int y, int size) {
	char target = arr[x][y];
	int divideSize = size / 2;

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[i][j] != target) {
				// 이 문제는 DivideAndConquer 재귀함수 4번의 호출 순서가 중요하다!
				// 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래 순서로!
				cout << "(";
				DivideAndConquer(x, y, divideSize); // 왼쪽 위
				DivideAndConquer(x, y + divideSize, divideSize); // 오른쪽 위
				DivideAndConquer(x + divideSize, y, divideSize); // 왼쪽 아래
				DivideAndConquer(x + divideSize, y + divideSize, divideSize); // 오른쪽 아래
				cout << ")";
				return;
			}
		}
	}
	cout << target; // arr[i][j] != target 인 경우가 하나도 없는 경우에, 그 범위의 값을 압축해서 한번만 출력하면 되므로!

	return;
}

int main()
{

	F_I;

	// [백준] 1992번 : 쿼드트리 (분할정복)

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			arr[i][j] = str[j];
		}
	}

	DivideAndConquer(0, 0, n);

	return 0;

}
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

int arr[2500][2500];
int minusOne, zero, one;

void DivideAndConquer(int x, int y, int size) {
	int target = arr[x][y];
	int divideSize = size / 3;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[i][j] != target) { // 주의 1) 모든 칸을 다 돌아다니면서 하나라도 틀린 게 있는지 찾는 함수를 만들 필요 없다. 그냥 왼쪽 최상단의 것을 기준으로 (target) 잡아놓고, 그것과 다른 것이 있는지만 판단하면 된다.
				// 주의 2) 단순히 개수를 체크하는 것이지, 9개로 나눴을 때의 순서가 중요한 것이 아니므로, DivideAndConquer의 순서는 이 문제에서는 중요하지 않다.
				DivideAndConquer(x, y, divideSize);
				DivideAndConquer(x + divideSize, y, divideSize);
				DivideAndConquer(x + divideSize * 2, y, divideSize);
				DivideAndConquer(x, y + divideSize, divideSize);
				DivideAndConquer(x, y + 2 * divideSize, divideSize);
				DivideAndConquer(x + divideSize, y + divideSize, divideSize);
				DivideAndConquer(x + divideSize, y + 2 * divideSize, divideSize);
				DivideAndConquer(x + 2 * divideSize, y + divideSize, divideSize);
				DivideAndConquer(x + 2 * divideSize, y + 2 * divideSize, divideSize);
				return; // 주의 3) return 해줘야 한다! 
				// 설령 arr[i][j] != target인 지점이 나중에 또 있다하더라도, 
				// 이 시작점(x,y)과 이 사이즈(size)의 정보를 가지고 반복문을 진행하는 작업은 arr[i][j] != target인 점을 하나라도 찾는 순간 9등분으로 나눠주기만 하고 바로 끝내야 한다.
				// 그렇지 않으면 중복이 많이 발생하므로 오답이 발생할 수 있다.
			}
		}
	}

	if (target == -1) minusOne++;
	else if (target == 0)zero++;
	else if (target == 1)one++;

	return;
}

int main()
{

	F_I;

	// [백준] 1780번 : 종이의 개수 (분할정복 + 주의점)

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	DivideAndConquer(0, 0, n);
	cout << minusOne << '\n' << zero << '\n' << one;
	return 0;

}
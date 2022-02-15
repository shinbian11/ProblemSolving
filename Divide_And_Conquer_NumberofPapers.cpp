#include <bits/stdc++.h>

#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); // F_I ��� �� ����) scanf �� cin ȥ�� ��� ����
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

int arr[2500][2500];
int minusOne, zero, one;

void DivideAndConquer(int x, int y, int size) {
	int target = arr[x][y];
	int divideSize = size / 3;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[i][j] != target) { // ���� 1) ��� ĭ�� �� ���ƴٴϸ鼭 �ϳ��� Ʋ�� �� �ִ��� ã�� �Լ��� ���� �ʿ� ����. �׳� ���� �ֻ���� ���� �������� (target) ��Ƴ���, �װͰ� �ٸ� ���� �ִ����� �Ǵ��ϸ� �ȴ�.
				// ���� 2) �ܼ��� ������ üũ�ϴ� ������, 9���� ������ ���� ������ �߿��� ���� �ƴϹǷ�, DivideAndConquer�� ������ �� ���������� �߿����� �ʴ�.
				DivideAndConquer(x, y, divideSize);
				DivideAndConquer(x + divideSize, y, divideSize);
				DivideAndConquer(x + divideSize * 2, y, divideSize);
				DivideAndConquer(x, y + divideSize, divideSize);
				DivideAndConquer(x, y + 2 * divideSize, divideSize);
				DivideAndConquer(x + divideSize, y + divideSize, divideSize);
				DivideAndConquer(x + divideSize, y + 2 * divideSize, divideSize);
				DivideAndConquer(x + 2 * divideSize, y + divideSize, divideSize);
				DivideAndConquer(x + 2 * divideSize, y + 2 * divideSize, divideSize);
				return; // ���� 3) return ����� �Ѵ�! 
				// ���� arr[i][j] != target�� ������ ���߿� �� �ִ��ϴ���, 
				// �� ������(x,y)�� �� ������(size)�� ������ ������ �ݺ����� �����ϴ� �۾��� arr[i][j] != target�� ���� �ϳ��� ã�� ���� 9������� �����ֱ⸸ �ϰ� �ٷ� ������ �Ѵ�.
				// �׷��� ������ �ߺ��� ���� �߻��ϹǷ� ������ �߻��� �� �ִ�.
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

	// [����] 1780�� : ������ ���� (�������� + ������)

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
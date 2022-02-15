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

char arr[70][70];

void DivideAndConquer(int x, int y, int size) {
	char target = arr[x][y];
	int divideSize = size / 2;

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[i][j] != target) {
				// �� ������ DivideAndConquer ����Լ� 4���� ȣ�� ������ �߿��ϴ�!
				// ���� ��, ������ ��, ���� �Ʒ�, ������ �Ʒ� ������!
				cout << "(";
				DivideAndConquer(x, y, divideSize); // ���� ��
				DivideAndConquer(x, y + divideSize, divideSize); // ������ ��
				DivideAndConquer(x + divideSize, y, divideSize); // ���� �Ʒ�
				DivideAndConquer(x + divideSize, y + divideSize, divideSize); // ������ �Ʒ�
				cout << ")";
				return;
			}
		}
	}
	cout << target; // arr[i][j] != target �� ��찡 �ϳ��� ���� ��쿡, �� ������ ���� �����ؼ� �ѹ��� ����ϸ� �ǹǷ�!

	return;
}

int main()
{

	F_I;

	// [����] 1992�� : ����Ʈ�� (��������)

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
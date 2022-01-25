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

ll w[31], ans, n, c;
vector<ll> group1, group2;

void dfs(int start, int end, vector<ll>& v, ll sum) {

	// dfs �Լ��� 3��° �Ű������� ���۷��� ��ȣ (&) �� �ʼ��̴�. call by reference!
	// ���۷��� ��ȣ(&)�� ���ٸ� ���� v�� ȣ��� �� �μ��� ���� �޾ƿ� ���͸� ������ ����� �ϰ�����,
	// push_back()�� ����� group1, group2�� �ƴ� v���� ����Ǹ�, return�� ������ v�� �Ҹ�ȴ�.
	// �� & �� ���̸� �� ������ �Լ� ������ �����ص� �ۿ��� ����� �κ��� �����ǰ�, �׷��� �ʴٸ� �Լ� �������� ���ߴٰ� �Ҹ��.

	if (start > end) {
		v.push_back(sum);
		return;
	}
	else {
		dfs(start + 1, end, v, sum + w[start]); // start ��°�� ������ �����ϴ� ���
		dfs(start + 1, end, v, sum); // start ��°�� ������ �������� �ʴ� ���
	}
}

int main()
{

	F_I;

	// ���� 1450�� : �������� (�ð����⵵, dfs, upper_bound, reference ��ȣ (&) ��� �н�)

	// ���� ��ũ : https://cocoon1787.tistory.com/358

	/*
	�ð����⵵�� ����ؾ� �ϴ� �����̴�. n �� �ִ� 30 �̹Ƿ�, �ִ� 2^30 ( 1073741824 )�� �������� ���� �� �־ �ð��ʰ��� ���´�.

	�ϴ� n���� ������ �ݹ����� ������.
	�ʹ� n/2���� �������� ���� �� �ִ� ������ �� ������ �������� group1 ��,
	�Ĺ� n/2���� �������� ���� �� �ִ� ������ �� ������ �������� group2 �� ��´�.

	�׸��� group2�� sorting �� �Ѵ�.

	group1�� i��° �����ٰ� group2�� Ư�� ���� ������ �� c�� �ѱ��� �ʴ� group2�� �ε����� �ִ븦 ���ϸ�, �װ��� group1�� i��°���� ���� �� �ִ� ����� ���̴�.

	���� ��� group1�� 0��° ���� 10�̰�, c�� 15�̸�, ���ĵ� group2 �迭�� 1 3 5 7 �� ���ٸ�,
	10+1, 10+3, 10+5 ������ 15�� �ѱ��� �����Ƿ�, group1�� 0��° ���� 10�϶� ���� �� �ִ� ����� ���� 3�����̴�.
	�� ����� �ݺ��Ѵ�.

	i�� group1 �� ó������ ������ �ݺ��ϸ�, �׶����� ������ ����� ���� ��� ���Ѵ�.

	*/
	cin >> n >> c;

	for (int i = 0; i < n; i++)
		cin >> w[i];

	dfs(0, n / 2, group1, 0);
	dfs(n / 2 + 1, n - 1, group2, 0);

	sort(group2.begin(), group2.end()); // sort stl �� �ð����⵵ : O(nlogn)

	// ���� for ���� ���� Ž���ϸ� O(group1.size() * group2.size()) �� �ð����⵵�� ������ �ȴ�.
	// group1.size()�� group2.size()�� �ִ� 2^15�̹Ƿ�, �̷� ��쿡 O(2^30) = O(1073741824)�� �����Ƿ� �ð��ʰ��� �ȴ�.
	// �׷��Ƿ�, O(nlogn)�� �ð����⵵�� ������ �ϱ� ����, ����Ž�� ����� upper_bound�� ����Ѵ�.

	for (int i = 0; i < group1.size(); i++) {
		ans += upper_bound(group2.begin(), group2.end(), c - group1[i]) - group2.begin();

		// upper_bound : c - group[i] ���� �ʰ��ϴ� ���ڰ� group2 �迭�� �� ��°���� ó�� �����ϴ��� �� �� ����. 
		// lower_bound : c - group[i] ���� ���ų� ū ���ڰ� group2 �迭�� �� ��°���� ó�� �����ϴ��� �� �� ����.
		// �̰� �ϱ� ���� group2�� sort �ؾ� �ϴ� ���̴�.
		// iterator �� ��ȯ�ϹǷ�, index�� �˰� ������ group2.begin()�� ���ָ� �ȴ�.

		// upper_bound, lower_bound�� �ð����⵵ : ����Ž�� ����̹Ƿ� ����Ž���� ������ O(logn)
		// ���� ��ũ : https://chanhuiseok.github.io/posts/algo-55/
	}

	cout << ans << '\n';

	return 0;
}
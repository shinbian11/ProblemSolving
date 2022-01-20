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

int main()
{
	// 2565�� : ������ (LIS)

	F_I;

	/*
	1��° 2��°
	1	  8
	3	  9
	2	  2
	4	  1
	6	  4
	10	  10
	9	  7
	7	  6

	=> �̷��� ��������, �������� �������� ��������, 1��° ������� ����Ǵ� ��ġ�� ��ȣ�� �������� �����ϰ�, 
	2��° ������� ����Ǵ� ��ġ�� ��ȣ�� ���� ���� �κ� ����(LIS, Longest Increasing Subsequence)�� ã��, ��ü �������� ���ָ� �ȴ�.

	=> �ϴ� 1��° ������� ����Ǵ� ��ġ�� ��ȣ�� �������� �����ϱ�!

	1��° 2��°
	1	  8
	2	  2
	3	  9
	4	  1
	6	  4
	7	  6
	9	  7
	10	  10

	=> ���� ��� (1,8)�� �̾����ٸ�, �� �������� �̾����� �� 2��° ������� ����Ǵ� ��ġ�� ��ȣ�� 8���� Ŀ�� �Ѵ�. (e.g. (3,9), (10,10))
	=> ��, 2��° ������� ����Ǵ� ��ġ�� ��ȣ�� LIS�� ã����, 5�� ���´�.
	=> ��, �������� �������� �ʰ�, �ִ� 5���� �������� ���� �� �� �ִ�.
	=> �׷��� ���� ���־� �ϴ� �������� �ּ� ������ 8-5 = 3���̴�.

	����) https://chanhuiseok.github.io/posts/algo-49/

	*/

	// n�� ������ ���� �� ������ LIS ����̴�!! (�ð����⵵ n^2)
	// n�� Ŭ ��? => ����) https://chanhuiseok.github.io/posts/algo-49/

	int n, mx = 1;
	cin >> n;

	vector<pi> v(n);
	vector<int> arr(n);
	vector<int> length(n, 1);

	for (int i = 0; i < n; i++) {
		// v : (1��° ������� ����Ǵ� ��ġ�� ��ȣ , 2��° ������� ����Ǵ� ��ġ�� ��ȣ)
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		arr[i] = v[i].second; // 2��° ������� ����Ǵ� ��ġ�� ��ȣ �鸸 ��� arr�̶�� �迭�� ������
	}
	
	//LIS ���ϴ� �κ�
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				length[i] = max(length[i], length[j] + 1);
				mx = max(mx, length[i]); // mx : LIS
			}
		}
	}

	cout << n - mx << '\n';

	return 0;
}
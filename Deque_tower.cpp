#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
	F_I;

	int n;
	cin >> n;
	deque<pi> dq;
	vector<int> ans;

	for (int i = 1; i <= n; i++) {
		int cur_tower_height; //tower�� ����
		cin >> cur_tower_height;
		if (i == 1) // ù ��° ž�� ���� ������ ��ȣ�� � ž������ ������ ���� ����
		{
			dq.push_back({ cur_tower_height, i }); // {���� Ÿ���� ����, ���� Ÿ���� ��ȣ}
			ans.push_back(0); // � ž������ ���� ���ϹǷ� ���� �迭���� 0 �Է�
			continue;
		}
		while (true) { //�ڽ��� �ٷ� ���� ž���� �������� �̵��ϸ鼭 Ž��

			if (dq.empty()) { // ���� ž���� ���� ž�� ������ �ϳ��� ��������
				dq.push_back({ cur_tower_height, i });
				ans.push_back(0); // � ž������ ���� ���ϹǷ� ���� �迭���� 0 �Է�
				break;
			}

			//���� ž ������ �ִ� ž�� ���� (�ٷ� ������ ž�� �ƴ� ���� ����)
			int prev_tower_height = dq.back().first;
			//���� ž ������ �ִ� ž�� �ε��� (�ٷ� ������ ž�� �ƴ� ���� ����)
			int prev_tower_idx = dq.back().second;

			if (prev_tower_height < cur_tower_height) {
				/*
				prev_tower_height�� cur_tower_height���� ������, prev_tower_height ���� ���� ���� �������Ƿ� pop ��Ű��
				���� : ���� ���Ŀ� ���� ž���� ������ ��ȣ�� ������ �Ǵ��� cur_tower_height �� ������ �� ���ɼ��� �ִ� ����, prev_tower_height�� �ɸ� ���ɼ��� ����.
				(cur_tower_height �� �� ũ�ϱ�!)
				*/
				dq.pop_back(); // �̰� ���ϸ� �ð��ʰ� �ɸ�
			}
			else { // else if (dq.back().first > tower) {
				ans.push_back(prev_tower_idx);
				dq.push_back({ cur_tower_height, i });
				break;
			}
		}
	}

	for (int a : ans)
		cout << a << ' ';
	return 0;
}
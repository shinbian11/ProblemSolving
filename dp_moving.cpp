#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

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

	//11048�� : �̵��ϱ� (dp)

	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			d[i][j] = max({ d[i - 1][j],d[i][j - 1],d[i - 1][j - 1] }) + arr[i][j];
			//d[i][j] = max({ d[i - 1][j],d[i][j - 1] }) + arr[i][j];
			//�������� ������ ������ �׻� 0�̰ų� ����̱� ������, 
			//�밢�� �������� �ѹ��� �������� ������, ������->�ϴ� or �ϴ�->���������� ���� ��찡 �ݵ�� �� ū ���̳� ���� ���� ������ �� �� �ۿ� ����.
			//�׷��Ƿ� d[i-1][j-1]�� ���� �ȴ�.
		}
	}

	cout << d[n][m] << '\n';

	return 0;
}
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

int arr[10][10];
vector<int> p(9);

bool is_magic(vector<int>& p) //���� ���������� �Ǵ�!
{
	int sum = p[0] + p[1] + p[2];

	//�� �˻�
	if (sum != p[0] + p[1] + p[2]) return false;
	if (sum != p[3] + p[4] + p[5]) return false;
	if (sum != p[6] + p[7] + p[8]) return false;

	//�� �˻�
	if (sum != p[0] + p[3] + p[6]) return false;
	if (sum != p[1] + p[4] + p[7]) return false;
	if (sum != p[2] + p[5] + p[8]) return false;

	//�밢�� �˻�
	if (sum != p[0] + p[4] + p[8]) return false;
	if (sum != p[2] + p[4] + p[6]) return false;

	return true;
}

int diff(int arr[][10], vector<int>& p) //��� ���ϱ�
{
	int sum = 0;
	int idx = 0;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			sum += abs((arr[i][j] - p[idx++]));
		}
	}

	return sum;
}

int main()
{
	F_I;

	//[����] 16945�� : ���� ������� �����ϱ� (���Ʈ ����)

	/*
	1~9������ ���� ����ִ� �迭�� ����, ������ �̿��Ͽ� ��� ��쿡 ���� ���� ����� �Ǵ��� ���� �����ϰ�,
	��������� �ȴٸ� �׶��� ������ �ּ� ����� ���ϴ� ���� Ǯ �� �ִ�.	
	*/
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < 9; i++)
		p[i] = i + 1;

	int ans = -1;
	do
	{
		if (is_magic(p)) //p �迭�� ���� ��������,
		{
			int cost = diff(arr, p); //����� ���ؼ�

			if (ans == -1 || ans > cost) //�ּ����� ��
				ans = cost;
		}

	} while (next_permutation(p.begin(), p.end()));


	cout << ans << '\n';

	return 0;
}
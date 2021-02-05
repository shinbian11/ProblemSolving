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

ll d[35][35];

int main()
{

	/*
	[����] 1010�� : �ٸ� ���� (dp. bottom-up)

	- e.g.) 

	3 5 ���,

O		O
O		O
O		O
		O
		O

	> �� ��Ȳ�ε�, �ٸ��� ���� �����ϸ� �ȵȴٴ� ���� ����ؾ� �Ѵ�.
	
	1. ���� ù��° o�� ������ ù��° o�� �����ߴٴ� �������� ����� �� : 2 4 �� ���� ���
	2. ���� ù��° o�� ������ �ι�° o�� �����ߴٴ� �������� ����� �� : 2 3 �� ���� ���
	3. ���� ù��° o�� ������ ����° o�� �����ߴٴ� �������� ����� �� : 2 2 �� ���� ���

	- 1,2,3�� ��츦 ��� ���ϸ� 3 5 �� ����� ���� �ȴ�!
	- d[3][5] = d[2][4] + d[2][3] + d[2][2]

	�Ϲ�ȭ) a b�� �Է¹޾��� ��, a-1  b-1�� �ٲٰ�, �� �������� b-1�� ��� �����ϸ鼭 (a-1�� �� ������), �׶����� d�� ��� �����ָ� �ȴ�.
	*/

	F_I;

	for (int i = 1; i <= 30; i++)
		d[1][i] = i;

	for (int i = 2; i <= 30; i++)
	{
		for (int j = i; j <= 30; j++)
		{
			int a = i - 1;
			int b = j - 1;
			while (a <= b)
			{

				d[i][j] += d[a][b];
				b -= 1;
			}
		}
	}

	int tc;
	cin >> tc;

	while (tc--)
	{
		int a, b;
		cin >> a >> b;
		cout << d[a][b] << '\n';
	}

	return 0;
}
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

int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int main()
{
	F_I;

	 /*
	 ���� 16956�� : ����� �� (BFS)

	- �Է¹��� ���� ��������, �� �Ѹ����� �����, ��� �ٷ� ������ ��(�Ÿ� 1�� �����¿� ĭ)�� ��ġ�ϰ� ������ , 
	��Ÿ���� ��� �ĵ� �ҿ� �����Ƿ� 0 ���. �װ� �ƴ϶�� �׳� ��ĭ�� ������ ��Ÿ���� �Ĺ����� �ǹǷ� 1 ���.

	- ��ġ�ؾ� �ϴ� ��Ÿ���� �ּ��� ������ ���ϴ� ������ �ƴϴ�! ������ ��ȯ�� �Ѵٸ� ���� �����̴�.
	 */

	int r, c;
	cin >> r >> c;

	vector<string> v(r);

	for (int i = 0; i < r; i++)
		cin >> v[i];

	bool exist = false; //���밡 ��� �ٷ� ������ ������ ������(exist = true), ��Ÿ���� ġ���� �ҿ���� ������, �̷� ���� 0 ���

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (v[i][j] == 'S')
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dir[k][0];
					int ny = j + dir[k][1];
					if (nx >= 0 && nx < r && ny >= 0 && ny < c)
					{
						if (v[nx][ny] == 'W')
						{
							exist = true;
							break;
						}
					}
				}
			}
		}
	}

	if (exist) //�ּ� �� ������ ���밡 �ٷ� �� ������ ���� �����Ƿ�, ��Ÿ���� � ������� ��ġ�ص� ����� ���� �ִ� ������ ������ �� �ִ�.
		cout << 0 << '\n';
	else
	{
		cout << 1 << '\n';

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++) 
			{
				if (v[i][j] == '.')
					cout << 'D';
				else
					cout << v[i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}
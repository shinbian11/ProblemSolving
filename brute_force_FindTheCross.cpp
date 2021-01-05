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


int check[101][101];

int main()
{
	F_I;

	int n, m;
	cin >> n >> m;
	vector<string> s(n);

	for (int i = 0; i < n; i++)
		cin >> s[i];

	vector< tuple<int, int, int> > ans;
	/*
	
	* 16924�� : ���ڰ� ã�� (���Ʈ ����)

	�� ���� ��� ���ڰ��� �߽��̶�� �����ϰ�, �� ������ ���ڰ��� ���� �� ���� ������ �ִ�� ������, ���� 1 �̻��� ���ڰ��� ���� �� ������,
	�� ������ ans ���Ϳ� ��´�.
	���� �߽ɿ��� ���̰� 3�� ���ڰ��� ���� �� �ִٴ� �ǹ̴�, ���̰� 1,2�� ���ڰ��� �ڵ����� ���� �� �ִٴ� �ǹ��̴�. ���� ���,

	....*...
	...**...
	..*****.
	...**...
	....*...
	........

	-> �̷� ��쿡��
	3 4 1
	3 5 2
	3 5 1 �� ���� �� �� ������,

	3 4 1
	3 5 2 �� ���� �� �� �ִ�.

	��, ������ �� �� �ƹ��ų� ��� �ص� �ȴٴ� ����� �����Ƿ�, ���ڰ��� ���� �� �ִ� ��쿣 �� ���ڰ��� ���̰� �ִ밡 �� ������ ��� ����� ���� �ȴ�.

	���� ������ ���ڰ��� ��� ����ؾ� �Ѵٸ�, //***2�� �̶�� ǥ�õ� �κе��� �������ָ� �ȴ�.
	*/

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//***2�� (�� �� �ּ�)
			//int length = 0;
			if (s[i][j] == '*')
			{
				int length = 0;
				for (int k = 1;; k++)
				{
					if (i - k >= 0 && i + k < n && j - k >= 0 && j + k < m) // ���� ���� �־�� ����.
					{
						if (s[i - k][j] == '*' && s[i + k][j] == '*' && s[i][j - k] == '*' && s[i][j + k] == '*')
						{

							//***2�� (�� �� �ּ�)
							//length = k; //���ڰ��� ���� ����

							//***2�� (�� �κ� �߰�)

							length += 1;
							ans.push_back(make_tuple(i + 1, j + 1, length)); //�������� ���� ���� ���� 1��, ���� ���� ���� 1�� �̶�� �����Ƿ�

							check[i][j] = true;
							check[i - k][j] = true;
							check[i + k][j] = true;
							check[i][j - k] = true;
							check[i][j + k] = true;

							//***2�� (�������)
						}
						else
							break;
					}
					else
						break;
				}
				/*  //***2�� (�� �κ� �ּ�)

				if (length > 0)
				{
					ans.push_back(make_tuple(i + 1, j + 1, length));

					for (int k = 0; k <= length; k++) //���� ���ڰ� �κ��� ��� trueó��!
					{
						check[i - k][j] = true;
						check[i + k][j] = true;
						check[i][j - k] = true;
						check[i][j + k] = true;
					}
				}
				*/

			}

		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '*' && check[i][j] == false) //���������� *�ڸ��� false�� �ִٴ°�, �� �ڸ��� �ش��ϴ� *�� ���ڰ��� �Ͽ�����
				//���Ե� �� ���ٴ� �ǹ��̹Ƿ�, �׷� ���� ���� �� �����Ƿ� -1 ó���Ѵ�.
			{
				cout << -1 << '\n';
				return 0;
			}
		}
	}

	//��ºκ�

	cout << ans.size() << '\n';

	for (int i = 0; i < ans.size(); i++)
	{
		cout << get<0>(ans[i]) << ' ' << get<1>(ans[i]) << ' ' << get<2>(ans[i]) << '\n';
	}

	return 0;
}
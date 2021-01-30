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

char arr[17][17];
int n, m;

int main()
{
	//F_I;
	/*
	[����] 17085�� : ���ڰ� 2�� ���� (���Ʈ ����)
	
	- ������ : ù��° ���ڰ��� �ϴ� �ִ��� ū ũ��� ��Ƴ���, �� ���Ŀ� �ι�° ���ڰ��� �ִ� ũ�⸦ ��� ������ �ϸ� �ȵȴ�.
	 �� ���� ���ڰ��� ũ�⸦ ���ÿ� ������ �Ѵ�.
	 ù��°, �ι�° ���ڰ� �� �� n*m�� matrix�� ��� ���鼭, ������ ���� ������ for�� ���鼭 �������� �Ѵ�.

	 */
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			arr[i][j] = s[j];
	}

	int ans = 0; //���� ��

	//ù��° ���ڰ� (i1, j1, cnt1)
	for (int i1 = 0; i1 < n; i1++)
	{
		for (int j1 = 0; j1 < m; j1++)
		{
			for (int cnt1 = 0;; cnt1++)
			{
				//matrix ������ ����ų�, #�� �ƴϸ� �̵��� �� ����.
				if (i1 - cnt1 * 1 < 0 || i1 + cnt1 * 1 >= n || j1 - cnt1 * 1 < 0 || j1 - cnt1 * 1 >= m) break;
				if (arr[i1 - cnt1 * 1][j1] != '#' || arr[i1 + cnt1 * 1][j1] != '#' || arr[i1][j1 - cnt1 * 1] != '#' || arr[i1][j1 + cnt1 * 1] != '#') break;
			
				//���ڰ� �ΰ��� ��ġ�� �ȵǴϱ�! �ϴ� * ǥ�÷� �س���!
				arr[i1 - cnt1 * 1][j1] = '*';
				arr[i1 + cnt1 * 1][j1] = '*';
				arr[i1][j1 - cnt1 * 1] = '*';
				arr[i1][j1 + cnt1 * 1] = '*';
				
				//�ι�° ���ڰ� (i2, j2, cnt2) : ù��° ���ڰ��� ��Ƴ�����, �ι�° ���ڰ��� �ִ� ũ�⸦ ���Ѵ�.
				for (int i2 = 0; i2 < n; i2++)
				{
					for (int j2 = 0; j2 < m; j2++)
					{
						for (int cnt2 = 0;; cnt2++)
						{
							//matrix ������ ����ų�, #�� �ƴϸ� �̵��� �� ����.
							if (i2 - cnt2 * 1 < 0 || i2 + cnt2 * 1 >= n || j2 - cnt2 * 1 < 0 || j2 - cnt2 * 1 >= m) break;
							if (arr[i2 - cnt2 * 1][j2] != '#' || arr[i2 + cnt2 * 1][j2] != '#' || arr[i2][j2 - cnt2 * 1] != '#' || arr[i2][j2 + cnt2 * 1] != '#') break;
						
							//������ ��츶��, �׶����� ������ ����� ���ؼ� �ִ밪�� �����Ѵ�.
							int tmp = (1 + 4 * cnt1) * (1 + 4 * cnt2);

							if (ans < tmp)
								ans = tmp;
							
						}
					}
				}
			}

			//ù��° ���ڰ����� �ӽ������� * ǥ�� �س��� �κ��� # ǥ�÷� ��������.
			for (int cnt1 = 0;; cnt1++)
			{
				if (i1 - cnt1 * 1 < 0 || i1 + cnt1 * 1 >= n || j1 - cnt1 * 1 < 0 || j1 - cnt1 * 1 >= m) break;
				if (arr[i1 - cnt1 * 1][j1] != '*' || arr[i1 + cnt1 * 1][j1] != '*' || arr[i1][j1 - cnt1 * 1] != '*' || arr[i1][j1 + cnt1 * 1] != '*') break;

				arr[i1 - cnt1 * 1][j1] = '#';
				arr[i1 + cnt1 * 1][j1] = '#';
				arr[i1][j1 - cnt1 * 1] = '#';
				arr[i1][j1 + cnt1 * 1] = '#';
			}
			
		}
	}

	cout << ans << '\n';

	return 0;
}
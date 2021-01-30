#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

char arr[17][17];
int n, m;

int main()
{
	//F_I;
	/*
	[백준] 17085번 : 십자가 2개 놓기 (브루트 포스)
	
	- 주의점 : 첫번째 십자가를 일단 최대한 큰 크기로 잡아놓고, 그 이후에 두번째 십자가의 최대 크기를 잡는 식으로 하면 안된다.
	 그 둘의 십자가의 크기를 동시에 따져야 한다.
	 첫번째, 두번째 십자가 둘 다 n*m의 matrix를 모두 돌면서, 각각에 대해 일일히 for문 돌면서 따져봐야 한다.

	 */
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			arr[i][j] = s[j];
	}

	int ans = 0; //최종 답

	//첫번째 십자가 (i1, j1, cnt1)
	for (int i1 = 0; i1 < n; i1++)
	{
		for (int j1 = 0; j1 < m; j1++)
		{
			for (int cnt1 = 0;; cnt1++)
			{
				//matrix 범위를 벗어나거나, #이 아니면 이동할 수 없다.
				if (i1 - cnt1 * 1 < 0 || i1 + cnt1 * 1 >= n || j1 - cnt1 * 1 < 0 || j1 - cnt1 * 1 >= m) break;
				if (arr[i1 - cnt1 * 1][j1] != '#' || arr[i1 + cnt1 * 1][j1] != '#' || arr[i1][j1 - cnt1 * 1] != '#' || arr[i1][j1 + cnt1 * 1] != '#') break;
			
				//십자가 두개는 겹치면 안되니까! 일단 * 표시로 해놓기!
				arr[i1 - cnt1 * 1][j1] = '*';
				arr[i1 + cnt1 * 1][j1] = '*';
				arr[i1][j1 - cnt1 * 1] = '*';
				arr[i1][j1 + cnt1 * 1] = '*';
				
				//두번째 십자가 (i2, j2, cnt2) : 첫번째 십자가를 잡아놨을때, 두번째 십자가의 최대 크기를 구한다.
				for (int i2 = 0; i2 < n; i2++)
				{
					for (int j2 = 0; j2 < m; j2++)
					{
						for (int cnt2 = 0;; cnt2++)
						{
							//matrix 범위를 벗어나거나, #이 아니면 이동할 수 없다.
							if (i2 - cnt2 * 1 < 0 || i2 + cnt2 * 1 >= n || j2 - cnt2 * 1 < 0 || j2 - cnt2 * 1 >= m) break;
							if (arr[i2 - cnt2 * 1][j2] != '#' || arr[i2 + cnt2 * 1][j2] != '#' || arr[i2][j2 - cnt2 * 1] != '#' || arr[i2][j2 + cnt2 * 1] != '#') break;
						
							//가능한 경우마다, 그때마다 각각의 사이즈를 구해서 최대값을 갱신한다.
							int tmp = (1 + 4 * cnt1) * (1 + 4 * cnt2);

							if (ans < tmp)
								ans = tmp;
							
						}
					}
				}
			}

			//첫번째 십자가에서 임시적으로 * 표시 해놓은 부분을 # 표시로 돌려놓기.
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
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

int arr[4004][4004];
int cnt[4004];

int main()
{
	/*
	
	[����] 17089�� : �� ģ�� (���Ʈ ����)

	- ���� for���� �׳� ������ O(n^3)�� ���ͼ� �ð��ʰ��� ������ ������...
	- �ϴ� ���� for���� ������ (i,j)�� ģ������(�̶� ģ������� �ִ� m���̴�) �϶��� k�� for������ Ž���ϵ��� �۾��� �� ������,
	O(n^2 + m*n) �̹Ƿ� �ð����ѿ� �ɸ��� �ʴ´�.

	*/

	F_I;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;

		//arr[i][j] = 1 :  i�� j�� ģ�������̴�.
		//cnt[i] : i�� ģ�� ��

		arr[s][e] = 1;
		arr[e][s] = 1;
		cnt[s] += 1;
		cnt[e] += 1;
	}

	int ans = -1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 1) //i�� j �� ģ�����
			{
				for (int k = 1; k <= n; k++)
				{
					if (k == i || k == j) continue;
					if (arr[i][k] == 1 && arr[k][j] == 1) //i�� k�� ģ���̰�, k�� j�� ģ�����
					{
						int tmp = cnt[i] + cnt[k] + cnt[j] - 6; //cnt[i]���� k�� j�� �����ϰ�, cnt[k]���� i�� j�� �����ϰ�, cnt[j]���� i�� k�� �����ϴϱ� �� 6�� ����.
						if (ans == -1 || ans > tmp)
							ans = tmp;
					}
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
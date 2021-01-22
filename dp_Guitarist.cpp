//C++

#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 3.1415926535

using namespace std;
typedef long long ll;

int n, s, m;
int arr[104];
bool d[104][1004];

int main()
{
	F_I;

	/*
	[����] 1495�� : ��Ÿ����Ʈ (dp)

	- 0-1������ �ƴ�, ������ �ɰ�� ���� �� �ִ� knapsack(�׸���,dp) �˰���� ������ Ǯ���̴�.

	*/
	
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	d[0][s] = true;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (d[i][j] == false) continue;

			if (j - arr[i] >= 0)
			{
				d[i + 1][j - arr[i]] = true;
			}

			if (j + arr[i] <= m)
			{
				d[i + 1][j + arr[i]] = true;
			}
		}
	}

	int ans = -1;

	for (int i = 0; i <= m; i++)
	{
		if (d[n][i] == true)
		{
			ans = i;
		}
	}

	cout << ans << '\n';

	return 0;
}

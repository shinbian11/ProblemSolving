//C++

#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 3.1415926535

using namespace std;
typedef long long ll;

bool nope[10004][10004];

int main()
{
	F_I;

	/*
	[백준] 2422번 : 한윤정이 이탈리아에 가서 아이스크림을 사먹는데 (brute-force)
	*/
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		//(a,b)쌍 뿐만 아니라 (b,a)쌍도 똑같이 못 먹는 쌍이다.
		nope[a][b] = true;
		nope[b][a] = true; 
	}

	int ans = 0;

	for (int i = 1; i <= n - 2; i++)
	{
		for (int j = i+1; j <= n-1; j++)
		{
			for (int k = j+1; k <= n; k++)
			{
				if (nope[i][j] || nope[j][k] || nope[k][i]) continue;
				ans += 1;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
//C++

#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 3.1415926535

using namespace std;
typedef long long ll;

int n, s, m;
int arr[104];
bool d[104][1004];

void go(int x, int y)
{

	if (x > n)
		return;

	if (d[x][y] == true)
		return;

	d[x][y] = true;

	if (y - arr[x] >= 0)
	{
		go(x + 1, y - arr[x]);
	}
	if (y + arr[x] <= m)
	{
		go(x + 1, y + arr[x]);
	}
	return;

}

int main()
{
	F_I;

	/* 
	백준 1495번 : 기타리스트 (dp, Top-down)
	*/

	cin >> n >> s >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	memset(d, false, sizeof(d));

	go(0, s);

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
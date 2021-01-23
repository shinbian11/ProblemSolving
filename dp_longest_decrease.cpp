//C++

#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 3.1415926535

using namespace std;
typedef long long ll;

int main()
{
	F_I;

	/*
	[백준] 11722번 : 가장 긴 감소하는 부분 수열(dp)
	*/

	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> d(n, 1);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i] && d[j] + 1 >= d[i])
				d[i] = d[j] + 1;
		}
	}

	int ans = -1e9;

	for (int i = 0; i < n; i++)
	{
		if (ans < d[i])
			ans = d[i];
	}

	cout << ans << '\n';

	return 0;
}
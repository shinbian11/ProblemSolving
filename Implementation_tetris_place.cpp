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
	[백준] 3019번 : 테트리스
	- 각 블럭이 회전했을 때 나올 수 있는 모형들을 모두 그려보고, 각 도형이 차지하는 열에 대해서 높이를 따져야 한다.

	*/
	int c, p;
	cin >> c >> p;

	int arr[104];

	for (int i = 1; i <= c; i++)
		cin >> arr[i];

	int ans = 0;

	if (p == 1)
	{
		ans += c;

		for (int i = 1; i < c - 2; i++)
		{
			if ((arr[i] == arr[i + 1]) && (arr[i + 1] == arr[i + 2]) && (arr[i + 2] == arr[i + 3]))
				ans += 1;
		}
	}
	else if (p == 2)
	{
		for (int i = 1; i < c; i++)
		{
			if (arr[i] == arr[i + 1])
				ans += 1;
		}
	}
	else if (p == 3)
	{
		for (int i = 1; i < c - 1; i++)
		{
			if ((arr[i] + 1 == arr[i + 2]) && (arr[i + 1] + 1 == arr[i + 2]))
				ans += 1;
		}
		for (int i = 1; i < c; i++)
		{
			if (arr[i] == arr[i + 1] + 1)
				ans += 1;
		}
	}
	else if (p == 4)
	{
		for (int i = 1; i < c - 1; i++)
		{
			if ((arr[i] == arr[i + 1] + 1) & (arr[i] == arr[i + 2] + 1))
				ans += 1;
		}
		for (int i = 1; i < c; i++)
		{
			if (arr[i] + 1 == arr[i + 1])
				ans += 1;
		}
	}
	else if (p == 5)
	{
		for (int i = 1; i < c - 1; i++)
		{
			if ((arr[i] == arr[i + 1]) && (arr[i + 1] == arr[i + 2]))
			{
				ans += 1;
			}
		}
		for (int i = 1; i < c; i++)
		{
			if (arr[i] == arr[i + 1] + 1)
			{
				ans += 1;
			}
		}
		for (int i = 1; i < c; i++)
		{
			if (arr[i] + 1 == arr[i + 1])
			{
				ans += 1;
			}
		}
		for (int i = 1; i < c - 1; i++)
		{
			if ((arr[i] == arr[i + 1] + 1) & (arr[i + 1] + 1 == arr[i + 2]))
			{
				ans += 1;
			}
		}
	}
	else if (p == 6)
	{
		for (int i = 1; i < c - 1; i++)
		{
			if ((arr[i] == arr[i + 1]) && (arr[i + 1] == arr[i + 2]))
				ans += 1;
		}
		for (int i = 1; i < c; i++)
		{
			if (arr[i] == arr[i + 1] + 2)
				ans += 1;
		}
		for (int i = 1; i < c - 1; i++)
		{
			if ((arr[i] + 1 == arr[i + 1]) & (arr[i] + 1 == arr[i + 2]))
				ans += 1;
		}
		for (int i = 1; i < c; i++)
		{
			if (arr[i] == arr[i + 1])
				ans += 1;
		}
	}
	else if (p == 7)
	{
		for (int i = 1; i < c - 1; i++)
		{
			if ((arr[i] == arr[i + 1]) && (arr[i + 1] == arr[i + 2]))
				ans += 1;
		}
		for (int i = 1; i < c; i++)
		{
			if (arr[i] == arr[i + 1])
				ans += 1;
		}
		for (int i = 1; i < c - 1; i++)
		{
			if ((arr[i] == arr[i + 2] + 1) && (arr[i + 1] == arr[i + 2] + 1))
				ans += 1;
		}
		for (int i = 1; i < c; i++)
		{
			if (arr[i] + 2 == arr[i + 1])
				ans += 1;
		}
	}

	cout << ans << '\n';

	return 0;
}
//C++

#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 3.1415926535

using namespace std;
typedef long long ll;

int d[5004][5004];

int main()
{
	F_I;

	/*
	[백준] 10422번 :  괄호 (dp)
	d[n][L] : 길이가 n인 문자열에서 짝을 이루지 못하는 열린 괄호가 L개인 문자열의 개수

	길이가 n인 문자열에서 맨 마지막 문자가 ( : d[n-1][L-1] > 마지막 ( 는 어짜피 짝을 이루지 못한 열린 괄호인데, 그게 없다면 L은 1 감소
	길이가 n인 문자열에서 맨 마지막 문자가 ) : d[n-1][L+1] > 마지막 ) 는 짝을 이루고 있던 열린 괄호 한개의 짝인데, 그게 없다면 L은 1 증가

	즉, d[n][L] = d[n-1][L-1] + d[n-1][L+1]
	*/

	int mod = 1e9 + 7;
	memset(d, 0, sizeof(d));
	
	d[0][0] = 1;

	for (int i = 1; i <= 5000; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j + 1 <= i)
				d[i][j] += d[i - 1][j + 1];
			if (j - 1 >= 0)
				d[i][j] += d[i - 1][j - 1];
			d[i][j] %= mod;
		}
	}

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		cout << d[n][0] << '\n'; //d[n][0] = 길이가 n인 문자열에서 짝을 짓지 못한 괄호가 0개일때
	}
	return 0;
}
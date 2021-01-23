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
		for (int L = 0; L <= i; L++)
		{
			//L-1, L+1이 범위를 넘어가면 안되니까!
			if (L - 1 >= 0 && L + 1 <= i) //L-1 < 0 이면 배열 탐색 오류이고, L+1 > i이면 이중 for문에서 정의한 L <= i의 정의에 대해 오류니까!
				d[i][L] = d[i - 1][L - 1] + d[i - 1][L + 1];
			else if (L - 1 >= 0 && L + 1 > i)
				d[i][L] = d[i - 1][L - 1];
			else if (L - 1 < 0 && L + 1 <= i)
				d[i][L] = d[i - 1][L + 1];

			d[i][L] %= mod;
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
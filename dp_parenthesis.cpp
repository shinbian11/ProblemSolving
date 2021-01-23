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
	[����] 10422�� :  ��ȣ (dp)
	d[n][L] : ���̰� n�� ���ڿ����� ¦�� �̷��� ���ϴ� ���� ��ȣ�� L���� ���ڿ��� ����

	���̰� n�� ���ڿ����� �� ������ ���ڰ� ( : d[n-1][L-1] > ������ ( �� ��¥�� ¦�� �̷��� ���� ���� ��ȣ�ε�, �װ� ���ٸ� L�� 1 ����
	���̰� n�� ���ڿ����� �� ������ ���ڰ� ) : d[n-1][L+1] > ������ ) �� ¦�� �̷�� �ִ� ���� ��ȣ �Ѱ��� ¦�ε�, �װ� ���ٸ� L�� 1 ����

	��, d[n][L] = d[n-1][L-1] + d[n-1][L+1]
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
		cout << d[n][0] << '\n'; //d[n][0] = ���̰� n�� ���ڿ����� ¦�� ���� ���� ��ȣ�� 0���϶�
	}
	return 0;
}
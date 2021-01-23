//C++

#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 3.1415926535

using namespace std;
typedef long long ll;

int d[62][62][62]; //d[i][j][k] = scv�� ü���� ���� i,j,k�϶� ��� �ı��ϴ� �ּ� Ƚ��

int main()
{
	F_I;

	/*
	[����] 12869�� : ��Ż����ũ(bottom-up) - �����ֽ� doju�� �����մϴ�!!

	- dp ���� : �ϴ� ��ȭ��(d), ����(�ʱ�) ���� (�ٸ� ���� �������� �ʴ��� ���� �ٷ� ���� �� �ִ� ����)�� �����ϱ�!

	(top-down)
	function f(a, b, c, ...):
	# ���� ���ǿ� �ش��Ѵٸ� �ٷ� �� return
	# �̹� ���� ���̶�� ����� �� return (�޸������̼�)
	# �׷��� �ʴٸ� ��ȭ���� ����� ���� ����ϰ� ����

	(bottom-up)
	for ...:  # ��ȭ���� ����ϱ� ���� �ʿ��� ������ �̸� ���Ǿ� �ֵ��� ���� ����
		# ��ȭ���� ����Ͽ� �ٷ� ���
	
	*/

	int n;
	cin >> n;
	vector<int> scv(3, 0);

	for (int i = 0; i < n; i++)
		cin >> scv[i];

	memset(d, -1, sizeof(d));


	vector<int> attack(3);
	attack = { 1,3,9 };

	d[0][0][0] = 0;

	int mx = max({ scv[0],scv[1],scv[2] });

	for (int i = 0; i <= scv[2]; i++)
	{
		for (int j = 0; j <= scv[0]; j++)
		{
			for (int k = 0; k <= scv[1]; k++)
			{
				do
				{

					int one = j - attack[0];
					int two = k - attack[1];
					int three = i - attack[2];

					//scv�� ü���� ���̳ʽ��� �Ǹ� �װ͵� 0���� ����!
					if (one < 0)
						one = 0;
					if (two < 0)
						two = 0;
					if (three < 0)
						three = 0;

					if (d[j][k][i] == -1 || d[j][k][i] > d[one][two][three] + 1)
						d[j][k][i] = d[one][two][three] + 1;

				} while (next_permutation(attack.begin(), attack.end()));
				
			}
		}
	}
	

	cout << d[scv[0]][scv[1]][scv[2]] << '\n';

	return 0;
}
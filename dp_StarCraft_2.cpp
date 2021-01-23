//C++

#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 3.1415926535

using namespace std;
typedef long long ll;

int d[62][62][62]; //d[i][j][k] = scv의 체력이 각각 i,j,k일때 모두 파괴하는 최소 횟수

int main()
{
	F_I;

	/*
	[백준] 12869번 : 뮤탈리스크(bottom-up) - 도움주신 doju님 감사합니다!!

	- dp 문제 : 일단 점화식(d), 기저(초기) 조건 (다른 항을 참조하지 않더라도 답을 바로 정할 수 있는 조건)을 정리하기!

	(top-down)
	function f(a, b, c, ...):
	# 기저 조건에 해당한다면 바로 값 return
	# 이미 계산된 값이라면 저장된 값 return (메모이제이션)
	# 그렇지 않다면 점화식을 사용해 답을 계산하고 저장

	(bottom-up)
	for ...:  # 점화식을 사용하기 위해 필요한 값들이 미리 계산되어 있도록 순서 선택
		# 점화식을 사용하여 바로 계산
	
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

					//scv의 체력이 마이너스가 되면 그것도 0으로 생각!
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
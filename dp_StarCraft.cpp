//C++

#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 3.1415926535

using namespace std;
typedef long long ll;

int d[62][62][62]; //d[i][j][k] = scv의 체력이 각각 i,j,k일때 모두 파괴하는 최소 횟수

int go(int one, int two, int three)
{
	if (one < 0) return go(0, two, three); //체력이 음수라는 건 파괴된 거니까 0으로 표현 가능(배열은 음수 idx가 불가능하니까)
	if (two < 0) return go(one, 0, three); //체력이 음수라는 건 파괴된 거니까 0으로 표현 가능(배열은 음수 idx가 불가능하니까)
	if (three < 0) return go(one, two, 0); //체력이 음수라는 건 파괴된 거니까 0으로 표현 가능(배열은 음수 idx가 불가능하니까)

	if (one == 0 && two == 0 && three == 0) return 0; //모두 파괴!

	int& ans = d[one][two][three];

	if (ans != -1)
		return ans;

	ans = 1e9;

	vector<int> attack(3);
	attack = { 1,3,9 };

	do
	{
		if (ans > go(one - attack[0], two - attack[1], three - attack[2]))
			ans = go(one - attack[0], two - attack[1], three - attack[2]);

	} while (next_permutation(attack.begin(), attack.end())); //조합

	ans += 1; // go(one - attack[0], two - attack[1], three - attack[2]) 를 만들기 위해서 했던 총 공격 횟수 + 1 해야 됨!

	return ans;
}

int main()
{
	F_I;

	/*
	[백준] 12869번 : 뮤탈리스크 (dp + Top-down)
	*/
	int n;
	cin >> n;
	vector<int> scv(3, 0);
	
	for (int i = 0; i < n; i++) //scv[i]가 0이라는건 이미 파괴되었다는 의미! 즉, n=2라도 한개는 그냥 0으로 넣어놓으면 된다.
		cin >> scv[i];

	memset(d, -1, sizeof(d));

	cout << go(scv[0], scv[1], scv[2]) << '\n';


	return 0;
}
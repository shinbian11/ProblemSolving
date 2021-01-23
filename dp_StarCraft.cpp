//C++

#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 3.1415926535

using namespace std;
typedef long long ll;

int d[62][62][62]; //d[i][j][k] = scv�� ü���� ���� i,j,k�϶� ��� �ı��ϴ� �ּ� Ƚ��

int go(int one, int two, int three)
{
	if (one < 0) return go(0, two, three); //ü���� ������� �� �ı��� �Ŵϱ� 0���� ǥ�� ����(�迭�� ���� idx�� �Ұ����ϴϱ�)
	if (two < 0) return go(one, 0, three); //ü���� ������� �� �ı��� �Ŵϱ� 0���� ǥ�� ����(�迭�� ���� idx�� �Ұ����ϴϱ�)
	if (three < 0) return go(one, two, 0); //ü���� ������� �� �ı��� �Ŵϱ� 0���� ǥ�� ����(�迭�� ���� idx�� �Ұ����ϴϱ�)

	if (one == 0 && two == 0 && three == 0) return 0; //��� �ı�!

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

	} while (next_permutation(attack.begin(), attack.end())); //����

	ans += 1; // go(one - attack[0], two - attack[1], three - attack[2]) �� ����� ���ؼ� �ߴ� �� ���� Ƚ�� + 1 �ؾ� ��!

	return ans;
}

int main()
{
	F_I;

	/*
	[����] 12869�� : ��Ż����ũ (dp + Top-down)
	*/
	int n;
	cin >> n;
	vector<int> scv(3, 0);
	
	for (int i = 0; i < n; i++) //scv[i]�� 0�̶�°� �̹� �ı��Ǿ��ٴ� �ǹ�! ��, n=2�� �Ѱ��� �׳� 0���� �־������ �ȴ�.
		cin >> scv[i];

	memset(d, -1, sizeof(d));

	cout << go(scv[0], scv[1], scv[2]) << '\n';


	return 0;
}
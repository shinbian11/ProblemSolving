#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

//��ģ ���� ���ؼ� ū������ �����ϱ� >> cmp �Լ��� �̷��Ե� Ŀ���͸���¡�� �Ǵ±���!!
bool cmp(string a, string b)
{
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	//���α׷��ӽ� - ���� ū �� (cmp �Լ� Ŀ���͸���¡)
	string str = "";

	vector<string> ans;
	for (int i = 0; i < numbers.size(); i++)
		ans.push_back(to_string(numbers[i]));

	sort(ans.begin(), ans.end(), cmp);

	if (ans.at(0) == "0") str = "0";
	else
	{
		for (int i = 0; i < ans.size(); i++)
			str += ans[i];
	}
	return str;
}

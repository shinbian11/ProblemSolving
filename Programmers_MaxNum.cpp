#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

//합친 문자 비교해서 큰순으로 정렬하기 >> cmp 함수가 이렇게도 커스터마이징이 되는구나!!
bool cmp(string a, string b)
{
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	//프로그래머스 - 가장 큰 수 (cmp 함수 커스터마이징)
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

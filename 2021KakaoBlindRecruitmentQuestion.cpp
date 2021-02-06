#include <bits/stdc++.h>
using namespace std;

// 2021 KAKAO BLIND RECRUITMENT ���� - �ű� ���̵� ��õ
// ���ڿ��� ���� �Լ��� �̿�� ����! tolower�Լ�, string�� push_back, substr(), empty() ���!
/*
- substr�� ���ؼ�

substr(10) : 10��° �ε������� ������ ���ϰڴ�.
substr(1,5): 1��° �ε������� 5���� ���ϰڴ�. (����! 1��° �ε������� 4��° �ε������� ���ϰڴٰ� �ƴ�!!!!)
*/
string solution(string st) {

	string answer = "";

	//1. �ҹ��ڷ� ��� ���� (tolower �Լ� �̿�!)
	for (char& c : st)
		c = tolower(c);
	
	//2. - , _ , . , ����, ���ĺ� �ҹ��ڸ� ���ڿ��� ����
	for (char c : st)
	{
		if (c != '-' && c != '_' && c != '.' && !(c - '0' >= 0 && c - '0' <= 9) && !(c - 'a' >= 0 && c - 'a' <= 25))
			continue;
		answer.push_back(c);
	}
	
	//3. �������� ��ħǥ���� 1���� ��ħǥ�� ġȯ (string ���� push_back ����! �����̳� ���� ���� string ���� �����ϰ� �ϱ�!)
	string tmp;
	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == '.')
		{
			tmp.push_back('.');
			while (i < answer.size() && answer[i] == '.') //ù��° ��ħǥ�� ���ڿ��� �־���� ���ӵ� ��ħǥ�� ���������� ��� skip �ϸ� �ѱ��.
				i++;
			i--;
		}
		else tmp.push_back(answer[i]);
	}
	answer = tmp; //���ڿ� ����
	
	//4. ó���̳� ���� ��ħǥ ������ ���� (substr �̿�!)

	if (answer[answer.size() - 1] == '.') answer = answer.substr(0, answer.size() - 1);
	if (answer[0] == '.') answer = answer.substr(1);
	
	//5. �� ���ڿ��̸� a ���̱� (���ڿ��� ������� Ȯ���ϴ� �� : empty() )
	
	if (answer.empty())
		answer += "a"; 

	//6. ���ڿ� ���̰� 16�̻��̸� 15��°������ �ڸ���, �ڸ� ���Ŀ� �� ������ ���ڰ� . �̸� �װ͵� �����ϱ�

	if (answer.size() > 15)
		answer = answer.substr(0, 15);
	if (answer[answer.size() - 1] == '.')
		answer = answer.substr(0, answer.size() - 1);

	while (answer.size() <= 2)
		answer += answer[answer.size() - 1];

	return answer;
}



#include <bits/stdc++.h>
using namespace std;

// 2021 KAKAO BLIND RECRUITMENT 문제 - 신규 아이디 추천
// 문자열에 관한 함수나 이용법 공부! tolower함수, string의 push_back, substr(), empty() 등등!
/*
- substr에 대해서

substr(10) : 10번째 인덱스부터 끝까지 취하겠다.
substr(1,5): 1번째 인덱스부터 5개만 취하겠다. (주의! 1번째 인덱스부터 4번째 인덱스까지 취하겠다가 아님!!!!)
*/
string solution(string st) {

	string answer = "";

	//1. 소문자로 모두 변경 (tolower 함수 이용!)
	for (char& c : st)
		c = tolower(c);
	
	//2. - , _ , . , 숫자, 알파벳 소문자만 문자열에 포함
	for (char c : st)
	{
		if (c != '-' && c != '_' && c != '.' && !(c - '0' >= 0 && c - '0' <= 9) && !(c - 'a' >= 0 && c - 'a' <= 25))
			continue;
		answer.push_back(c);
	}
	
	//3. 연속적인 마침표들은 1개의 마침표로 치환 (string 에도 push_back 가능! 스택이나 벡터 말고 string 으로 간편하게 하기!)
	string tmp;
	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == '.')
		{
			tmp.push_back('.');
			while (i < answer.size() && answer[i] == '.') //첫번째 마침표만 문자열에 넣어놓고 연속된 마침표가 끝날때까지 계속 skip 하며 넘긴다.
				i++;
			i--;
		}
		else tmp.push_back(answer[i]);
	}
	answer = tmp; //문자열 복사
	
	//4. 처음이나 끝에 마침표 있으면 제거 (substr 이용!)

	if (answer[answer.size() - 1] == '.') answer = answer.substr(0, answer.size() - 1);
	if (answer[0] == '.') answer = answer.substr(1);
	
	//5. 빈 문자열이면 a 붙이기 (문자열이 비었는지 확인하는 법 : empty() )
	
	if (answer.empty())
		answer += "a"; 

	//6. 문자열 길이가 16이상이면 15번째까지만 자르고, 자른 이후에 맨 마지막 문자가 . 이면 그것도 삭제하기

	if (answer.size() > 15)
		answer = answer.substr(0, 15);
	if (answer[answer.size() - 1] == '.')
		answer = answer.substr(0, answer.size() - 1);

	while (answer.size() <= 2)
		answer += answer[answer.size() - 1];

	return answer;
}



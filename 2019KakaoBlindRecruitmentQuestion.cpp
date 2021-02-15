#include <bits/stdc++.h>

using namespace std;

// 2019 KAKAO BLIND RECRUITMENT - 오픈채팅방


vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector< pair<string, string> > save;
	//map 사용법 익혀두기! 중요!
	map<string, string> m;

	int n = record.size();
	for (int i = 0; i < n; i++)
	{
		//중요!
		//istringstream 으로 문자열 parsing 하기! 방법 암기하기!
		//getline(istringstream 변수명, 잘라서 저장할 string 저장소, 기준점(delim))
		istringstream s(record[i]);
		string command, id, nickname;
		
		getline(s, command, ' '); //record[i]를 ' ' 전까지만 입력 받아서 command에 저장하겠다는 의미!
		getline(s, id, ' '); //record[i]의 그 다음 부분을 ' ' 전까지만 입력 받아서 id에 저장하겠다는 의미!
		getline(s, nickname, ' '); //record[i]의 그 다음 부분을 ' ' 전까지만 입력 받아서 nickname에 저장하겠다는 의미!
		
		if (command == "Enter") 
		{
			save.push_back(make_pair(command, id));
			m[id] = nickname;
		}
			
		if (command == "Leave")
		{
			save.push_back(make_pair(command, id));
		}
		if (command == "Change")
		{
			m[id] = nickname;
		}
	}

	for (int i = 0; i < save.size(); i++)
	{
		if (save[i].first == "Enter")
			answer.push_back(m[save[i].second] + "님이 들어왔습니다.");
		if (save[i].first == "Leave")
			answer.push_back(m[save[i].second] + "님이 나갔습니다.");
	}
	return answer;
}


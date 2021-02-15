#include <bits/stdc++.h>

using namespace std;

// 2019 KAKAO BLIND RECRUITMENT - ����ä�ù�


vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector< pair<string, string> > save;
	//map ���� �����α�! �߿�!
	map<string, string> m;

	int n = record.size();
	for (int i = 0; i < n; i++)
	{
		//�߿�!
		//istringstream ���� ���ڿ� parsing �ϱ�! ��� �ϱ��ϱ�!
		//getline(istringstream ������, �߶� ������ string �����, ������(delim))
		istringstream s(record[i]);
		string command, id, nickname;
		
		getline(s, command, ' '); //record[i]�� ' ' �������� �Է� �޾Ƽ� command�� �����ϰڴٴ� �ǹ�!
		getline(s, id, ' '); //record[i]�� �� ���� �κ��� ' ' �������� �Է� �޾Ƽ� id�� �����ϰڴٴ� �ǹ�!
		getline(s, nickname, ' '); //record[i]�� �� ���� �κ��� ' ' �������� �Է� �޾Ƽ� nickname�� �����ϰڴٴ� �ǹ�!
		
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
			answer.push_back(m[save[i].second] + "���� ���Խ��ϴ�.");
		if (save[i].first == "Leave")
			answer.push_back(m[save[i].second] + "���� �������ϴ�.");
	}
	return answer;
}


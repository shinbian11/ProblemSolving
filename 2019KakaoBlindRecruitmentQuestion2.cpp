#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<double, int>& a, pair<double, int>& b)
{
    //�������� �������� �������� -> �������� ���ٸ� ���� ��ȣ�� ���������� ����!
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages)
{
    //2019 KAKAO BLIND RECRUITMENT - ������

    vector< pair<double, int> > fail;
    vector<int> answer;

    /* 
    stages�� 1 1 2 3 4 ��� �Ѵٸ�,
    ���� ��� stage 2�� ���� ��������, 1/3 �̴�. 
    �̶� ���ڴ� 2�� �ش��ϴ� ���̰�, (= ���������� ���������� ���� Ŭ�������� ���� �÷��̾��� ��)
    �и�� 2���� ũ�ų� ���� �����̴�. (= ���������� ������ �÷��̾� ��)
     */
    for (int s = 1; s <= N; s++)
    {
        double mother = 0; //�и�
        double kid = 0; //����

        for (int i = 0; i < stages.size(); i++)
        {
            if (stages[i] == s)
                kid++;
            if (stages[i] >= s)
                mother++;
        }

        if (mother == 0) //�и� 0�̸� ���� �� �����Ƿ�
            fail.push_back({ 0,s });
        else
            fail.push_back({ kid / mother,s });
    }

    sort(fail.begin(), fail.end(), cmp);

    for (int i = 0; i < fail.size(); i++)
        answer.push_back(fail[i].second);

    return answer;
}
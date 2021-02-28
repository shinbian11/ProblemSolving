#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<double, int>& a, pair<double, int>& b)
{
    //실패율을 기준으로 내림차순 -> 실패율이 같다면 작은 번호의 스테이지가 먼저!
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages)
{
    //2019 KAKAO BLIND RECRUITMENT - 실패율

    vector< pair<double, int> > fail;
    vector<int> answer;

    /* 
    stages가 1 1 2 3 4 라고 한다면,
    예를 들어 stage 2에 대한 실패율은, 1/3 이다. 
    이때 분자는 2에 해당하는 수이고, (= 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수)
    분모는 2보다 크거나 같은 수들이다. (= 스테이지에 도달한 플레이어 수)
     */
    for (int s = 1; s <= N; s++)
    {
        double mother = 0; //분모
        double kid = 0; //분자

        for (int i = 0; i < stages.size(); i++)
        {
            if (stages[i] == s)
                kid++;
            if (stages[i] >= s)
                mother++;
        }

        if (mother == 0) //분모가 0이면 나눌 수 없으므로
            fail.push_back({ 0,s });
        else
            fail.push_back({ kid / mother,s });
    }

    sort(fail.begin(), fail.end(), cmp);

    for (int i = 0; i < fail.size(); i++)
        answer.push_back(fail[i].second);

    return answer;
}
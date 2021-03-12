#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;

//프로그래머스 - 모의고사 (브루트 포스)

vector<int> solution(vector<int> answers) {

    vector<int> answer;

    vector<int> one = { 1,2,3,4,5 };
    int ones = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        if (one[i % 5] == answers[i]) ones += 1;
    }

    vector<int> two = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int twos = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        if (two[i % 8] == answers[i]) twos += 1;
    }

    vector<int> three = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int threes = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        if (three[i % 10] == answers[i]) threes += 1;
    }

    priority_queue< pi, vector<pi>, greater<pi> > q;
    q.push({ -ones,1 });
    q.push({ -twos,2 });
    q.push({ -threes,3 });


    int ans = -q.top().first;
    int ans_idx = q.top().second;
    answer.push_back(ans_idx);
    q.pop();

    while (!q.empty())
    {
        int com = -q.top().first;
        int idx = q.top().second;
        if (ans == com)
            answer.push_back(idx);
        q.pop();
    }
    return answer;
}
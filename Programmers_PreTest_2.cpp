#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;

//프로그래머스 - 모의고사 (브루트 포스) (두번째 풀이)

vector<int> solution(vector<int> answers) {

    vector<int> answer;

    vector<int> one = { 1,2,3,4,5 };
    vector<int> two = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> three = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    vector<int> arr(3);

    for (int i = 0; i < answers.size(); i++)
    {
        if (one[i % one.size()] == answers[i]) arr[0] += 1;
        if (two[i % two.size()] == answers[i]) arr[1] += 1;
        if (three[i % three.size()] == answers[i]) arr[2] += 1;
    }

    int mx = *max_element(arr.begin(), arr.end()); //최댓값 구해서

    for (int i = 0; i < arr.size(); i++)
    {
        if (mx == arr[i]) //최대값과 같은 번호 모두 push_back하기!
            answer.push_back(i + 1);
    }

    return answer;
}
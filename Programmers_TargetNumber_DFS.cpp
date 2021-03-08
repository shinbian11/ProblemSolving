#include <bits/stdc++.h>

using namespace std;

//프로그래머스 - 타겟 넘버 (DFS)

int total;

void DFS(vector<int> numbers, int target, int sum, int n)
{
    if (n >= numbers.size())
    {
        if (sum == target)
            total += 1;
        return;
    }

    DFS(numbers, target, sum + numbers[n], n + 1);
    DFS(numbers, target, sum - numbers[n], n + 1);
}

int solution(vector<int> numbers, int target) {

    int answer = 0;

    DFS(numbers, target, numbers[0], 1);
    DFS(numbers, target, -numbers[0], 1);

    answer = total;

    return answer;
}
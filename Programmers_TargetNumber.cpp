#include <bits/stdc++.h>

using namespace std;

//프로그래머스 - 타겟 넘버 (비트마스크)

int solution(vector<int> numbers, int target) {

    int size = numbers.size();
    int answer = 0;

    for (int i = 0; i < (1 << size); i++)
    {
        int sum = 0;


        for (int j = 0; j < size; j++)
        {
            if (i & (1 << j))
            {
                numbers[j] *= -1;
            }
        }
        
        for (int k = 0; k < numbers.size(); k++)
        {
            sum += numbers[k];
        }
        
        if (sum == target)
        {
            answer += 1;
        }
       

        for (int j = 0; j < size; j++)
        {
            if (i & (1 << j))
            {
                numbers[j] *= -1;
            }
        }
    }

    return answer;
}
#include <bits/stdc++.h>

using namespace std;

//2018 KAKAO BLIND RECRUITMENT - [1��] �������

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> t;
    char list[2] = { ' ','#' }; //[0]�̸� ��ĭ, [1]�̸� ��

    for (int i = 0; i < arr1.size(); i++)
        t.push_back(arr1[i] | arr2[i]);


    for (int i = 0; i < t.size(); i++)
    {
        string tmp_arr = ""; //�� ���ڿ� �ϳ� ���� ������, ���ڿ� ���ϱ� ���� �ϱ�!
        int idx = 0;
        while (++idx <= n)
        {
            tmp_arr = list[t[i] & 1] + tmp_arr;
            t[i] /= 2;
        }
        answer.push_back(tmp_arr);
    }

    return answer;
}




#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;

// 프로그래머스 : Summer / Winter Coding(~2018) - 스킬트리


int solution(string skill, vector<string> skill_trees) {

    vector<pi> sk;
    for (int i = 0; i < skill.length(); i++)
    {
        sk.push_back({ skill[i] - 'A',i + 1 });
    }
   
    int answer = 0;
    vector<int> ans;

    for (int i = 0; i < skill_trees.size(); i++)
    {
        ans.clear();

        for (int idx = 0; idx < skill_trees[i].length(); idx++)
        {
            int r = skill_trees[i][idx] - 'A';
            for (int k = 0; k < sk.size(); k++)
            {
                if (sk[k].first == r)
                {
                    ans.push_back(sk[k].second);
                }
            }
        }

        bool flag = true;

        if (ans.empty())
        {
            answer += 1;
            continue;
        }
        if (ans[0] != 1)
            flag = false;

        for (int idx = 1; idx < ans.size(); idx++)
        {
            if (ans[idx] - ans[idx - 1] != 1)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            answer += 1;
        }
    }
    return answer;
}
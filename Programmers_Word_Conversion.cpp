#include <string>
#include <vector>

using namespace std;
int answer = 1000; //초기값

//프로그래머스 - 단어 변환 (DFS)

int diff(string str, string word) //문자열 str 과 word의 다른 단어의 개수를 찾는 함수
{
    int cnt = 0;
    int len = str.length();

    for (int i = 0; i < len; i++)
    {
        if (str[i] != word[i])
            cnt += 1;
    }

    return cnt;
}

void dfs(string begin, string target, vector<string>& words, vector<bool>& visited, int cnt)
{
    int size = words.size();

    for (int i = 0; i < size; i++)
    {
        if (!visited[i] && diff(begin, words[i]) == 1)
        {

            if (words[i] == target) //탈출 조건
            {
                if (answer > cnt + 1) //최소 값 비교하기!
                {
                    answer = cnt + 1;
                    return;
                }
            }

            visited[i] = true;
            dfs(words[i], target, words, visited, cnt + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {

    vector<bool> visited(100, false);

    int cnt = 0;

    dfs(begin, target, words, visited, cnt);

    if (answer != 1000)
        return answer;
    else //answer 갱신이 한번도 되지 않았다 => target을 찾은 적이 없다 => 0을 반환
        return 0;
}
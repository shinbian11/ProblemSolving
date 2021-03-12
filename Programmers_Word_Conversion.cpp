#include <string>
#include <vector>

using namespace std;
int answer = 1000; //�ʱⰪ

//���α׷��ӽ� - �ܾ� ��ȯ (DFS)

int diff(string str, string word) //���ڿ� str �� word�� �ٸ� �ܾ��� ������ ã�� �Լ�
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

            if (words[i] == target) //Ż�� ����
            {
                if (answer > cnt + 1) //�ּ� �� ���ϱ�!
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
    else //answer ������ �ѹ��� ���� �ʾҴ� => target�� ã�� ���� ���� => 0�� ��ȯ
        return 0;
}
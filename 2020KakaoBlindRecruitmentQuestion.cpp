#include <bits/stdc++.h>

using namespace std;

//2020 KAKAO BLIND RECRUITMENT - ���ڿ� ����

int solution(string s)
{

    if (s.length() == 1) //�Է� ���ڿ� ���̰� 1�̸� ���� �Ұ����̹Ƿ�, ���� 1 �ٷ� ����.
        return 1;

    int answer = 1005; //���ڿ� ������ �ִ밡 1000�̴ϱ�.

    int sum = 0;
    int size = s.length();

    for (int len = 1; len <= size / 2; len++) // ���ϰ��� �ϴ� ������ ����(����).. len�� ������ �߶� �����ϰڴ�.
    {
        int cnt = 1;

        string front = s.substr(0, len); //index 0���� len ����ŭ�� ���� (front)
        string next;
        string ans = "";

        for (int j = len; j < size; j += len)
        {
            next = s.substr(j, len); //index j ���� len����ŭ�� ���� (next)

            if (front == next) //�ݺ��Ǵ� ���ڿ��̸�(�������̸�)
            {
                cnt += 1; //cnt ����
            }
            else //front != next ���
            {
                if (cnt == 1) //������ �ѹ��� �ݺ����� ���� ���ڿ��̸�
                {
                    ans += front; // ���̸� ���ϰ��� �ϴ� ans �迭���ٰ� front ���ڿ��� ���̰�,
                    front = next; // next ���ڿ��� front ���ڿ��� �ǰԲ� �Ѵ�.
                }
                else //�̹� �ݺ��� ���ڿ��̸� 
                {
                    ans += (to_string(cnt) + front); //�ݺ��� Ƚ���� ���ڿ�ȭ ���Ѽ� �ٿ��� �Ѵ�.
                    front = next;
                    cnt = 1; //cnt �� �ٽ� 1�� �ʱ�ȭ
                }
            }


            //������ �κ� ó������� ��.
            //e.g.) len = 1 �̰�, s = ababab�϶�, �� �κ� �ڵ尡 ���ٸ�
            //ans ���� ababa �ۿ� ����� �ʴ´�. (������ ababab ��ܾ� ��!) �� ������ �κп� ���� ����� ó���� �ʼ����̴�!
            if (j + len >= size)
            {
                if (cnt == 1)
                {
                    ans += s.substr(j);
                    break;
                }
                else
                {
                    ans += (to_string(cnt) + front);
                    break;
                }
            }
            
        }

        int tmp = ans.length();

        if (answer > tmp)
            answer = tmp;
    }

    return answer;
}

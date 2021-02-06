#include <bits/stdc++.h>

using namespace std;

//2020 KAKAO BLIND RECRUITMENT - 문자열 압축

int solution(string s)
{

    if (s.length() == 1) //입력 문자열 길이가 1이면 압축 불가능이므로, 길이 1 바로 리턴.
        return 1;

    int answer = 1005; //문자열 길이의 최대가 1000이니까.

    int sum = 0;
    int size = s.length();

    for (int len = 1; len <= size / 2; len++) // 비교하고자 하는 문자의 개수(간격).. len개 단위로 잘라서 압축하겠다.
    {
        int cnt = 1;

        string front = s.substr(0, len); //index 0부터 len 개만큼만 추출 (front)
        string next;
        string ans = "";

        for (int j = len; j < size; j += len)
        {
            next = s.substr(j, len); //index j 부터 len개만큼만 추출 (next)

            if (front == next) //반복되는 문자열이면(압축대상이면)
            {
                cnt += 1; //cnt 증가
            }
            else //front != next 라면
            {
                if (cnt == 1) //이전에 한번도 반복되지 않은 문자열이면
                {
                    ans += front; // 길이를 구하고자 하는 ans 배열에다가 front 문자열을 붙이고,
                    front = next; // next 문자열이 front 문자열이 되게끔 한다.
                }
                else //이미 반복된 문자열이면 
                {
                    ans += (to_string(cnt) + front); //반복된 횟수도 문자열화 시켜서 붙여야 한다.
                    front = next;
                    cnt = 1; //cnt 는 다시 1로 초기화
                }
            }


            //마지막 부분 처리해줘야 함.
            //e.g.) len = 1 이고, s = ababab일때, 밑 부분 코드가 없다면
            //ans 에는 ababa 밖에 담기지 않는다. (원래는 ababab 담겨야 함!) 즉 마지막 부분에 대한 깔끔한 처리가 필수적이다!
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

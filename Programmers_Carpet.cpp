#include <bits/stdc++.h>

using namespace std;

// 프로그래머스 - 완전 탐색 - 카펫
// 두 미지수를 구해야 할 때, 이중 for문이 아니라 반복문 하나로 하는 법

vector<int> solution(int brown, int yellow) {

    vector<int> answer;
    int w, h;

    // w와 h를 찾기 위해서 이중 for문 돌려도 조건만 잘 설정하면 시간초과 안남!
    // 하지만 이렇게 한 미지수(여기서는 w)에 대해서 식을 정리한 뒤,
    // h에 가장 작은 수를 넣고 밑 방법 대로 하면 while문 하나로도 가능하다.

    //(w-2)*(h-2) == red이고, brown+red == w*h인데,
    // 두 식을 조합해서 w에 대해 정리하면  밑처럼 된다.
    w = brown / 2 + 2 - h;

    int len = brown / 2 + 2;

    h = 3; //h가 가능한 최소값은 3이다. (h가 2가 되면 yellow가 0이 되는데, 문제에서 yellow는 1이상이라고 나옴.)
    w = len - 3;

    while (w >= h) //w가 더 커야한다고 문제에 표기
    {
        if (w * h == (brown + yellow))
        {
            answer.push_back(w);
            answer.push_back(h);
            return answer;
        }
        w--;
        h++;
    }

}


// 이중 for문을 이용하여도 가능하긴 하다!

//#include <bits/stdc++.h>
//
//using namespace std;
//
//vector<int> solution(int brown, int yellow) {
//    vector<int> answer;
//
//    for (int i = 2; i <= yellow + 2; i++)
//    {
//        for (int j = 2; j <= yellow + 2; j++)
//        {
//            if ((i - 2) * (j - 2) == yellow && (brown + 4) == 2 * (i + j))
//            {
//                if (i < j)
//                    swap(i, j);
//                answer.push_back(i);
//                answer.push_back(j);
//                return answer;
//            }
//        }
//    }
//
//}


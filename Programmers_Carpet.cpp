#include <bits/stdc++.h>

using namespace std;

// ���α׷��ӽ� - ���� Ž�� - ī��
// �� �������� ���ؾ� �� ��, ���� for���� �ƴ϶� �ݺ��� �ϳ��� �ϴ� ��

vector<int> solution(int brown, int yellow) {

    vector<int> answer;
    int w, h;

    // w�� h�� ã�� ���ؼ� ���� for�� ������ ���Ǹ� �� �����ϸ� �ð��ʰ� �ȳ�!
    // ������ �̷��� �� ������(���⼭�� w)�� ���ؼ� ���� ������ ��,
    // h�� ���� ���� ���� �ְ� �� ��� ��� �ϸ� while�� �ϳ��ε� �����ϴ�.

    //(w-2)*(h-2) == red�̰�, brown+red == w*h�ε�,
    // �� ���� �����ؼ� w�� ���� �����ϸ�  ��ó�� �ȴ�.
    w = brown / 2 + 2 - h;

    int len = brown / 2 + 2;

    h = 3; //h�� ������ �ּҰ��� 3�̴�. (h�� 2�� �Ǹ� yellow�� 0�� �Ǵµ�, �������� yellow�� 1�̻��̶�� ����.)
    w = len - 3;

    while (w >= h) //w�� �� Ŀ���Ѵٰ� ������ ǥ��
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


// ���� for���� �̿��Ͽ��� �����ϱ� �ϴ�!

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


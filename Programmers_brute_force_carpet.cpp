#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int i = 1; i <= yellow; i++) {
        if (yellow % i == 0) { // yellow �� ������ ������ ���ʿ��� �׸� ���� �� �ִ� ����� (����,����) �� ��� ���� ��,
            if (yellow / i >= i) { // ���α��� >= ���� ���� �̹Ƿ�,
                // yellow�� ���� yellow/i, ���� i �� ����� ��,
                int cmpBrownCnt = (yellow / i + 2) * 2 + (i * 2);  // �׶� ���� �� �ִ� brown�� ������ ������,
                if (cmpBrownCnt == brown) { // �� ���� brown ������, �־��� brown�� ������ ��ġ�Ѵٸ� => �� ��찡 ���� ���̴�!!
                    answer.push_back(yellow / i + 2); // ī���� ���� : yellow�� ���� + 2  
                    answer.push_back(i + 2); // ī���� ���� : yellow�� ���� + 2
                    break;
                }
            }
        }
    }
    return answer;
}
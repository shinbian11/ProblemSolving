#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int i = 1; i <= yellow; i++) {
        if (yellow % i == 0) { // yellow 의 개수로 격자의 안쪽에서 네모를 만들 수 있는 경우의 (가로,세로) 를 모두 구한 뒤,
            if (yellow / i >= i) { // 가로길이 >= 세로 길이 이므로,
                // yellow가 가로 yellow/i, 세로 i 의 모양일 때,
                int cmpBrownCnt = (yellow / i + 2) * 2 + (i * 2);  // 그때 나올 수 있는 brown의 개수를 세보고,
                if (cmpBrownCnt == brown) { // 그 때의 brown 개수가, 주어진 brown의 개수가 일치한다면 => 이 경우가 답인 것이다!!
                    answer.push_back(yellow / i + 2); // 카펫의 가로 : yellow의 가로 + 2  
                    answer.push_back(i + 2); // 카펫의 세로 : yellow의 세로 + 2
                    break;
                }
            }
        }
    }
    return answer;
}
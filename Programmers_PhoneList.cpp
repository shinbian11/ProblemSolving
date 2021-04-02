#include <bits/stdc++.h>
using namespace std;

//문자열의 사전식 순서 정렬의 의미 (오름차순 기준)
    //1. 1순위는 첫번째 글자를 사전식 정렬(e.g. {a, d, h})
    //2. 만약 첫번째 글자가 같다면, 그 다음 글자에 대한 사전식 정렬, 그것도 같다면, 또 그 다음 글자에 대한 사전식 정렬....(e.g. {aa, ad, ah})
    //3. 2번까지도 같다면, 길이가 짧은 순서대로(e.g. {aa, ad, ah, az, azz, azzz, azzzzz})

bool solution(vector<string> v) {

    // 프로그래머스 - 전화번호 목록 (해쉬 & 문자열의 사전식 순서 정렬의 의미 에 대해서)

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] == v[i + 1].substr(0, v[i].size())) return false;
    }
    return true;
}

	

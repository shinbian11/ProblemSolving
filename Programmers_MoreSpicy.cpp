#include <bits/stdc++.h>

using namespace std;

//가장 맵지 않은, 두번째로 맵지 않은 음식을 뽑아서 섞은 뒤 큐에 다시 push 하는 행위 반복하면서 그 횟수 체크
//탈출 조건 : 1. 가장 맵지 않은 음식이 K스코빌 이상인 경우 : cnt반환
//탈출 조건 : 2. 음식이 두개 남았는데, 그 두개를 섞어도 K스코빌을 못 넘는 경우 : -1반환

int solution(vector<int> scoville, int K)
{
    int cnt = 0;
    priority_queue< int, vector<int>, greater<int> > pq; //최소 힙 우선순위 큐 

    for (int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);

    while (true)
    {
        int mx_f = pq.top(); pq.pop();  //가장 맵지 않은 음식의 스코빌 지수
        int mx_s = pq.top(); pq.pop(); //두번째로 맵지 않은 음식의 스코빌 지수

        if (mx_f >= K) return cnt; //가장 맵지 않은 음식의 스코빌 지수가 K 스코빌 이상이면 cnt 반환
        else if (pq.empty() && mx_f + mx_s * 2 < K)
            return -1;

        pq.push(mx_f + mx_s * 2);
        cnt += 1; //횟수 += 1
    }
}
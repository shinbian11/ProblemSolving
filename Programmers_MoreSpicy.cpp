#include <bits/stdc++.h>

using namespace std;

//���� ���� ����, �ι�°�� ���� ���� ������ �̾Ƽ� ���� �� ť�� �ٽ� push �ϴ� ���� �ݺ��ϸ鼭 �� Ƚ�� üũ
//Ż�� ���� : 1. ���� ���� ���� ������ K���ں� �̻��� ��� : cnt��ȯ
//Ż�� ���� : 2. ������ �ΰ� ���Ҵµ�, �� �ΰ��� ��� K���ں��� �� �Ѵ� ��� : -1��ȯ

int solution(vector<int> scoville, int K)
{
    int cnt = 0;
    priority_queue< int, vector<int>, greater<int> > pq; //�ּ� �� �켱���� ť 

    for (int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);

    while (true)
    {
        int mx_f = pq.top(); pq.pop();  //���� ���� ���� ������ ���ں� ����
        int mx_s = pq.top(); pq.pop(); //�ι�°�� ���� ���� ������ ���ں� ����

        if (mx_f >= K) return cnt; //���� ���� ���� ������ ���ں� ������ K ���ں� �̻��̸� cnt ��ȯ
        else if (pq.empty() && mx_f + mx_s * 2 < K)
            return -1;

        pq.push(mx_f + mx_s * 2);
        cnt += 1; //Ƚ�� += 1
    }
}
#include <bits/stdc++.h>
using namespace std;

//���ڿ��� ������ ���� ������ �ǹ� (�������� ����)
    //1. 1������ ù��° ���ڸ� ������ ����(e.g. {a, d, h})
    //2. ���� ù��° ���ڰ� ���ٸ�, �� ���� ���ڿ� ���� ������ ����, �װ͵� ���ٸ�, �� �� ���� ���ڿ� ���� ������ ����....(e.g. {aa, ad, ah})
    //3. 2�������� ���ٸ�, ���̰� ª�� �������(e.g. {aa, ad, ah, az, azz, azzz, azzzzz})

bool solution(vector<string> v) {

    // ���α׷��ӽ� - ��ȭ��ȣ ��� (�ؽ� & ���ڿ��� ������ ���� ������ �ǹ� �� ���ؼ�)

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] == v[i + 1].substr(0, v[i].size())) return false;
    }
    return true;
}

	

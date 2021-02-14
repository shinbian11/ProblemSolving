#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> numbers, string hand) {
	//2020 īī�� ���Ͻ� - Ű�е� ������
	string answer = "";

	int arr[4][3] = { {1,2,3},{4,5,6},{7,8,9},{-1,0,-1} }; //�Ÿ� �����ϱ� ����

	int l = -1, r = -1;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) //1,4,7
		{
			l = numbers[i];
			answer += 'L';
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) //3,6,9
		{
			r = numbers[i];
			answer += 'R';
		}
		else //2,5,8,0
		{
			int l_x = -1, l_y = -1;
			int r_x = -1, r_y = -1;
			int number_x = -1, number_y = -1;

			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					if (arr[j][k] == numbers[i]) //���� ��
					{
						number_x = j;
						number_y = k;
					}
					if (arr[j][k] == l) //�޼��� ������ �ִ� ��
					{
						l_x = j;
						l_y = k;
					}
					if (arr[j][k] == r) //�������� ������ �ִ� ��
					{
						r_x = j;
						r_y = k;
					}

				}
			}

			//�Ÿ� ����
			int d1 = abs(l_x - number_x) + abs(l_y - number_y);
			int d2 = abs(r_x - number_x) + abs(r_y - number_y);

			if (d1 < d2) //�޼հ� �� ������
			{
				answer += 'L';
				l = numbers[i];
			}
			else if (d1 > d2) //�����հ� �� ������
			{
				answer += 'R';
				r = numbers[i];
			}
			else //�Ÿ��� ������
			{
				if (hand == "right")
				{
					answer += 'R';
					r = numbers[i];
				}
				else
				{
					answer += 'L';
					l = numbers[i];
				}
			}
		}
	}

	return answer;
}
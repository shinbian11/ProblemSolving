#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	//2019 카카오 개발자 겨울 인턴십 - 크레인 인형뽑기 게임

	int answer = 0;
	int n = board[0].size();
	stack<int> st;
	
	for (int i = 0; i < moves.size(); i++)
	{
		for (int j = 0; j < n; j++)
		{
			int doll = board[j][moves[i] - 1];
			board[j][moves[i] - 1] = 0;

			if (doll != 0)
			{
				if (!st.empty() && st.top() == doll)
				{
					st.pop();
					answer += 2;
				}
				else
				{
					st.push(doll);
				}

				break;
			}
		}
	}

	return answer;
}
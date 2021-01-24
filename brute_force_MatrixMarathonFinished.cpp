//C++

#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int n, m;
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
char v[34][34];

int isinside(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m)
		return 1;
	else
		return 0;
}

int go(int x, int y, int cnt) //x행 y열 자리에서, 방문해야 하는 남은 칸의 개수가 cnt개일때, 모든 칸을 방문하기 위해 필요한 이동 횟수 리턴하는 함수
{
	if (cnt == 0) //모든 칸을 이동했으면
		return 0; //더 이상 이동할 횟수가 0이다

	int ans = -1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		while (isinside(nx, ny) && v[nx][ny] == '.') //nx행 ny열로 이동 할 수 있으면
		{
			v[nx][ny] = '*'; //한번 방문한 곳은 장애물로 바꿈으로써, 다시 갈수 없다는 처리를 한다.
			cnt -= 1;

			//계속 그 방향으로 이동
			nx += dx[i];
			ny += dy[i];
		}

		//e.g.) 오른쪽으로 이동하고, 이동한 후의 위치가 nx=0, ny=5인데, isinside에서 nx행 ny열이 배열을 벗어난 이후라면, 다시 nx=0, ny=4로 돌아와야 한다!
		nx -= dx[i];
		ny -= dy[i];

		if (x != nx || y != ny) //원래 (x,y)에서 조금이라도 이동했다면
		{
			int tmp = go(nx, ny, cnt); //(nx,ny) 행에 대해서도 재귀함수 호출!
			if (tmp != -1)
			{
				if (ans == -1 || ans > tmp + 1)
					ans = tmp + 1;
			}
		}

		//아까전에 빈칸에서 이동할 수 있는 (nx,ny) 칸들을 모두 장애물('*')처리를 했으므로, 다시 돌려놔야 한다.
		while (x != nx || y != ny)
		{
			v[nx][ny] = '.';
			cnt += 1;
			nx -= dx[i];
			ny -= dy[i];
		}
	}

	return ans;

}

int main()
{
	//F_I;

	/*
	[백준] 9944번 : NxM 보드 완주하기 (브루트 포스)
	- go 함수 정의 내리고, 재귀함수 이용하기!
	*/

	int tc = 1;

	while (cin >> n >> m)
	{

		int cnt = 0; //빈칸의 개수

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> v[i][j];

				if (v[i][j] == '.')
					cnt += 1;
			}
		}

		int ans = -1;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (v[i][j] == '.')
				{
					v[i][j] = '*';

					int tmp = go(i, j, cnt - 1); //(i,j) 칸을 바로 윗줄에서, 빈칸 -> 장애물 로 바꿨으므로, cnt도 1 감소

					if (tmp != -1)
					{
						if (ans == -1 || ans > tmp)
							ans = tmp;
					}

					v[i][j] = '.'; //다시 빈칸으로 되돌려 놔야한다.
				}
			}
		}
		cout << "Case " << tc << ": " << ans << '\n';
		tc += 1;
	}

	return 0;
}
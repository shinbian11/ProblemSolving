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

int go(int x, int y, int cnt) //x�� y�� �ڸ�����, �湮�ؾ� �ϴ� ���� ĭ�� ������ cnt���϶�, ��� ĭ�� �湮�ϱ� ���� �ʿ��� �̵� Ƚ�� �����ϴ� �Լ�
{
	if (cnt == 0) //��� ĭ�� �̵�������
		return 0; //�� �̻� �̵��� Ƚ���� 0�̴�

	int ans = -1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		while (isinside(nx, ny) && v[nx][ny] == '.') //nx�� ny���� �̵� �� �� ������
		{
			v[nx][ny] = '*'; //�ѹ� �湮�� ���� ��ֹ��� �ٲ����ν�, �ٽ� ���� ���ٴ� ó���� �Ѵ�.
			cnt -= 1;

			//��� �� �������� �̵�
			nx += dx[i];
			ny += dy[i];
		}

		//e.g.) ���������� �̵��ϰ�, �̵��� ���� ��ġ�� nx=0, ny=5�ε�, isinside���� nx�� ny���� �迭�� ��� ���Ķ��, �ٽ� nx=0, ny=4�� ���ƿ;� �Ѵ�!
		nx -= dx[i];
		ny -= dy[i];

		if (x != nx || y != ny) //���� (x,y)���� �����̶� �̵��ߴٸ�
		{
			int tmp = go(nx, ny, cnt); //(nx,ny) �࿡ ���ؼ��� ����Լ� ȣ��!
			if (tmp != -1)
			{
				if (ans == -1 || ans > tmp + 1)
					ans = tmp + 1;
			}
		}

		//�Ʊ����� ��ĭ���� �̵��� �� �ִ� (nx,ny) ĭ���� ��� ��ֹ�('*')ó���� �����Ƿ�, �ٽ� �������� �Ѵ�.
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
	[����] 9944�� : NxM ���� �����ϱ� (���Ʈ ����)
	- go �Լ� ���� ������, ����Լ� �̿��ϱ�!
	*/

	int tc = 1;

	while (cin >> n >> m)
	{

		int cnt = 0; //��ĭ�� ����

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

					int tmp = go(i, j, cnt - 1); //(i,j) ĭ�� �ٷ� ���ٿ���, ��ĭ -> ��ֹ� �� �ٲ����Ƿ�, cnt�� 1 ����

					if (tmp != -1)
					{
						if (ans == -1 || ans > tmp)
							ans = tmp;
					}

					v[i][j] = '.'; //�ٽ� ��ĭ���� �ǵ��� �����Ѵ�.
				}
			}
		}
		cout << "Case " << tc << ": " << ans << '\n';
		tc += 1;
	}

	return 0;
}
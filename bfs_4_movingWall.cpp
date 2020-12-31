#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����


bool visited[8][8][9]; // visited[x][y][t] : t�� �ڿ� x�� y���� �湮�ߴ��� ���θ� �Ǵ�
int dir[9][2] = { {0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1},{0,0} }; //{0,0} : �� �ڸ��� ������ �ִ� ���

int main()
{
	
	F_I;
	 
	//16954�� ���� : �����̴� �̷� Ż�� (c++)

	vector<string> matrix(8);

	for (int i = 0; i < 8; i++)
	{
		cin >> matrix[i];
	}

	queue< tuple<int, int, int> > q;

	visited[7][0][0] = true;
	q.push(make_tuple(7, 0, 0));

	bool ans = false;

	while (!q.empty())
	{
		int x, y, t;
		tie(x, y, t) = q.front();
		q.pop();

		if (x == 0 && y == 7)
		{
			ans = true; //0�� 7��(���� ������)�� �����ϸ� true�̴�.
			break;
		}

		for (int i = 0; i < 9; i++)
		{

			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			int nt = (int)Min((ll)t + 1, (ll)8);

			if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
			{

				//���� matrix[nx][ny]�� ��ġ�� ���� ��, t�� �Ŀ� �� �ڸ��� ������ �ƴ����� �Ǵ��Ϸ��� matrix[nx-t][ny]�� ������ �ƴ����� ���� �ȴ�!
				//1�ʿ� �� �پ� ���� �������ϱ�, t�� �Ŀ��� ���� t��ŭ �������� ��! matrix[nx][ny]�� �ڸ��� t�� �Ŀ� ���� �� ���Ҵ� matrix[nx-t][ny]�̴�.
				if (nx - t >= 0 && matrix[nx - t][ny] == '#')  //nx�� ny������(���� ��ġ����), t�� �ڿ� ������ ���Ұ� ���̶�� �������δ� �����̸� �ȵȴ�.
					continue;

				//nx�� ny������(���� ��ġ����), t+1�� �ڿ� ������ ���Ұ� ���̶�� �������δ� �����̸� �ȵȴ�.
				//������ ĳ���Ͱ� ���� �����̰� �� ������ ���� �����̴µ�, ���� �� ��ġ�� 7�� 0���̰�, t�� 1�̰�, 5�� 0���� ���̶��
				//1�� �ڿ� ���� 6�� 0���� �����̰� �� ����, 5�� 0���� �ִ� ���� �������ϱ�... �׷��� ������ �� ����! ��, �̶��� ���� �̵� ���Ѵ�.
				if (nx - t - 1 >= 0 && matrix[nx - t - 1][ny] == '#')
					continue;

				if (visited[nx][ny][nt] == false)
				{
					visited[nx][ny][nt] = true;
					q.push(make_tuple(nx, ny, nt));
				}
			}
		}
	}

	if (ans == false)
		cout << 0 << '\n';
	else
		cout << 1 << '\n';

	return 0;
}
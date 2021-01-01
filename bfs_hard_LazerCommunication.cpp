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
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int main()
{

	F_I;
	/*
	- ���� 6087�� : ������ ���
	- ������ bfs ������ �ٸ���, ��ĭ�� ���ư������� +1 �� �ϴ°� �ƴ϶�, ���� ���� �������� �� ������ �����ϴ�. �׶������� ��� ���� ���� �ִ´�.
	- ��ġ�ؾ� �ϴ� �ſ��� ���� (������ ���� ���� ������ Ƚ��(������ ����) - 1)�� ����! (���� ��� ���������� ���������� ���µ� 2���� ��� �����ϸ�, ������ �� 3���� �ʿ��ϰ�,
	  �ſ��� 2���� �ʿ��ϴ�(���� �������� �ʿ��ϴϱ�). ���� ������ �ش��ϴ� ��� �ڸ��� ���� ������ �����ϰ�, ������������ ��(������ ����) - 1 �� �ϸ� ���� ���� ��µȴ�.
	*/
	int n, m;
	
	cin >> m >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int sx, sy, ex, ey;
	sx = sy = ex = ey = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 'C')
			{
				if (sx == -1 && sy == -1) //sx�� sy�� �ʱ�ȭ ���¸�, C�� �ѹ��� �߰����� ���� ��Ȳ�̶�� �ǹ̴ϱ�, ù��° C�� �������̶�� ���ְ�, �������� ������ �־��ش�.
				{
					sx = i;
					sy = j;
				}
				else //�̹� C�� �ѹ� ���� ���¸�, �ι�° C�� �������̶�� ���ְ�, �������� ������ �־��ش�.
				{
					ex = i;
					ey = j;
				}
			}
		}
	}

	queue<pair<int, int>> q;
	vector< vector<int> > b(n, vector<int>(m, -1)); //�Ÿ��� �����ϴ� �迭

	b[sx][sy] = 0;
	q.push(make_pair(sx, sy));
	while (!q.empty())
	{
		int x, y;
		tie(x,y)=q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			while (nx >= 0 && nx < n && ny >= 0 && ny < m) //���� ���� ������ ��� �����ؾ� �ϹǷ�, if���� �ƴ϶� while���̾�� �Ѵ�.
			{
				if (arr[nx][ny] == '*') break;// ���̸� ���� �׸��ϰ� �����ߵ�!

				if (b[nx][ny] == -1)
				{
					b[nx][ny] = b[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
				//nx�� ny�� ���� �����ϰ�, x�� y�� ���� ���� �ʴ´�.
				nx += dir[i][0];
				ny += dir[i][1];
			}
		}
	}
	cout << b[ex][ey] - 1 << '\n';
	return 0;
}
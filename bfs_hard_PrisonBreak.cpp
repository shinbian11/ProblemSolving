#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����


int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };

//x�� y������ �迭 v�� ���� �������� �� ���� ���� �ּ� Ƚ���� ��� �迭�� ���ϴ� �Լ�
vector< vector<int> > bfs(vector<string>& v, int x, int y)
{
	int n = v.size();
	int m = v[0].size();

	vector< vector<int> > dist(n, vector<int>(m));


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dist[i][j] = -1;
		}
	}
	deque<pi> q; 

	q.push_back(make_pair(x, y));
	dist[x][y] = 0;

	while (!q.empty())
	{
		tie(x, y) = q.front();
		q.pop_front();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dir[k][0];
			int ny = y + dir[k][1];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{

				//�� �������� �̵��� �ĺ��� �߿���,
				if (dist[nx][ny] != -1) continue; //�ѹ� �湮�� ���̸� �ȵ�!
				if (v[nx][ny] == '*') continue; //���̸� �ȵ�!

				if (v[nx][ny] == '#') //���̸� Ƚ��+1 �� �ϰ� ���� ��!
				{
					dist[nx][ny] = dist[x][y] + 1;
					q.push_back(make_pair(nx, ny));
				}
				else
				{
					dist[nx][ny] = dist[x][y];
					q.push_front(make_pair(nx, ny));
				}
			}
		}
	}

	return dist; //Ƚ���� ����ִ� �迭�� ����

}

int main()
{
	F_I;
	/*
	9376�� Ż�� : ������ ���Ͽ� ���ؼ� ������ bfs�� ���ϰ�, ���� �ۿ� �ִ� ���������� ����� �ִٰ� ������ �ϰ�
	������ bfs�� ���ؼ� ���� ������ �ּҰ��� ���̴�!
	*/
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m;
		cin >> n >> m;

		vector<string> v(n + 2);

		string padding = "";
		for (int i = 0; i < m + 2; i++)
			padding += ".";

		for (int i = 1; i <= n; i++)
		{
			cin >> v[i];
			v[i] = "." + v[i] + ".";
		}


		v[0] += padding;
		v[n + 1] += padding;

		n += 2;
		m += 2;

		vector< vector<int> > d1 = bfs(v, 0, 0); //�������� ���(������)�� �� 0�� 0���� �ƴϾ �ȴ�!


		int x1 = -1, y1 = -1;
		int x2 = -1, y2 = -1;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (v[i][j] == '$') //������ ã��
				{
					if (x1 == -1 && y1 == -1) //ã�� ������ ù��° �����̶��
					{
						x1 = i;
						y1 = j;
					}
					else //ã�� ������ �ι�° �����̶��
					{
						x2 = i;
						y2 = j;
					}
				}

			}
		}

		vector< vector<int> > d2 = bfs(v, x1, y1);
		vector< vector<int> > d3 = bfs(v, x2, y2);

		int ans = 1e9;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{

				if (d1[i][j] == -1) continue; //*�� �ִ� �����̶�� �� (���� �κ��� ����)

				int sum = (d1[i][j] + d2[i][j] + d3[i][j]);
				if (v[i][j] == '#') sum -= 2;

				if (ans > sum)
					ans = sum;
			}
		}
		cout << ans << '\n';

	}

	return 0;
}
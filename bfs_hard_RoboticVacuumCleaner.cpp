#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector< vector<int> > bfs(vector<string>& arr, int x, int y)
{
	int m = arr[0].length();
	int n = arr.size();
	vector< vector<int> > res(n, vector<int>(m, -1));

	queue<pi> q;
	q.push(make_pair(x, y));
	res[x][y] = 0;

	while (!q.empty())
	{
		int sx, sy;
		tie(sx, sy) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (res[nx][ny] == -1 && arr[nx][ny] != 'x') //�̵��ϰ��� �ϴ� ���� ����('x')�� �̵� ����
				{
					res[nx][ny] = res[sx][sy] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	return res;
}
int main()
{
	/*
	
	[����] 4991�� : �κ� û�ұ� (BFS + ����(permutation))
	
	- ������ ��ġ�� �ٲ��� �ʴ´�.
	- �׷��Ƿ� �κ� û�ұ��� ��ġ�� �������� ��ġ, �׸��� ������ ��ȣ�� �Űܼ� ������ �����س���,
	- �ִܰŸ��� ���� ���Ѵ�.
	
	- ������ ġ��� ������ �߿��ϴ�.
	e.g.) ������ 3���̰�, 1�� ����, 2�� ����, 3�� ������� �ϰ�,
	    �κ� û�ұ⸦ 0�� ���� ��� �����Ѵٸ� (���� �κ��� 0�� ������ �����ص� ġ�� ���� �ִܰŸ��� �տ��� ������ �� ��ġ�� ����)
		0���� ���������� ���� ���ѳ���,
		1->2->3
		1->3->2
		2->1->3
		2->3->1
		3->1->2
		3->2->1
		=> �� 6������ ������ ���� �ִܰŸ��� ���� �޶��� �� �ִ�.
		=> �׷��Ƿ�, ������ ���� ������ �ִܰŸ��� bfs�� ���ؼ� ���س���, �� ���Ŀ� permutation�� ������ �ִ� �Ÿ��� ���� ã�´�.

	*/
	
	while (true)
	{
		int n, m;
		cin >> m >> n;

		if (n == 0 && m == 0)
			return 0;

		vector<string> arr(n);
		vector<pi> dirty(1);

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 'o')
				{
					dirty[0] = make_pair(i, j); //�κ��� 0������
				}
				else if (arr[i][j] == '*') //������ 1�� ����
				{
					dirty.push_back(make_pair(i, j));
				}
			}
		}

		int cnt = dirty.size(); //�κ� + ������ ����
		bool ok = true;
		vector< vector<int> > dist(cnt, vector<int>(cnt)); // dist[i][j] = i��° ������ �ִ� ��ҿ��� j��° ������ �ִ� ��ҷ� �̵��Ҷ��� �ּ� �Ÿ�

		for (int i = 0; i < cnt; i++)
		{
			/*
			i�� ������ ���������� �� bfs�� ���Ѵ�. 
			�������� dirty�� ����ִ� ��� ���� �����ϹǷ�, ������ ���� bfs�� �����ؾ� �Ѵ�.
			
			i�� 0�϶��� bfs�� ������, 0�� �������� ������ ������ ���� ��δ� ����Ǿ�����, 
			���� ��� 1�� �������� 3�� ������ ���� dist[1][3]�� ���� ���� ���� ������ ���� �ʾ����Ƿ�, bfs�� ������ ���� cnt�� �����ؾ� �Ѵ�.
			*/
			vector< vector<int> > res = bfs(arr, dirty[i].first, dirty[i].second); 
			for (int j = 0; j < cnt; j++)
			{
				dist[i][j] = res[dirty[j].first][dirty[j].second]; 
				//(i�� ��������) j�� ������ �̵��ϴ� �ּ� �Ÿ�(== res[dirty[j].first][dirty[j].second]) �� dist[i][j] �� ����Ѵ�.

				if (dist[i][j] == -1) //���࿡ �̵��� �� ���� ������ �ִٸ�, bfs ��ȯ���� �޾��� �� �̹� �� res �迭�� �ش� ��ġ���� -1�� ���� ���̴�. (== dist[i][j]==-1)
				{
					ok = false;
				}
			}
		}

		if (ok == false) // �̵� �� �� ���� ������ �ִٸ� -1 ���
		{
			cout << "-1" << '\n';
			continue;
		}
		else
		{
			int ans = 1e9;
			vector<int> permu(cnt);
			for (int i = 0; i < cnt; i++)
			{
				permu[i] = i;
			}
			
			do
			{
				int sum = dist[0][permu[0]];

				for (int i = 0; i < cnt - 1; i++)
				{
					sum += dist[permu[i]][permu[i + 1]];
				}

				if (ans > sum)
				{
					ans = sum;
				}
				
			} while (next_permutation(permu.begin(), permu.end()));

			/*
			int ans = 1e9;
			vector<int> permu(cnt - 1);
			for (int i = 0; i < cnt-1; i++)
			{
				permu[i] = i+1;
			}

			do
			{
				int sum = dist[0][permu[0]];
				for (int i = 0; i < cnt - 2; i++)
				{
					sum += dist[permu[i]][permu[i + 1]];
				}
				if (ans > sum)
				{
					ans = sum;
				}

			} while (next_permutation(permu.begin(), permu.end()));
			*/
			cout << ans << '\n';
		}
	}
	return 0;
}
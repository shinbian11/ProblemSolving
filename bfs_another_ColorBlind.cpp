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
int n;

int N_ColorBlind(vector<string> &arr) //���ϻ����� �ƴ� ���
{
	vector< vector<int> > visited(n, vector<int>(n, 0));
	queue<pair<int, int>> q;
	int step = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == 0) // �湮���� ���̸�
			{
				step += 1;

				q.push(make_pair(i, j));
				visited[i][j] = 1;
				while (!q.empty())
				{
					int x, y;
					tie(x, y) = q.front();
					q.pop();
					for (int i = 0; i < 4; i++)
					{
						int nx = x + dir[i][0];
						int ny = y + dir[i][1];
						
						if (nx >= 0 && nx < n && ny >= 0 && ny < n && arr[x][y] == arr[nx][ny]) 
							//�����(x�� y��) �� ������(nx�� ny��)�� ���� ���ĺ��϶��� ���ư� �� �ִ�.
						{
							if (visited[nx][ny] == 0)
							{
								visited[nx][ny] = 1;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
	}
	return step;
}
int ColorBlind(vector<string>& arr)
{
	vector< vector<int> > visited(n, vector<int>(n, 0));
	queue<pair<int, int>> q;
	int step = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == 0)
			{
				step += 1;
				q.push(make_pair(i, j));
				visited[i][j] = 1;
				while (!q.empty())
				{
					int x, y;
					tie(x, y) = q.front();
					q.pop();
					for (int i = 0; i < 4; i++)
					{
						int nx = x + dir[i][0];
						int ny = y + dir[i][1];
							if (nx >= 0 && nx < n && ny >= 0 && ny < n)
							{
								if (visited[nx][ny] == 0)
								{
									//���ϻ����� �ƴ� ����� �����(x�� y��) �� ������(nx�� ny��)�� ���� ���ĺ��϶��� ���ư� �� �ִ�.
									//������, ���ϻ����� ����� R�� G�� ���� ���ڷ� ���� ������, �� ó���� �߰������� ���־�� �Ѵ�.
									if ((arr[x][y] == arr[nx][ny]) || (arr[x][y] == 'R' && arr[nx][ny] == 'G') || (arr[x][y] == 'G' && arr[nx][ny] == 'R'))
									{
										visited[nx][ny] = 1;
										q.push(make_pair(nx, ny));
									}
								}
							}
					}
				}
			}
		}
	}
	
	return step;
}
int main()
{
	F_I;

	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << N_ColorBlind(arr) << ' ' << ColorBlind(arr); 
	// ��� N_ColorBlind�Լ��� ColorBlind�Լ��� ������� ���� �Ȱ��� ������, ������ �Լ��� ���� �ʿ� ���� �ϳ��� �Լ��� ��ĥ ���� �ִ�.
	// ���ϻ������� �ƴ����� üũ�ϴ� ���� �ϳ��� ���� ����(���ϻ����� ����� R�� G�� ���� ������ ���)�� �߰����ֱ⸸ �ϸ� �Ǵϱ�!
	
	return 0;
}
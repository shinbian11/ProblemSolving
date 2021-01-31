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

int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs(vector< vector<int> >& copy, vector<pi>& virus) //���� ���� ���ϱ�
{
	
	queue<pi> q;

	for (int i = 0; i < virus.size(); i++)
	{
		int x = virus[i].first;
		int y = virus[i].second;

		q.push(make_pair(x, y));
	}

	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (copy[nx][ny] == 0)
				{
					copy[nx][ny] = copy[x][y]; //2�� ����
					q.push(make_pair(nx, ny));

				}
			}

		}
	}

	int cnt = 0;
	
	//���� ���� ���� ���ϱ�
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (copy[i][j] == 0)
				cnt += 1;
		}
	}

	return cnt;
}

int main()
{
	F_I;

	//[����] 14502�� : ������ (bfs, ���Ʈ ����)

	cin >> n >> m;
	vector<pi> b; //��ĭ ���� ����
	vector<pi> virus; //���̷��� ���� ����

	vector< vector<int> > arr(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 0)
				b.emplace_back(i, j);
			if (arr[i][j] == 2)
				virus.emplace_back(i, j);
		}
	}
	
	

	int size = b.size();
	int ans = -1;

	/*
	- ���� ��ġ �� �� �ִ� �ĺ���, �ٽ� ���� ��� ��ĭ�� �߿��� 3���� ���� ����� �� -> �־��� ��� : 64C3 = 64! / (61! 3!) > �ð� ���� ����!
	��ĭ�� �� ���� ��ġ�� �� ���� ���Ƿ� ���ؼ�, 1 ó�� �س���, �׶����� ���� ������ ũ�⸦ ���� �ִ밪�� ���������� ����Ѵ�.
	*/

	//��ĭ�� �� ���� ��ġ�� �� ���� ���Ʈ ������ ���ϱ�
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			for (int k = j + 1; k < size; k++)
			{
				vector< vector<int> > copy(arr);

				//�� ��ġ�Ѵٰ� ����
				copy[b[i].first][b[i].second] = 1;
				copy[b[j].first][b[j].second] = 1;
				copy[b[k].first][b[k].second] = 1;

				//�׶��� ���� ���� ���ϱ�
				int safe = bfs(copy,virus);

				if (ans < safe)
					ans = safe;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
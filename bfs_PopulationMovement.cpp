#include <bits/stdc++.h>
#include <unordered_set>

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

int arr[54][54];
bool d[54][54];
bool c[54][54];
int n, L, R;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt;
bool flag;

void BFS(int x, int y)
{
	queue<pi> q;
	vector<pi> at; //�̹� �α��̵� �� avg �� �������� ĭ�� ������ ����
	q.push({ x,y });
	at.push_back({ x,y });

	d[x][y] = true;
	
	cnt = 1;
	int sum = 0;
	sum += arr[x][y];

	while (!q.empty())
	{
		
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				int diff = abs(arr[x][y] - arr[nx][ny]);

				if (L <= diff && diff <= R)
				{
					if (d[nx][ny] == false)
					{
						d[nx][ny] = true;
						
						cnt += 1;
						sum += arr[nx][ny];

						q.push({ nx,ny });
						at.push_back({ nx,ny });
					}
					
				}
			}
		}
	}
	if (at.size() > 1)
	{
		int move_avg = sum / cnt;
		flag = true;

		for (int i = 0; i < at.size(); i++)
		{
			arr[at[i].first][at[i].second] = move_avg;
		}
	}

	at.clear();

	
	return;

}
int main()
{
	F_I;
	
	//[����] 16234�� : �α� �̵� (BFS)

	cin >> n >> L >> R;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	
	int move = 0;

	while (true)
	{
		memset(d, false, sizeof(d));
		flag = false; //�̹� �Ͽ� �α� �̵��� �Ͼ���� flag = true�� �ȴ�!

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!d[i][j])
				{
					BFS(i, j);	
				}
			}
		}
	
		if (flag) move += 1; //�α� �̵��� �Ͼ���� move+=1;
		else break;
	}

	
	cout << move << '\n';

	return 0;
}
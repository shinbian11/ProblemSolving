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
int arr[54][54];
int d[54][54];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int ans_res = -1; //���� ��

vector<pi> virus; //���̷����� ���� �� �ִ� ��ġ�� ����

void bfs()
{
	queue<pi> q;

	memset(d, -1, sizeof(d));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 2) //���̷����� ������ ��ġ�Ǿ� �ִ� ����
			{
				d[i][j] = 0;
				q.push(make_pair(i, j));
			}
		}
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
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if (arr[nx][ny] != 1 && d[nx][ny] == -1) //���� �ƴϰ�, ó�� �湮�ϴ� ���̶��
				{
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	int ans = -1e9;

	// d �迭�� ��� ���̷����� ������ ��, ���������� ��� ĭ�� ���̷����� ������ ���� '���� �ð�'�� ���Ѵ�
	// ���� �ƴѵ��� �湮���� ���� ����, �ٽ� ���� ���� ���̶� ���̷����� ������ �� ���� ���̶�� �ǹ��ε�, �׷� ���� �����Ѵٸ� �� ���� �׳� �����ϱ�!
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)  continue; //���� �ƴϾ�� �ϰ�,

			//���� �ƴѵ��� �湮���� ���� ���� �ִٴ� ����, �� ��쿡�� ���̷����� �������� ���ϴ� ĭ�� �����Ѵٴ� �ǹ��̹Ƿ� �� ���� ����.
			//���̷����� ��� ĭ�� ������ ���鸸 ������ ������ �Ѵ�.
			if (d[i][j] == -1) return; //����
			
			if (ans < d[i][j])
				ans = d[i][j];
		}
	}

	if (ans_res == -1 || ans_res > ans) //�������� ��� �� ĭ�� ���̷����� �ְ� �Ǵ� �ּ� �ð����� �Ǵ�
		ans_res = ans;

	return;
}

void permu(int idx, int cnt)
{
	if (idx == virus.size()) //��� ���̷��� ĭ �ĺ��� ���ؼ� ���̷����� ������ ������ �������� �� 
	{
		if (cnt == m) //�������� ���ƾ� �ϴ� ���� M����ŭ ������ ������, 
		{
			bfs(); //bfs�� ���ؼ� �����غ���.
		}
	}
	else //��� ���̷��� ĭ �ĺ��� ���ؼ� ���̷����� ������ ������ ���� �� �������� ���ߴٸ�,
	{
		int x = virus[idx].first;
		int y = virus[idx].second;

		//���̷����� ���� �� �ִ� �ĺ��� ����ִ� ������ idx��° �ڸ��� ���̷����� ������ ��
		arr[x][y] = 2;
		permu(idx + 1, cnt + 1);

		//���̷����� ���� �� �ִ� �ĺ��� ����ִ� ������ idx��° �ڸ��� ���̷����� ���� �ʾ��� ��
		arr[x][y] = 0;
		permu(idx + 1, cnt);
	}
	
	
	return;
}

int main()
{
	F_I;

	//[����] 17141�� : ������ 2 (bfs)
	//���̷����� ���� �� �ִ� ����� �� : 2^M ����. ������ ��쿡 ���� bfs�� �غ���.

	cin >> n >> m;
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				arr[i][j] = 0; //��ĭ���� ���
				virus.emplace_back(i, j); //���̷����� ���� �� �ִ� ��ҵ��� �����鸸 ���� ����
			}
		}
	}

	permu(0, 0);

	cout << ans_res << '\n';

	return 0;
}
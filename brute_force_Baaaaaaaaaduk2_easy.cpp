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

int arr[24][24];
bool visited[24][24];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m;

int bfs()
{
	int ans = 0;

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 2 && visited[i][j] == false) //ó�� �湮�Ǵ�, ������� �ٵϵ� �϶�
			{
				queue<pi> q;
				q.push(make_pair(i, j));
				visited[i][j] = true; //�湮�����ϱ�

				bool dead = true; //�ش� �׷��� ������ ���� �� �ִ� �׷������� �Ǵ�.
				int tmp = 0; //���� �� �ִ� ����� �ٵϵ��� ����. ���������� dead �� true�� ��쿡�� �� ������ �信 �������� ���� �����ȴ�.

				while (!q.empty())
				{
					tmp += 1; //���� ����!

					int x, y;
					tie(x, y) = q.front();
					q.pop();

					for (int i = 0; i < 4; i++)
					{
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (nx >= 0 && nx < n && ny >= 0 && ny < m)
						{
							if (arr[nx][ny] == 2 && visited[nx][ny] == false)  //�ֺ��� �Ǵٸ� ����� �ٵϵ��� �ִٸ�, push �ϱ�!
							{
								visited[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
							if (arr[nx][ny] == 0) //�ֺ��� ��ĭ(0) �� �ϳ��� �ִٸ� => �� �ش� arr[x][y] ������ ������ �׷��� ���� �� �ִ� �׷��� �ƴϴ�.
								dead = false;
						}
					}
				}
				if (dead) //arr[x][y]������ ������ �׷��� ���������ε� ���� �� �ִ� �׷��̸�
				{
					ans += tmp; //�� �׷쿡�� ���� �� �ִ� ����� ���� ������ �����ش�.
				}
			}
		}
	}

	return ans;
}

int main()
{
	F_I;

	//[����] 16988�� : Baaaaaaaaaduk2 (Easy) (���Ʈ ����)
	// �ΰ��� ���� ���� ��ġ�� ���ϴ� ����� �� > NM * NM
	// �ΰ��� ���� ���� ��ġ�� ���� ����, bfs�� ���� ���� �� �ִ� ����� �� ������ ���� ��� > NM
	// �� O((NM)^3) => �ð� ���� ����!

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	int ans = 0;

	for (int i1 = 0; i1 < n; i1++) //ù��° �� 
	{
		for (int j1 = 0; j1 < m; j1++)
		{
			if (arr[i1][j1] != 0) continue; //ù��° ���� ������ �ϴ� ��ġ�� ��ĭ�� �ƴϸ� �ѱ��!

			for (int i2 = 0; i2 < n; i2++) //�ι�° ��
			{
				for (int j2 = 0; j2 < m; j2++)
				{
					if (arr[i2][j2] != 0) continue; //�ι�° ���� ������ �ϴ� ��ġ�� ��ĭ�� �ƴϸ� �ѱ��!

					if (i1 == i2 && j1 == j2) continue; // ù��° ���� ������ �ϴ� ��ġ�� �ι�° ���� ������ �ϴ� ��ġ�� ������ �ȵ�!

					//�� ���� ���� ������ ��
					arr[i1][j1] = 1;
					arr[i2][j2] = 1;

					int tmp = bfs();
					if (ans < tmp)
						ans = tmp;

					//�� ���� ���Ҵ� ���� �ٽ� ���󺹱� ��Ű��!
					arr[i1][j1] = 0;
					arr[i2][j2] = 0;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
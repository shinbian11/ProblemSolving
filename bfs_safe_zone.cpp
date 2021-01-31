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

int n;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };



int main()
{
	F_I;

	//[����] 2468�� : ���� ���� (bfs)

	cin >> n;
	vector< vector<int> > arr(n, vector<int>(n));

	int mx = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (mx < arr[i][j])
				mx = arr[i][j];
		}
	}

	int ans = -1;

	//������ ���� : 0���� �����ؾ� �Ѵ�. ��������, �ƹ� ������ ���� ����� ���� ���� �ִٰ� �����ϱ�!
	for (int k = 0; k <= mx; k++)
	{
		vector< vector<int> > brr(arr); //���纻.

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (brr[i][j] <= k)
				{
					brr[i][j] = 0; //��� �κ��� 0���� ǥ���Ѵ�.
				}
			}
		}

		int group = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (brr[i][j] != 0)
				{
					group += 1; //���� ������ ����

					queue<pi> q;
					q.push(make_pair(i, j));

					brr[i][j] = 0;

					while (!q.empty())
					{
						int a, b;
						tie(a, b) = q.front();
						q.pop();

						for (int k = 0; k < 4; k++)
						{
							int nx = a + dx[k];
							int ny = b + dy[k];

							if (nx >= 0 && nx < n && ny >= 0 && ny < n)
							{
								if (brr[nx][ny] != 0)
								{
									brr[nx][ny] = 0;
									q.push(make_pair(nx, ny));
								}
							}
						}
					}

				}
			}
		}


		if (ans < group)
			ans = group;
	}

	cout << ans << '\n';

	return 0;
}
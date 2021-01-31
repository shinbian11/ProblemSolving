#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int n;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };



int main()
{
	F_I;

	//[백준] 2468번 : 안전 영역 (bfs)

	cin >> n;
	vector< vector<int> > arr(n, vector<int>(n));


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];

		}
	}

	int ans = -1;

	for (int k = 0; k <= 100; k++)
	{
		vector< vector<int> > brr(arr);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (brr[i][j] <= k)
				{
					brr[i][j] = 0;
				}
			}
		}

		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (brr[i][j] != 0)
				{
					cnt += 1;

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


		if (ans < cnt)
			ans = cnt;
	}

	if (ans == -1)
		cout << 1 << '\n';
	else
		cout << ans << '\n';

	return 0;
}
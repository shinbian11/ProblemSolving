#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수


int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int n;

int N_ColorBlind(vector<string> &arr) //적록색약이 아닌 사람
{
	vector< vector<int> > visited(n, vector<int>(n, 0));
	queue<pair<int, int>> q;
	int step = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == 0) // 방문안한 곳이면
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
							//출발지(x행 y열) 과 도착지(nx행 ny열)에 같은 알파벳일때만 나아갈 수 있다.
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
									//적록색약이 아닌 사람은 출발지(x행 y열) 과 도착지(nx행 ny열)에 같은 알파벳일때만 나아갈 수 있다.
									//하지만, 적록색약인 사람은 R과 G는 같은 문자로 보기 때문에, 이 처리도 추가적으로 해주어야 한다.
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
	// 사실 N_ColorBlind함수와 ColorBlind함수는 생김새가 거의 똑같기 때문에, 일일히 함수를 만들 필요 없이 하나의 함수로 합칠 수도 있다.
	// 적록색약인지 아닌지를 체크하는 변수 하나만 만들어서 조건(적록색약인 사람은 R과 G를 같은 것으로 취급)을 추가해주기만 하면 되니까!
	
	return 0;
}
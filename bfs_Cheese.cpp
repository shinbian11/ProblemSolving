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

int n, m;

int arr[104][104];
bool visited[104][104];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };


int main()
{
	F_I;
	
	//[백준] 2636번 : 치즈 (BFS)
	 
	// 치즈 안쪽에 존재할 수도 있는 구멍에 대해서 뭔가 따로 처리를 해주어야 할 것 같지만, 굳이 그러지 않아도 된다.
	// 인접한 주변에 치즈가 있으면 0으로 바꾸어 주고(치즈가 녹았다는 의미), 주변에 0이 있으면 나중에 치즈를 0으로 바꿀 수 있는 공기이므로 큐에 넣어주는 식으로 처리한다.
	// 치즈가 모두 녹기 전까지 반복하며, 한번 BFS 를 돌때마다 그때 그때의 남아있는 치즈 개수를 체크한다.

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	int cnt = 0; //모두 녹기까지 걸리는 시간 체크하는 변수
	int prev = 0; //모두 녹기 직전에 남아있는 치즈조각의 칸 개수 체크하는 변수

	while (true)
	{

		//현재 남아있는 치즈 개수 체크하기

		int cheese = 0; //모두 녹기 직전에 남아있는 치즈조각의 칸 개수 체크하는 변수

		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1) //치즈인 경우
					cheese += 1;
		
			}
		}
		if (cheese == 0) //모두 녹았다면
			break;
		else //아니라면
		{
			prev = cheese; //이번에 남아있는 치즈 개수로 prev를 갱신해주기
			cheese = 0;
		}

		//초기화
		memset(visited, false, sizeof(visited));

		//처음 (0,0)을 push 하면서 시작!
		queue<pi> q;
		q.push(make_pair(0, 0));
		
		while (!q.empty())
		{
			int x, y;
			tie(x, y) = q.front(); q.pop();
			visited[x][y] = true;
			
			for (int k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m)
				{
					if (visited[nx][ny] == false)
					{
						if (arr[nx][ny] == 0) //arr[nx][ny] 가 0이라면, 인접한 치즈를 녹일 수 있는 공기이므로
							q.push(make_pair(nx, ny)); //큐에 push
						if (arr[nx][ny] == 1) // arr[nx][ny]가 치즈일때,
							arr[nx][ny] = 0; // 공기에 의해서 치즈가 녹았으므로, 0으로 바꾸어준다.

						visited[nx][ny] = true;
					}
				}
			}
		}
		cnt += 1;
	}

	cout << cnt << '\n' << prev;

	return 0;
}
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
int d[104][104];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int ans_res = -1; //최종 답

vector<pi> virus; //바이러스의 위치들 저장

void bfs()
{
	queue<pi> q;

	memset(d, -1, sizeof(d));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 3) //바이러스가 활성화 되어있는 칸들
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

				if (arr[nx][ny] != 1 && d[nx][ny] == -1) //이동할 곳이 벽이 아니고, 처음 방문하는 곳일때만! (주의! 비활성화 바이러스로는 이동가능하다)
				{
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	int ans = 0;
	/*

	2 2 2 2
	2 2 2 2
	2 2 1 1
	1 1 1 1

	와 같은 상황에서는, 모든 바이러스를 활성화 시키는 경우에는 답이 0 이 나와야 한다.
	그런데 이때 ans를 처음에 0 이 아니라 -1e9로 초기화 시키는 경우에는 -1e9가 출력됨으로 정답이 될 수 없다.
	반드시 ans를 0으로 초기화시키기.
	*/

	// d 배열에 활성화 된 바이러스가 모두 퍼졌을 때, 최종적으로 모든 칸에 바이러스가 퍼졌을 때의 '최종 시간'을 구한다.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			/*
			arr배열에는
			1. 비활성화 바이러스
			2. 활성화 바이러스
			3. 벽
			4. 빈칸
			- 이렇게 4가지가 존재하는데, 3번의 경우(빈칸) 들 중에서 최대 시간을 구하면 된다!

			다시 말해서,

			- 조건 1 : 벽이 아니어야 하고,
			- 조건 2 : 비활성화 바이러스가 아니어야 한다. (비활성화 바이러스도 바이러스이다! 즉 이미 바이러스가 퍼진 칸이다.)
			- (조건 3) : 활성화 바이러스의 자리는 어짜피 d[i][j]가 0이다. 그러므로 조건 1,2 처럼 걸러낼 필요가 없다.

			if (arr[i][j] == 1)  continue; //벽 (조건 1)
			if (arr[i][j] == 2)  continue; //비활성화 바이러스 (조건 2)

			- 원래는 이렇게 적어도 된다..

			*/

			//그런데 위의 조건 1,2가 귀찮으면, 그냥 arr[i][j] == 0인 경우 만 따져도 된다. ('빈칸'인 경우들만) 
			if (arr[i][j] == 0) //빈칸들 중에서 최대 시간 구하기!
			{
				// 벽이나 활성화/ 비활성화 바이러스가 있는 자리가 아닌데도 불구하고 방문하지 못한 점이 있다는 것은,
				// 이 경우에는 바이러스가 절대 도달하지 못하는 칸이 존재한다는 의미이므로,
				// 이 경우는 제외한다. 바이러스가 모든 칸에 퍼지는 경우들만 가지고 따져야 한다.
				if (d[i][j] == -1) return; // 종료

				if (ans < d[i][j])
					ans = d[i][j];
			}

		}
	}

	if (ans_res == -1 || ans_res > ans) //모든 경우에 대해서 최종 값을 비교하여 갱신
		ans_res = ans;

	return;
}

void permu(int idx, int cnt)
{
	if (idx == virus.size()) //모든 바이러스에 대해 활성화/비활성화 여부를 판단 완료했을 때
	{
		if (cnt == m) //문제에서 활성화 해야 하는 개수 M개만큼 활성화 했을 때만, 
		{
			bfs(); //bfs를 통해서 생각해본다.
		}
	}
	else //모든 바이러스에 대해 활성화/비활성화 여부를 아직 판단 완료하지 못했을 때
	{
		int x = virus[idx].first;
		int y = virus[idx].second;

		//idx번째 바이러스를 활성화 했을 때
		arr[x][y] = 3; //활성화 : 3
		permu(idx + 1, cnt + 1);

		//idx번째 바이러스를 활성화 하지 않았을 때
		arr[x][y] = 2; //비활성화 : 그대로 2
		permu(idx + 1, cnt);
	}


	return;
}

int main()
{
	F_I;

	//[백준] 17142번 : 연구소 3 (bfs) >> 17141번 : 연구소 2와 거의 비슷하다.

	//바이러스가 있는 장소들 중 M개의 바이러스를 활성 상태로 바꾸는 경우의 수 : 2^M 가지

	cin >> n >> m;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				virus.emplace_back(i, j); // 바이러스의 위치 정보 모두 저장
			}
		}
	}

	permu(0, 0);

	cout << ans_res << '\n';

	return 0;
}
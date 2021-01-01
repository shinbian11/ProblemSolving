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
int main()
{

	F_I;
	/*
	- 백준 6087번 : 레이저 통신
	- 기존의 bfs 문제와 다르게, 한칸을 나아갈때마다 +1 씩 하는게 아니라, 벽을 만날 때까지는 쭉 직진이 가능하다. 그때까지는 계속 같은 값을 넣는다.
	- 설치해야 하는 거울의 수는 (도착점 까지 갈떄 직진한 횟수(선분의 개수) - 1)과 같다! (예를 들어 시작점에서 도착점까지 가는데 2번을 꺾어서 가야하면, 직선은 총 3개가 필요하고,
	  거울은 2개가 필요하다(꺾는 구간에서 필요하니까). 같은 직선에 해당하는 모든 자리를 같은 값으로 저장하고, 도착점에서의 값(직선의 개수) - 1 을 하면 최종 답이 출력된다.
	*/
	int n, m;
	
	cin >> m >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int sx, sy, ex, ey;
	sx = sy = ex = ey = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 'C')
			{
				if (sx == -1 && sy == -1) //sx와 sy가 초기화 상태면, C를 한번도 발견하지 못한 상황이라는 의미니까, 첫번째 C를 시작점이라고 해주고, 시작점의 정보를 넣어준다.
				{
					sx = i;
					sy = j;
				}
				else //이미 C가 한번 나온 상태면, 두번째 C를 도착점이라고 해주고, 도착점의 정보를 넣어준다.
				{
					ex = i;
					ey = j;
				}
			}
		}
	}

	queue<pair<int, int>> q;
	vector< vector<int> > b(n, vector<int>(m, -1)); //거리를 저장하는 배열

	b[sx][sy] = 0;
	q.push(make_pair(sx, sy));
	while (!q.empty())
	{
		int x, y;
		tie(x,y)=q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			while (nx >= 0 && nx < n && ny >= 0 && ny < m) //벽을 만날 때까지 계속 직진해야 하므로, if문이 아니라 while문이어야 한다.
			{
				if (arr[nx][ny] == '*') break;// 벽이면 직진 그만하고 나가야됨!

				if (b[nx][ny] == -1)
				{
					b[nx][ny] = b[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
				//nx와 ny의 값만 증가하고, x와 y는 증가 하지 않는다.
				nx += dir[i][0];
				ny += dir[i][1];
			}
		}
	}
	cout << b[ex][ey] - 1 << '\n';
	return 0;
}
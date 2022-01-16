#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

//방법 2 : DFS 아닌 순수 구현법

int n, m, x, y, dir, room;
int v[54][54];
int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };

int turnDirection(int dir) { //왼쪽 방향으로 방향 변경
	switch (dir)
	{
	case 0:
		return 3;
	case 1: 
		return 0;
	case 2:
		return 1;
	case 3:
		return 2;
	}
}
void solution() {
	
	v[x][y] = 100; //청소한 방은 100으로!
	room += 1; //청소한 방 1개 증가
	
	while (true) {

		int tmp_dir = dir;
		int canNotClean = 0;
		bool canClean = false;
		int nd, nx, ny;

		for (int i = 0; i < 4; i++) {
			nd = turnDirection(dir);
			nx = x + dir_x[nd];
			ny = y + dir_y[nd];

			if (v[nx][ny] == 0) { // 이번에 탐색하는 곳이, 청소할 수 있는 방이면
				dir = nd;
				canClean = true;
				break;
			}
			else if (v[nx][ny] == 1 || v[nx][ny] == 100) { // 벽이거나 이미 청소해서, 청소 할 수 없으면
				canNotClean += 1;
				dir = nd;
			}
			
		}

		if (canClean)  // 이번에 탐색하는 곳이, 청소할 수 있는 방이면
		{
			v[nx][ny] = 100;
			room += 1;
		}
		if (canNotClean == 4) { // 4면을 모두 청소할 수 없다면

			// 뒷쪽 방향의 좌표 구하기
			nx = x - dir_x[tmp_dir]; 
			ny = y - dir_y[tmp_dir];

			if (v[nx][ny] == 1) { // 뒷쪽 방향이 벽이라서, 이동할 수 없다면
				cout << room << '\n'; // 이때까지 청소한 방의 개수 출력 후 종료!
				break;
			}
			else { // 뒷쪽 방향으로 이동 할 수 있다면,
				dir = tmp_dir; // 기존의 바라보는 방향은 유지 
			}
		}

		// 좌표 이동
		x = nx;
		y = ny;

	}
}

int main()
{
	F_I;

	cin >> n >> m >> x >> y >> dir;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	solution();

	return 0;
}
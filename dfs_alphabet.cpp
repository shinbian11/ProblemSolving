#include <bits/stdc++.h>

#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); // F_I 사용 시 주의) scanf 와 cin 혼합 사용 금지
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

char arr[21][21];
int dfs[21][21];
bool visited[26];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int r, c;
int ans = -1e9;

void DFS(int x, int y, int num) {
	
	ans = max(ans, num);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue; // 맵(보드) 범위를 벗어나면 안됨
		if (visited[arr[nx][ny] - 'A']) continue; // 이미 방문한 알파벳은 안됨

		dfs[nx][ny] = max(dfs[nx][ny], num + 1);

		visited[arr[nx][ny] - 'A'] = true; // (x,y) => (nx,ny) 로 가는 경우
		DFS(nx, ny, num + 1); // (x,y) => (nx,ny) 로 가는 경우에 대한 재귀함수

		// (x,y) => (nx,ny) 로 가는 경우에 대한 재귀함수가 끝난 뒤, (x,y)에서 (nx,ny) 방향이 아닌 인접한 다른 방향의 경로로도 가봐야 하므로, 
		// 해당 위치의 알파벳 (arr[nx][ny])을 방문하지 않은 것으로 변경 (이 작업은 필수!)
		visited[arr[nx][ny] - 'A'] = false;
	}

	return;
}

int main()
{

	F_I;

	// [백준] 1987번 : 알파벳 (BFS 쓰면 메모리 초과되는 경우! DFS 사용하기!)

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < c; j++)
		{
			arr[i][j] = str[j];
		}
	}

	dfs[0][0] = 1;
	visited[arr[0][0] - 'A'] = true; // 이미 방문한 알파벳은 큐나 벡터로 관리하기 보다는, visited[26] 배열로 관리하기!

	DFS(0, 0, 1);

	cout << ans << '\n';

	return 0;

}
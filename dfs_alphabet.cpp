#include <bits/stdc++.h>

#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); // F_I ��� �� ����) scanf �� cin ȥ�� ��� ����
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

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
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue; // ��(����) ������ ����� �ȵ�
		if (visited[arr[nx][ny] - 'A']) continue; // �̹� �湮�� ���ĺ��� �ȵ�

		dfs[nx][ny] = max(dfs[nx][ny], num + 1);

		visited[arr[nx][ny] - 'A'] = true; // (x,y) => (nx,ny) �� ���� ���
		DFS(nx, ny, num + 1); // (x,y) => (nx,ny) �� ���� ��쿡 ���� ����Լ�

		// (x,y) => (nx,ny) �� ���� ��쿡 ���� ����Լ��� ���� ��, (x,y)���� (nx,ny) ������ �ƴ� ������ �ٸ� ������ ��ηε� ������ �ϹǷ�, 
		// �ش� ��ġ�� ���ĺ� (arr[nx][ny])�� �湮���� ���� ������ ���� (�� �۾��� �ʼ�!)
		visited[arr[nx][ny] - 'A'] = false;
	}

	return;
}

int main()
{

	F_I;

	// [����] 1987�� : ���ĺ� (BFS ���� �޸� �ʰ��Ǵ� ���! DFS ����ϱ�!)

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
	visited[arr[0][0] - 'A'] = true; // �̹� �湮�� ���ĺ��� ť�� ���ͷ� �����ϱ� ���ٴ�, visited[26] �迭�� �����ϱ�!

	DFS(0, 0, 1);

	cout << ans << '\n';

	return 0;

}
#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

//��� 2 : DFS �ƴ� ���� ������

int n, m, x, y, dir, room;
int v[54][54];
int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };

int turnDirection(int dir) { //���� �������� ���� ����
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
	
	v[x][y] = 100; //û���� ���� 100����!
	room += 1; //û���� �� 1�� ����
	
	while (true) {

		int tmp_dir = dir;
		int canNotClean = 0;
		bool canClean = false;
		int nd, nx, ny;

		for (int i = 0; i < 4; i++) {
			nd = turnDirection(dir);
			nx = x + dir_x[nd];
			ny = y + dir_y[nd];

			if (v[nx][ny] == 0) { // �̹��� Ž���ϴ� ����, û���� �� �ִ� ���̸�
				dir = nd;
				canClean = true;
				break;
			}
			else if (v[nx][ny] == 1 || v[nx][ny] == 100) { // ���̰ų� �̹� û���ؼ�, û�� �� �� ������
				canNotClean += 1;
				dir = nd;
			}
			
		}

		if (canClean)  // �̹��� Ž���ϴ� ����, û���� �� �ִ� ���̸�
		{
			v[nx][ny] = 100;
			room += 1;
		}
		if (canNotClean == 4) { // 4���� ��� û���� �� ���ٸ�

			// ���� ������ ��ǥ ���ϱ�
			nx = x - dir_x[tmp_dir]; 
			ny = y - dir_y[tmp_dir];

			if (v[nx][ny] == 1) { // ���� ������ ���̶�, �̵��� �� ���ٸ�
				cout << room << '\n'; // �̶����� û���� ���� ���� ��� �� ����!
				break;
			}
			else { // ���� �������� �̵� �� �� �ִٸ�,
				dir = tmp_dir; // ������ �ٶ󺸴� ������ ���� 
			}
		}

		// ��ǥ �̵�
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
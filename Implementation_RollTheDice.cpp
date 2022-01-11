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


// �̵��� ���� ( 1 ~ 4)
// 1 : ��
// 2 : ��
// 3 : ��
// 4 : ��

// Ǯ�� 
/*
 STEP 1 : �̵����� �Է¹ް� -> �Է¹��� ��� �̵����� �� ���� ������� üũ -> ����� �ʴ´ٸ� ������ �̵���Ű��

 STEP 2 : �̵��� ĭ�� ���� �ִ� ���� 0�̸� -> �ֻ����� �ٴڸ鿡 ���� �ִ� ���� ĭ�� ����
		  �̵��� ĭ�� ���� �ִ� ���� 0�� �ƴϸ� -> ĭ�� ���� �ִ� ���� �ֻ����� �ٴڸ����� ����ǰ�, ĭ�� ���� �ִ� ���� 0�� ��.

 STEP 3 : �ֻ��� ���鿡 �ִ� �� ���

*/

int n, m, x, y, cmd;
int back, up, front, down, Left, Right; //�ֻ����� 6��
int back_tmp, up_tmp, front_tmp, down_tmp, left_tmp, right_tmp; //�ֻ����� 6�� �ӽ����庻

void Init() {
	back_tmp = back;
	up_tmp = up;
	front_tmp = front;
	down_tmp = down;
	left_tmp = Left;
	right_tmp = Right;
}

void movingEast() {
	back = back_tmp;
	Right = up_tmp;
	front = front_tmp;
	Left = down_tmp;
	up = left_tmp;
	down = right_tmp;
	return;
}
void movingWest() {
	back = back_tmp;
	Left = up_tmp;
	front = front_tmp;
	Right = down_tmp;
	down = left_tmp;
	up = right_tmp;
	return;
}
void movingNorth() {
	down = back_tmp;
	back = up_tmp;
	up = front_tmp;
	front = down_tmp;
	Left = left_tmp;
	Right = right_tmp;
	return;
}
void movingSouth() {
	up = back_tmp;
	front = up_tmp;
	down = front_tmp;
	back = down_tmp;
	Left = left_tmp;
	Right = right_tmp;
	return;
}

// �̵��� ������ ��ǥ�� ���� ������� üũ => �� ���̶�� �׳� ���� & �� ���̶�� �̵��ϱ�
int exceptionCheckAndMove(int number) {

	switch (number)
	{
	case 1: //moving east
		y += 1;
		if (x >= 0 && x < n && y >= 0 && y < m) {
			Init();
			movingEast();
			return true;
		}
		else {
			y -= 1; // ���󺹱�
			return false;
		}
		// break;
	case 2: //moving west
		y -= 1;
		if (x >= 0 && x < n && y >= 0 && y < m) {
			Init();
			movingWest();
			return true;
		}
		else {
			y += 1; // ���󺹱�
			return false;
		}
		// break;
	case 3: //moving north
		x -= 1;
		if (x >= 0 && x < n && y >= 0 && y < m) {
			Init();
			movingNorth();
			return true;
		}
		else {
			x += 1; // ���󺹱�
			return false;
		}
		// break;
	case 4: //moving south
		x += 1;
		if (x >= 0 && x < n && y >= 0 && y < m) {
			Init();
			movingSouth();
			return true;
		}
		else {
			x -= 1; // ���󺹱�
			return false;
		}
		// break;
	} 

}

int main()
{
	F_I;

	cin >> n >> m >> x >> y >> cmd;

	vector< vector<int> > v(n, vector<int>(m));
	vector<int> move(cmd);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < cmd; i++) {

		// STEP 1
		cin >> move[i];
		int cur = move[i]; // �̹��� �̵��� ���� (1 ~ 4)

		if (!exceptionCheckAndMove(cur)) continue; 

		// STEP 2
		if (v[x][y] == 0) {
			v[x][y] = down;
		}
		else {
			down = v[x][y];
			v[x][y] = 0;
		}

		// STEP 3
		cout << up << '\n';
	}
	

	return 0;
}
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

int arr[35][35];
int n;
ll d[35][35][3];

ll go(int x, int y, int move) //move : 1은 우측, 2는 아래, 3은 대각선 아래 방향으로 이동
{
	//종료조건
	if (x == n && y == n) //(n,n)에 도달했다는 방법 들 중 1가지 방법을 찾은 것이므로, 1 반환
		return 1;

	ll ans = 0;

	if (d[x][y][move] != -1) //memoization
		return d[x][y][move];

	if (move == 1)
	{
		if (y + 1 <= n && arr[x][y + 1] == 0)
		{
			ans += go(x, y + 1, 1);
		}
		//대각선으로 이동하려면 세방향 모두 빈칸이어야 한다. 문제 잘 읽기!
		if (x + 1 <= n && y + 1 <= n && arr[x + 1][y] == 0 && arr[x][y + 1] == 0 && arr[x + 1][y + 1] == 0)
		{
			ans += go(x + 1, y + 1, 3);
		}
	}
	if (move == 2)
	{
		if (x + 1 <= n && arr[x + 1][y] == 0)
		{
			ans += go(x + 1, y, 2);
		}
		if (x + 1 <= n && y + 1 <= n && arr[x + 1][y] == 0 && arr[x][y + 1] == 0 && arr[x + 1][y + 1] == 0)
		{
			ans += go(x + 1, y + 1, 3);
		}
	}
	if (move == 3)
	{
		if (y + 1 <= n && arr[x][y + 1] == 0)
		{
			ans += go(x, y + 1, 1);
		}
		if (x + 1 <= n && arr[x + 1][y] == 0)
		{
			ans += go(x + 1, y, 2);
		}
		if (x + 1 <= n && y + 1 <= n && arr[x + 1][y] == 0 && arr[x][y + 1] == 0 && arr[x + 1][y + 1] == 0)
		{
			ans += go(x + 1, y + 1, 3);
		}
	}

	return d[x][y][move] = ans;
}

int main()
{
	//[백준] 17069번 : 파이프 옮기기 2 (브루트 포스 살짝 + dp)
	// 17070번 : 파이프 옮기기 1번에서 조금 더 변형된 문제.. 자료형 모두 long long 으로 바꾸고, d배열 따로 생성하여 dp 기능 추가! 

	//int n;
	cin >> n;

	memset(d, -1, sizeof(d));

	//vector< vector<int> > arr(n+1, vector<int>(n+1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	}

	cout << go(1, 2, 1) << '\n'; //시작점이 (1,2)이고, (1,1)에서 (1,2) 방향으로 이동하니까(오른쪽 방향으로 가니까 세 번째 인자는 1이다)

	return 0;
}
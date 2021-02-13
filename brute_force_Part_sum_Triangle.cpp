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

int arr[500][1000];
int part_sum[500][1000];
int n;

int calc(int x, int y)
{
	int cur = arr[x][y];
	int ans = cur;
	int row = x, n_ly = y, n_ry = y;

	if (y % 2 != 0) // y가 홀수 >> (x,y) 기준으로 삼각형이 아래로 전개
	{
		while (true)
		{
			row += 1;
			n_ly = y;
			n_ry += 2;

			if (row > n || row < 1) break;
			if (n_ly < 1 || n_ry > row * 2 - 1) break;

			cur += (part_sum[row][n_ry] - part_sum[row][n_ly - 1]);

			if (ans < cur)
				ans = cur;
		}
	}
	else // y가 짝수 >> (x,y) 기준으로 삼각형이 위로 전개
	{
		while (true)
		{
			row -= 1;
			n_ly -= 2;
			n_ry = y;

			if (row > n || row < 1) break;
			if (n_ly < 1 || n_ry > row * 2 - 1) break;

			cur += (part_sum[row][n_ry] - part_sum[row][n_ly - 1]);

			if (ans < cur)
				ans = cur;
		}
	}

	return ans;
}

int main()
{
	F_I;

	//[백준] 4902번 : 삼각형의 값 (브루트 포스)
	/*
	e.g.) 부분합에 대해
	4~10까지의 합은? : 1~10까지의 합 - 1~3까지의 합

	- 이 문제에서, 단위 삼각형의 y 좌표가 홀수면 밑으로 뻗어나가는 부분 삼각형을 만들 수 있고,
	- 단위 삼각형의 y 좌표가 짝수면 위로 뻗어나가는 부분 삼각형을 만들 수 있다.
	*/
	int tc = 1;
	while (true)
	{

		cin >> n;
		if (n == 0)
			break;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 2 * i - 1; j++)
			{
				cin >> arr[i][j];
				part_sum[i][j] = part_sum[i][j - 1] + arr[i][j]; //i번째 행의 j번째까지의 부분합 : i번째 행의 j-1번째까지의 부분합 + (i,j)의 수
			}
		}

		int ans = -1000000;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 2 * i - 1; j++)
			{
				int tmp = calc(i, j); // 각각의 삼각형에서 만들 수 있을 때까지 부분 삼각형을 계속 만들어나가면서 넓이 체크를 한다.
				if (ans < tmp)
					ans = tmp;
			}
		}

		cout << tc << ". " << ans << '\n';

		tc += 1;
	}
	return 0;
}
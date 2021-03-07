#include <bits/stdc++.h>
#include <unordered_set>

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

int arr[504][504];
int d[504][504];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n;

/*
d[i][j] : (i,j)에서 시작했을 때 판다가 살 수 있는 최대 일 수(이동할 수 있는 최대 칸 수)
(i,j) -> (x,y) -> ..... -> (끝) 이라고 그림을 그렸을 때 , d[i][j] = d[x][y] + 1 이다.
이때 (x,y)은 3가지 조건을 만족하는 점인데,
조건 1 : (i,j)에서 상하좌우 인접한 칸이어야 한다.
조건 2 : (x,y)가 matrix 범위를 벗어나면 안된다.
조건 3 : arr[i][j]보다 arr[x][y]가 더 큰 값을 가져야 한다. (그래야 욕심쟁이 판다가 이동 할 수 있으니까)
-> 3가지 조건을 만족하는 (x,y)를 찾는게 중요한 포인트이다.
*/
int panda(int i, int j) //(i,j)에서 시작했을 때 판다의 최대 생존 일 수를 반환하는 함수
{
	if (d[i][j] != -1) return d[i][j]; //memoization

	d[i][j] = 1; //이 문제는 판다가 움직일 수 있는 칸의 최대 개수를 구하는 문제이고, (i,j)칸에 있는 것도 1칸으로 인정되므로 1로 초기화한다.

	for (int k = 0; k < 4; k++)
	{
		//조건 1 : 인접한 상하좌우 칸
		int x = i + dx[k];
		int y = j + dy[k];

		//조건 2 : 범위 체크
		if (x >= 0 && x < n && y >= 0 && y < n)
		{
			//조건 3 : arr[i][j]보다 더 큰 수여야 함
			if (arr[i][j] < arr[x][y])
			{
				if (d[i][j] < panda(x, y) + 1) //'최대' 일 수!
					d[i][j] = panda(x, y) + 1;
			}
		}
	}

	return d[i][j];
}

int main()
{
	F_I;
	//[백준] 1937번 : 욕심쟁이 판다 (dp, Top_down)

	//int n;
	cin >> n;

	memset(d, -1, sizeof(d));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	//판다의 시작점을 지정한 것이 아니므로, 모든 칸에 대해서 시작 했을 때의 최대 이동 칸수 (최대 생존 일 수)를 구한다.
	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ans < panda(i, j))
				ans = panda(i, j);
		}
	}

	cout << ans << '\n';

	return 0;
}
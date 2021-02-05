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

ll d[35][35];

int main()
{

	/*
	[백준] 1010번 : 다리 놓기 (dp. bottom-up)

	- e.g.) 

	3 5 라면,

O		O
O		O
O		O
		O
		O

	> 이 상황인데, 다리가 서로 교차하면 안된다는 조건 고려해야 한다.
	
	1. 왼쪽 첫번째 o가 오른쪽 첫번째 o를 연결했다는 가정하의 경우의 수 : 2 4 일 때의 경우
	2. 왼쪽 첫번째 o가 오른쪽 두번째 o를 연결했다는 가정하의 경우의 수 : 2 3 일 때의 경우
	3. 왼쪽 첫번째 o가 오른쪽 세번째 o를 연결했다는 가정하의 경우의 수 : 2 2 일 때의 경우

	- 1,2,3번 경우를 모두 합하면 3 5 의 경우의 수가 된다!
	- d[3][5] = d[2][4] + d[2][3] + d[2][2]

	일반화) a b를 입력받았을 때, a-1  b-1로 바꾸고, 이 오른쪽의 b-1을 계속 감소하면서 (a-1이 될 때까지), 그때마다 d를 계속 더해주면 된다.
	*/

	F_I;

	for (int i = 1; i <= 30; i++)
		d[1][i] = i;

	for (int i = 2; i <= 30; i++)
	{
		for (int j = i; j <= 30; j++)
		{
			int a = i - 1;
			int b = j - 1;
			while (a <= b)
			{

				d[i][j] += d[a][b];
				b -= 1;
			}
		}
	}

	int tc;
	cin >> tc;

	while (tc--)
	{
		int a, b;
		cin >> a >> b;
		cout << d[a][b] << '\n';
	}

	return 0;
}
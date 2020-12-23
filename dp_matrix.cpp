#include <bits/stdc++.h>

//#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// 윗줄 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int a[51][51];
int b[51][51];
int n, m;

void flip(int i, int j) //3 X 3 분량 만큼에 해당하는 모든 부분 뒤집기
{
	for (int x = i; x <= i + 2; x++)
	{
		for (int y = j; y <= j + 2; y++)
		{
			a[x][y] = 1 - a[x][y];
		}
	}
}
int main() 
{
	//F_I; >> scanf랑 cin 동시에 쓸 때는 이거 못 쓴다!! 기억해놓기!
	//int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &b[i][j]);
		}
	}

	int cnt = 0;
	if (n < 3 || m < 3) //가로나 세로나 3이 안되면, 뒤집을 수가 없으므로, 그냥 그 상태에서 모든 원소가 같은지를 판단해야 한다.
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] != b[i][j])
				{
					cout << "-1" << '\n';
					return 0;
				}
			}
		}
		cout << "0" << '\n';
		return 0;
	}
	else
	{
		//A,B의 3 x 3 행렬 각각의 가장 왼쪽 상단의 원소가 다르면 FLIP 한다. 
		//중첩 반복문을 끝내고 나면, 적어도 가로 1 ~ M-2 부분과, 세로 1 ~ N-2 부분은 같아진다. 
		for (int i = 0; i <= n - 3; i++)
		{
			for (int j = 0; j <= m - 3; j++)
			{
				if (a[i][j] != b[i][j])
				{
					flip(i, j);
					++cnt;
				}
			}
		}
		//나머지 부분만 비교해서 그래도 다르면 가망이 없으므로 -1 출력, 아니면 cnt 출력.
		//근데 나머지 부분만 비교하는거나 그냥 전체 비교하는거나 별 차이 없으므로 그냥 전체 비교하기!
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] != b[i][j])
				{
					cout << "-1" << '\n';
					return 0;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
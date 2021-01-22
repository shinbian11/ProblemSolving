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
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int n = 5;
vector< vector<int> > arr(n, vector<int>(n));
set<int> d;

void func(int x, int y, int num, int len)
{
	if (len == 6)
	{
		d.insert(num);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n)
		{
			func(nx, ny, 10 * num + arr[nx][ny], len + 1);
		}
	}

	return;
}

int main()
{
	F_I;
	/*
	[백준] 2210번 : 숫자판 점프 ( 브루트 포스 + 중복 제거)

	- 어렵게 생각할 필요 없다. 인접한 상하좌우로 계속 나아가고, 길이가 6이 되면 자료구조에 저장하고, 중복 제거 이후 길이 출력 하면 되는 간단한 문제이다.
	set을 이용하면 중복 제거가 편리해지므로 set 이용. 재귀함수 이용하여 쉽게 처리 가능하다!4

	*/
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			func(i, j, arr[i][j], 1);
		}
	}

	cout << d.size() << '\n';

	return 0;
}
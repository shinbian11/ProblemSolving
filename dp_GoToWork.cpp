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

int d[51][51][51][4][4];

string st;
int len;

int a;
int b;
int c;

int go(int a, int b, int c, int p1, int p2)
{
	/*
	- [백준] 12969번 : ABC (dp, Top-down) 와 비슷한 문제이다.

	d[a][b][c][p1][p2] : A가 a개, B가 b개, C가 c개 이고, 전날 근무한 사람이 p1, 전전날 근무한 사람이 p2일때의 순서가 존재하면 1, 아니면 0이다.
	
	- 이때 p1,p2 에서 A : 1, B : 2, C: 3이라고 하자.

	 ______p2 p1 : d[a][b][c][p1][p2] 라 한다면,

	 ______p2 p1 a : d[a+1][b][c][a][p1]
	 ______p2 p1 b : p1 != b 이면, d[a][b+1][c][b][p1]
	 ______p2 p1 c : p1 != c 이고, p2 != c 이면, d[a][b][c+1][c][p1]

	*/
	if (a + b + c == 0) //종료조건
	{
		return d[a][b][c][p1][p2] = 1; //순서가 존재한다는 의미!
	}

	if (d[a][b][c][p1][p2] != -1) //memoization
		return d[a][b][c][p1][p2];

	if (a > 0 && go(a - 1, b, c, 1, p1) == 1)
		return d[a][b][c][p1][p2] = 1;
	if (b > 0 && p1 != 2)
	{
		if (go(a, b - 1, c, 2, p1) == 1)
			return d[a][b][c][p1][p2] = 1;
	}
	if (c > 0 && p1 != 3 && p2 != 3)
	{
		if (go(a, b , c-1, 3, p1) == 1)
			return d[a][b][c][p1][p2] = 1;
	}

	return d[a][b][c][p1][p2] = 0;
}

string build(int a, int b, int c, int p1, int p2) //go함수를 통해 존재한다는 사실이 증명되었다면, build 함수를 통해 그 문자열을 만들기!
{
	if (a + b + c == 0)
	{
		return "";
	}

	if (a > 0 && go(a - 1, b, c, 1, p1) == 1)
		return "A" + build(a - 1, b, c, 1, p1);
	if (b > 0 && p1 != 2)
	{
		if (go(a, b - 1, c, 2, p1) == 1)
			return "B" + build(a, b - 1, c, 2, p1);
	}
	if (c > 0 && p1 != 3 && p2 != 3)
	{
		if (go(a, b, c - 1, 3, p1) == 1)
			return "C" + build(a, b, c - 1, 3, p1);
	}

	return "";
}

int main()
{
	//[백준] 14238번 : 출근 기록 (DP, TOP_DOWN)
	
	cin >> st;

	len = st.length();

	for (int i = 0; i < len; i++)
	{
		if (st[i] == 'A')
			a += 1;
		if (st[i] == 'B')
			b += 1;
		if (st[i] == 'C')
			c += 1;
	}

	memset(d, -1, sizeof(d));

	if (go(a,b,c, 0, 0)) 
		cout << build(a, b, c, 0, 0) << '\n';
	else
		cout << -1 << '\n';

	return 0;
}
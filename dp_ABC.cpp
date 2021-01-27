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

int n, k;
int d[34][34][34][(34 * 35) / 2];
char ans[34];

bool go(int idx, int a, int b, int p)
{
	/*
	*
	> d[idx][a][b][p] : 길이가 idx개 이고, A가 a개, B가 b개, C가 idx-a-b개인 문자열이 p개 존재하면 1. 존재하지 않으면 0. 아직 모르면 -1(초기값)

	 ______ : d[idx][a][b][p] 라 한다면,

	 ______a : d[idx+1][a+1][b][p]
	 ______b : d[idx+1][a][b+1][p+a]
	 ______c : d[idx+1][a][b][p+a+b] 이다.

	*/

	if (idx == n) //최종적으로 길이 n의 문자열을 만들었을 때, 
	{
		if (p == k) //만약에 조건에 만족하는 답이 있으면
			return d[idx][a][b][p] = 1; //1 반환 (존재)
		else //없으면
			return  d[idx][a][b][p] = 0; //0 반환 (존재 X)
	}

	if (d[idx][a][b][p] != -1) //memoization
		return d[idx][a][b][p];

	d[idx][a][b][p] = 0;

	ans[idx] = 'A';
	if (go(idx + 1, a + 1, b, p)) return d[idx][a][b][p] = 1; //존재하면 1 대입해서 반환

	ans[idx] = 'B';
	if (go(idx + 1, a, b + 1, p + a)) return d[idx][a][b][p] = 1; //존재하면 1 대입해서 반환

	ans[idx] = 'C';
	if (go(idx + 1, a, b, p + a + b)) return d[idx][a][b][p] = 1; //존재하면 1 대입해서 반환

	return d[idx][a][b][p] = 0; //아니면 1 대입해서 반환
}

int main()
{
	//[백준] 12969번 : ABC (dp, Top-down)
	cin >> n >> k;

	memset(d, -1, sizeof(d));

	if (go(0, 0, 0, 0))
		cout << ans << '\n';
	else
		cout << -1 << '\n';
	return 0;
}
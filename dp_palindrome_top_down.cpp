#include <bits/stdc++.h>
//#include <unordered_set>
//#include <unordered_map>

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

int arr[2004];
int d[2004][2004];

int dp(int i, int j)
{
	if (d[i][j] >= 0) return d[i][j]; //memoization

	if (i == j) //길이 1
		return d[i][j] = 1;

	else if (max(i, j) - min(i, j) == 1) //길이 2
	{
		if (arr[i] == arr[j])
			return d[min(i, j)][max(i, j)] = 1;
		else
			return d[min(i, j)][max(i, j)] = 0;
	}

	else //길이 3 이상~
	{
		if (arr[i] != arr[j])
			return d[i][j] = 0;
		else
		{
			return d[i][j] = dp(i + 1, j - 1);
		}
	}
}
int main()
{
	F_I;
	/*
	* 백준 10942번 : 팰린드롬? (dp : top-down (재귀함수) )
	* d[i][j] = i번째 인덱스부터 j번째 인덱스까지의 수열이 팰린드롬이면 1, 아니면 0
	- i번째 인덱스부터 j번째 인덱스까지의 수열이 팰린드롬인지 아는 방법! 
	조건 1. 맨 끝과 끝인 arr[i]와 arr[j]가 같고, 
	조건 2. i+1번째 인덱스부터 j-1번째 인덱스까지도 팰린드롬이면 팰린드롬이다.
	*/

	memset(d, -1, sizeof(d));

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];


	//bottom-up (반복문)
	//for (int i = 1; i <= n; i++) //(길이 1) i에서 i까지는 무조건 팰린드롬이다.
	//	d[i][i] = 1;

	//for (int i = 1; i <= n - 1; i++)// (길이 2) arr[i]와 arr[i+1]가 같아야 팰린드롬. 
	//{
	//	if (arr[i] == arr[i + 1])
	//		d[i][i + 1] = 1;
	//	else
	//		d[i][i + 1] = 0;
	//}

	//for (int len = 3; len <= n; len++) //길이 3부터~
	//{
	//	for (int start = 1; start <= n - len + 1; start++) //시작점
	//	{
	//		int end = start + len - 1; //끝점

	//		if (arr[start] == arr[end] && d[start + 1][end - 1] == 1) //조건 1 & 조건 2
	//			d[start][end] = 1;
	//		else
	//			d[start][end] = 0;
	//	}
	//}

	int m;
	cin >> m;
	while (m--)
	{
		int s, e;
		cin >> s >> e;
		cout << dp(s, e) << '\n';
	}

	return 0;
}
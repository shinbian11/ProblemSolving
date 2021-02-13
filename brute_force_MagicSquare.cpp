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

int arr[10][10];
vector<int> p(9);

bool is_magic(vector<int>& p) //매직 스퀘어인지 판단!
{
	int sum = p[0] + p[1] + p[2];

	//행 검사
	if (sum != p[0] + p[1] + p[2]) return false;
	if (sum != p[3] + p[4] + p[5]) return false;
	if (sum != p[6] + p[7] + p[8]) return false;

	//열 검사
	if (sum != p[0] + p[3] + p[6]) return false;
	if (sum != p[1] + p[4] + p[7]) return false;
	if (sum != p[2] + p[5] + p[8]) return false;

	//대각선 검사
	if (sum != p[0] + p[4] + p[8]) return false;
	if (sum != p[2] + p[4] + p[6]) return false;

	return true;
}

int diff(int arr[][10], vector<int>& p) //비용 구하기
{
	int sum = 0;
	int idx = 0;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			sum += abs((arr[i][j] - p[idx++]));
		}
	}

	return sum;
}

int main()
{
	F_I;

	//[백준] 16945번 : 매직 스퀘어로 변경하기 (브루트 포스)

	/*
	1~9까지의 값이 들어있는 배열을 만들어서, 조합을 이용하여 모든 경우에 대해 매직 스퀘어가 되는지 각각 검토하고,
	매직스퀘어가 된다면 그때의 비용들의 최소 비용을 구하는 식을 풀 수 있다.	
	*/
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < 9; i++)
		p[i] = i + 1;

	int ans = -1;
	do
	{
		if (is_magic(p)) //p 배열이 매직 스퀘어라면,
		{
			int cost = diff(arr, p); //비용을 구해서

			if (ans == -1 || ans > cost) //최소인지 비교
				ans = cost;
		}

	} while (next_permutation(p.begin(), p.end()));


	cout << ans << '\n';

	return 0;
}
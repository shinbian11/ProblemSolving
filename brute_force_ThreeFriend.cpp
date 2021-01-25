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

int arr[4004][4004];
int cnt[4004];

int main()
{
	/*
	
	[백준] 17089번 : 세 친구 (브루트 포스)

	- 삼중 for문을 그냥 돌리면 O(n^3)이 나와서 시간초과가 될지도 모르지만...
	- 일단 이중 for문을 돌려서 (i,j)가 친구관계(이때 친구관계는 최대 m개이다) 일때만 k를 for문으로 탐색하도록 작업을 해 놓으면,
	O(n^2 + m*n) 이므로 시간제한에 걸리지 않는다.

	*/

	F_I;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;

		//arr[i][j] = 1 :  i와 j가 친구관계이다.
		//cnt[i] : i의 친구 수

		arr[s][e] = 1;
		arr[e][s] = 1;
		cnt[s] += 1;
		cnt[e] += 1;
	}

	int ans = -1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 1) //i와 j 가 친구라면
			{
				for (int k = 1; k <= n; k++)
				{
					if (k == i || k == j) continue;
					if (arr[i][k] == 1 && arr[k][j] == 1) //i와 k가 친구이고, k와 j도 친구라면
					{
						int tmp = cnt[i] + cnt[k] + cnt[j] - 6; //cnt[i]에서 k와 j는 빼야하고, cnt[k]에서 i와 j는 빼야하고, cnt[j]에서 i와 k는 빼야하니까 총 6을 뺀다.
						if (ans == -1 || ans > tmp)
							ans = tmp;
					}
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
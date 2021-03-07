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

int arr[1004][1004];
int d[1004][1004];

int main()
{
	// F_I;

	//[백준] 1915번 : 가장 큰 정사각형 (dp- Bottom up)

	//이해가 안되면 백준 pdf 파일 참고!

	//d[i][j] : (i,j)를 오른쪽 하단 끝점으로 하는 1로만 이루어진 가장 큰 정사각형의 한 변의 길이
	//d[i][j] = (i,j-1), (i-1,j), (i-1,j-1)을 우측하단 끝점으로 하는 1로만 이루어진 가장 큰 정사각형의 길이들 중 최소값 + 1 이다.
	//(i,j)칸이 확장되면서 정사각형의 변의 길이가 1 증가하는 것이므로 + 1 을 한다.
	//물론 arr[i][j]가 0 이면 애초에 성립이 안되므로, arr[i][j]가 1인 경우에만 해당 과정을 실행한다.

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			scanf("%1d", &arr[i][j]);
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] == 0) continue;

			d[i][j] = min({ d[i - 1][j], d[i][j - 1], d[i - 1][j - 1] }) + 1;
		}
	}

	int mx = 0; //정사각형의 최소 길이는 0이므로, 0으로 초기화 해야 한다.

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (mx < d[i][j])
				mx = d[i][j];
		}
	}

	cout << mx * mx << '\n';

	return 0;
}
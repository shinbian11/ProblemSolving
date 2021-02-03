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

int s[10]; //s[i] : i번째 계란의 내구도
int w[10]; //w[i] : i번째 계란의 무게
int n;

int go(int index) //index 번째 계란을 손에 들고 있을 때,
{
	if (index == n)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++) //깨진 계란의 개수 세기
		{
			if (s[i] <= 0)
				cnt += 1;
		}
		return cnt;
	}

	if (s[index] <= 0) //손에 들고 있는 계란이 깨진 상태일때, 그냥 그 다음으로 넘어가기
	{
		return go(index + 1);
	}

	int ans = 0; //깰 수 있는 계란의 최대 개수

	bool flag = false;

	for (int i = 0; i < n; i++)
	{
		int j = index; // 현재 들고 있는 계란의 인덱스
		if (i == j) continue; //같은 계란끼리 서로 깰 수 없다. 반드시 다른 계란끼리 깨야하니까!
		if (s[i] > 0)
		{
			flag = true; //깰 수 있는 계란이 단 한개라도 있으면, flag 를 true 로 바꾼다.

			s[i] -= w[j];
			s[j] -= w[i];

			int tmp = go(index + 1); //i번째 계란과 j번째 계란을 깼다고 가정하고 그 다음으로 넘어갔을 때의 값

			if (ans < tmp) 
				ans = tmp; //최대값 비교

			//원상복구
			s[i] += w[j];
			s[j] += w[i];
		}
	}
	if (!flag) //flag가 false라는 의미.. >> 깰 수 있는 계란이 단 한개라도 없다는 의미 => 그냥 그 다음으로 넘어가기
	{
		return go(index + 1);
	}

	return ans;
}

int main()
{
	F_I;

	//[백준] 16987번 : 계란으로 계란치기 (브루트 포스)
	// N <= 8 이고, 계란 한개당 깰 수 있는 계란의 경우의 수가 (N-1)가지이다. 즉 (N-1)^N 이 시간복잡도이다. 충분히 브루트 포스로 가능!

	
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> s[i] >> w[i];

	cout << go(0) << '\n';

	return 0;
}
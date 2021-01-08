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

int hard[16]; //문제의 난이도
bool selectQ[16]; //문제를 선택했는지의 여부(e.g. selectQ[i]가 true이면 i번째 문제를 선택했다는 의미.
int n, l, r, x;

int select_question(int index)
{
	
	if (index == n) //탈출조건!
	{
		int cnt = 0; //고른 문제 수를 체킹
		int sum = 0; //고른 문제들의 난이도의 합

		//고른 문제 중 최고 난이도 h, 최저 난이도 e
		int h = -1;
		int e = 1e9; 

		for (int i = 0; i < n; i++)
		{
			if (selectQ[i])
			{
				cnt += 1;
				sum += hard[i];

				if (h < hard[i])
					h = hard[i];

				if (e > hard[i])
					e = hard[i];
			}
			
		}
		if (cnt >= 2 && sum >= l && sum <= r && (h - e) >= x)
			return 1; //문제를 고르는 1가지 경우의 수!
		else
			return 0;
	}

	selectQ[index] = true; //index번째 문제를 선택했을 때
	int a1 = select_question(index + 1);

	selectQ[index] = false; //index번째 문제를 선택하지 않았을 때
	int a2 = select_question(index + 1);

	return a1 + a2;
}

int main()
{
	F_I;
	 /*
	 백준 16938번 : 캠프 준비
	- 문제를 두 개 이상 골라야 하니까 고르는 경우의 수는 총 2^n개이다. O(2^n) 이고 n<=15 이므로 2^15 = 32768 >>> 브루트 포스로 가능!
	- 문제를 일일히 다 고르고 난 다음 문제에 제시된 조건에 충족하는지 판독 하는 방법이 있고(이 소스코드)
	- 문제를 하나씩 고를때마다 체킹하는 방법이 있다.
	- 둘의 시간복잡도는 거의 차이가 나지 않고, 구현법에만 약간의 차이가 있다.
	 */

	//int n, l, r, x;
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++)
		cin >> hard[i]; //문제의 난이도 저장

	cout << select_question(0) << '\n';

	return 0;
}
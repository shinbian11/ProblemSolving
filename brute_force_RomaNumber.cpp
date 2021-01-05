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

int arr[20 * 50 + 1];

int main()
{
	F_I;

	int n;
	cin >> n;
	/*
	백준 16922번 : 로마 숫자 만들기 (브루트 포스 + 생각의 전환)

	- I,V,X,L 문자로 사용

	- N이 20일때, 각각의 자리에 들어올 수 있는 경우의 수는 4가지이다 -> O(4^20) : 제한시간 초과!
	- I,V,X,L의 개수를 정하자. (I는 i개, V는 j개 , X는 k개, L은 l개) -> 각 개수가 최대 N개 가능하므로 -> O(N^4) : 제한시간 초과 x
	- 근데 I,V,X의 개수를 정하면, L의 개수는 자연스레 정해진다. 반복문 돌릴 필요 없다. -> l = n - i - j - k개 -> O(N^3) : 제한시간 초과 x (가장 효율적)
	*/

	for (int i = 0; i <= n; i++) //I의 개수
	{
		for (int j = 0; j <= n - i; j++) //V의 개수
		{
			for (int k = 0; k <= n - i - j; k++) //X의 개수
			{
				int l = n - i - j - k; // L의 개수
				int sum = i * 1 + j * 5 + k * 10 + l * 50; //각각의 문자의 개수에다가 실제 값을 곱해서 모두 더해줘야 함. 그것들이 만들 수 있는 숫자들!
				arr[sum] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 20 * 50 + 1; i++)
	{
		if (arr[i]) 
			ans += 1;
	}

	cout << ans << '\n';
	return 0;
}
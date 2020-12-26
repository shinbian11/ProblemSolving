#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수


//백준 11729번 : 하노이 탑 이동 순서 (분할 정복) (c++)
void solve(int n, int x, int y)
{
	// step 1 . 1 ~ n-1 까지의 원판들을 다른 기둥으로 옮겨놓고, 
	// step 2 . 맨 밑의 n번째 원판을 최종 목적지로 옮긴 다음, 
	// step 3. step 1에서 옮겨놨던 원판들을 n번째 원판 위로 옮긴다
	if (n == 0)
		return;
	//1,2,3의 세 기둥이 있는데, x,y 기둥이 아닌 나머지 기둥을 6-x-y로 표현했다! 만약 x = 1, y = 2 면 나머지 기둥인 3은 6-1-2 = 3이니까.
	solve(n - 1, x, 6 - x - y);
	cout << x << ' ' << y << '\n';
	solve(n - 1, 6 - x - y, y);
}

int main() 
{
	F_I;
	int n;
	cin >> n;
	// D[n] = n개의 원판을 가지고 정상적으로 하노이 이동을 할 때의 횟수라고 한다면,
	// D[1] = 1 이고, D[n] = D[n-1] + 1 + D[n-1] 이다.(solve함수의 step 1~3 참고)
	// 양변에 1을 더하면 D[n] + 1 = 2(D[n-1]+1)이고, D[n]+1 = E[n]이라 치환하면,
	// E[1]=D[1]+1 = 2이고, E[n] = 2*E[n-1] = 2^n이므로, D[n]+1 = 2^n 이고, 결론적으로 D[n] = (2^n) - 1 이다.
	cout << pow(2, n) - 1 << '\n';

	solve(n,1,3); //n개의 원판을 기둥 1에서 기둥 3으로 옮기기
	return 0;

}
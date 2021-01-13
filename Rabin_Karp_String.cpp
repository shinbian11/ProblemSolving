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

int mod = 127;
int base = 256;


int hash_val(string str)
{
	int ans = 0;
	for (char ch : str)
	{
		ans = (ans * base + ch) % mod;
	}
	return ans;
}

int match(string& a, string& b)
{
	//substr(i,m) : i번째 인덱스부터, m개만큼을 추출한다는 뜻! (i번째 ~ i+m-1번째 추출)

	int n = a.length();
	int m = b.length();

	if (n < m)
		return 0;

	int pattern = hash_val(b); //찾고자 하는 패턴의 hash 값 구하기

	int f = hash_val(a.substr(0, m)); //문자열의 첫번째 덩어리의 hash 값 구하기 (두번째 덩어리부터는 그 전 덩어리에서 구했던 hash값의 일부분을 이용)

	int first = 1;

	for (int i = 0; i < m - 1; i++)
		first = (first * base) % mod; //pow(base, m-1) 말고 이 방법으로 하기! 어짜피 pow()로 하면 곱할때 마다 % mod 를 못하니까 오답 처리됨!

	for (int i = 0; i <= n - m; i++)
	{
		if (f == pattern) //hash 값이 같으면
		{
			if (a.substr(i, m) == b) return 1; //같은 문자열인지 확인
		}
		else
		{
			/*
			원래 문자열 덩어리가 123 이었다가, 이번 덩어리가 234 라면,
			123에서 1을 빼고 (123->23)  : (f - ((int)(a[i] * first) % mod))
			23을 왼쪽으로 당기고 (23->230)  : * base) % mod)
			4를 추가해야 한다 (230->234)  :  + a[i + m]) % mod;
			*/
			if (i + m < n) // i+m >= n 이면, a[i+m] 부분에서 배열 메모리 참조 오류 생기니까!
				f = ((((f - ((int)(a[i] * first) % mod)) * base) % mod) + a[i + m]) % mod;
		}
	}
	return 0;
}
int main()
{
	F_I;
	/*
	백준 16916번 : 부분 문자열 (라빈-카프 문자열 알고리즘)
	*/
	string n, m;
	cin >> n >> m;
	cout << match(n, m) << '\n';
	return 0;
}
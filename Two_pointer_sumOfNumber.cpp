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

int main()
{
	F_I;

	//[백준] 2003번 : 수들의 합 2 (브루르포스 + 투 포인터)

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int left = 0, right = 0, sum = v[0], ans = 0;
	while (left <= right && right < n)
	{
		if (sum < m) //찾고자 하는 값보다 작으면 
		{
			right += 1;
			if (right < n) //right 가 1 증가 했을때의 예외처리
				sum += v[right];
	
		}
		else if (sum > m) //찾고자 하는 값보다 크면 
		{
			sum -= v[left];
			left += 1;

			if (left > right && left < n) //left 가 1 증가 했을때의 예외처리
			{
				right = left;
				sum = v[left];
			}
			
		}
		else if(sum==m) //찾고자 하는 값이면
		{
			ans += 1;

			right += 1;

			if (right < n) //right 가 1 증가 했을때의 예외처리
				sum += v[right];	
		}

	}

	cout << ans << '\n';

	return 0;
}



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

	//[백준] 1644번 : 소수의 연속합 (소수 배열에서의 투 포인트 + 에라토스테네스의 체)

	int n;
	cin >> n;

	//에라토스테네스의 체로 소수 구하기
	vector<bool> p(n + 1);
	vector<int> v;
	for (int i = 2; i <= n; i++) {
		if (p[i] == false) {
			v.push_back(i);
			for (int j = i * 2; j <= n; j += i) {
				p[j] = true;
			}
		}
	}

	int left = 0, right = 0, ans = 0;

	//n이 1이면, 벡터 v에는 아무것도 들어가지 않았으므로, sum=0 처리 해주고, 자연적을 len=0이라고 해줘서, while문에 들어가지 않게 한다!
	int sum = v.empty() ? 0 : v[0]; 
	int len = v.size();
	
	while (left <= right && right < len)
	{
		if (sum < n)
		{
			right += 1;
			if(right< len)
				sum += v[right];
		}
		else if (sum > n)
		{
			sum -= v[left];
			left += 1;

			//if (left > right && left < len)
			//{
			//	right = left;
			//	sum = v[left];
			//}
		}
		else if (sum == n)
		{
			ans += 1;
			right += 1;
			if (right < len)
				sum += v[right];

		}
	}

	cout << ans << '\n';

	return 0;
}



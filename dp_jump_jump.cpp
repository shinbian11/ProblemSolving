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

	/*
	11060번 : 점프 점프 (dp + bottom-up)
	*/
	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> d(n, -1);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	d[0] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (d[j] != -1 && i - j <= v[j]) //d[j]==-1이면 d[j]의 값을 활용 할 수가 없으니까! && j와 i의 간격이 v[j]보다 작아야 한다.
			{
				if (d[i] == -1) //한번도 갱신 된 적이 없으면 
					d[i] = d[j] + 1; //새로 들어올 값으로 초기화 해주고,
				else //아니라면 기존의 값(d[i])과 새로 들어올 후보(d[j]+1)는 값을 비교해서 최소값만 넣어주어야 한다.
					d[i] = Min(d[i], d[j] + 1);
			}
		}
	}
	
	cout << d[n - 1] << '\n';

	return 0;
}
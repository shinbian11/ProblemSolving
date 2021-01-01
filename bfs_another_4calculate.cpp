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

	//백준 14395 : 4연산 (이것도 bfs 로 풀 수 있는 문제이다.)

	ll n, m;
	cin >> n >> m;

	set<ll> s; //set : 중복 허용 x, 자동적으로 작은것부터 정렬해줌!
	queue<pair<ll, string>> q;
	s.insert(n);

	q.push(make_pair(n, ""));

	while (!q.empty())
	{
		ll x;
		string str;
		tie(x, str) = q.front();
		q.pop();

		if (x == m) //x랑 m이랑 같은데
		{
			if (str.length() == 0) //str 길이가 0이라는 건, 한번도 연산자가 담기지 않았다는 것이므로, 처음부터 n==m 이었다는 의미이다.
				cout << 0 << '\n';
			else
			{
				cout << str << '\n';
			}
			return 0;
		}


		//연산의 아스키 코드 순서는 * + - / 순서이다.
		if (x * x >= 1 && s.count(x * x) == 0) //x*x의 값 제한 && x*x을 한번도 해본적이 없어야 함. s.count(x*x)==1 이면 이미 한번 똑같은 방법으로 바꾼 적이 있다는 의미이므로 안됨.
		{
			s.insert(x * x);
			q.push(make_pair(x * x, str + "*"));
		}
		if (x + x >= 1 && s.count(x + x) == 0) //x+x의 값 제한 && x+x을 한번도 해본적이 없어야 함. s.count(x+x)==1 이면 이미 한번 똑같은 방법으로 바꾼 적이 있다는 의미이므로 안됨.
		{
			s.insert(x + x);
			q.push(make_pair(x + x, str + "+"));
		}
		if (x - x >= 0 && s.count(x - x) == 0) //x-x의 값 제한 && x-x을 한번도 해본적이 없어야 함. s.count(x-x)==1 이면 이미 한번 똑같은 방법으로 바꾼 적이 있다는 의미이므로 안됨.
		{
			s.insert(x - x);
			q.push(make_pair(x - x, str + "-"));
		}

		if (x != 0 && x / x >= 1 && s.count(x / x) == 0) //x/x의 값 제한 && x/x을 한번도 해본적이 없어야 함. s.count(x/x)==1 이면 이미 한번 똑같은 방법으로 바꾼 적이 있다는 의미이므로 안됨.
		{
			s.insert(x / x);
			q.push(make_pair(x / x, str + "/"));
		}
	}

	cout << -1 << '\n';


	return 0;
}
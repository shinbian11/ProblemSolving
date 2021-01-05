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
	백준 16936번 : 나3곱2 (브루트 포스 + 수학적 개념(인수))

	- A의 원소들을 소인수분해 하였을 때의 인수로써 나오는 3의 개수를 기준으로 구분을 해야 한다.
	왜냐하면 나3 작업을 했을땐, 3의 인수가 하나 사라지지만, (9 = 3*3 을 나3 하면 3 = 3*1 이 된다. 3의 인수가 2개 -> 1개)
	곱2 작업을 했을땐, 3의 인수의 개수에는 아무런 영향을 끼치지 못하기 때문이다.
	
	다시 말해, 어떤 수를 3으로 나눴을때, 그 수에 포함되는 3이라는 인수의 개수는 줄어들거나 같을 수는 있어도, 늘어날 수는 없다.
	(이러한 수학적인 지식을 요구하는 문제)

	- 즉, 3이라는 인수의 개수를 기준으로 내림차순 정렬을 해야 한다.

	- 또한, 3이라는 인수의 개수가 같은 그룹 안에서는 나3 작업을 할 수 없으므로,
	(e.g. 6 3 12 는 모두 인수 3이 1개씩 있는 하나의 그룹(2*3, 3, 3*2*2)인데, 얘네들 끼리는 나3을 했을 때 같은 그룹에 속해있는 다른 원소가 될 수 없다.)
	같은 그룹 내에서는 곱2 작업만 수행해야 한다. 곱2를 하면 수가 커지므로, 같은 그룹에 속해있는 원소들은 오름차순을 정렬해야 한다.

	  e.g) 4 8 6 12 3 9

	 인수 3의 개수 :   |    2개     |     1개    |     0개    | => (내림차순)
							9          3 6 12        4 8
						(오름차순)    (오름차순)    (오름차순)
	*/

	int n;
	cin >> n;

	vector< pair<int, ll> > v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i].second; //실제 수를 .second 에 저장

	for (int i = 0; i < n; i++)
	{
		ll num = v[i].second;
		while (num % 3 == 0) //입력 받은 수들의 3의 인수 개수를 기록하는 작업 (.first 에 저장)
		{
			num /= (ll)3;
			v[i].first++;
		}
	}

	sort(v.begin(), v.end(), [](pair<int, ll>& a, pair<int, ll>& b) { //vector<pi> &a 가 아니라 pi &a이다. 
		return ((a.first > b.first) || (a.first == b.first && a.second < b.second));
		// 3의 인수 개수를 기준으로 내림차순(.first) , 3의 인수 개수가 같은 그룹끼리는 그 수의 크기로 오름차순(.second)
		});


	for (int i = 0; i < v.size(); i++)
		cout << v[i].second << ' ';

	cout << '\n';

	return 0;
}
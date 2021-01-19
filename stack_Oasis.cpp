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
	 
	백준 3015번 : 오아시스 재결합 (스택의 역할)

	- a 와 b 가 있을때, a보다 b가 더 크다면, b 뒤에 올 관객들은 a를 볼 수 없다는 사실을 이용한다.
	*** stack에는 서로 보일 수도 있는 '가능성'이 있는 관객들'만' 넣어놓는 역할을 한다.

	n=7이고, 각각의 키가 2 4 1 2 2 5 1 일 때, 2를 넣고,

	- 4는 2보다 크니까, (2,4) 로 쌍을 지을 수 있다. (개수 + 1)
	또한, 2 뒤에 4 가 들어온 이상, 4 뒤에서 2가 보일 확률은 전혀 없어지므로, 2를 pop 시킨다.
	
	- 1은 4보다 작으니까, 그냥 스택에 넣고, (1,4) 로 쌍을 지을 수 있다. (개수+1)

	- 2는 1보다 크니까, (1,2) 로 쌍을 지을 수 있다. (개수 + 1)
	또한, 1 뒤에 2 가 들어온 이상, 2 뒤에서 1이 보일 확률은 전혀 없어지므로, 1을 pop 시킨다.
	스택에 남은 4와 2는 볼 수 있으므로(사이에 다 작은 애들만.. 사이에 1밖에 없으니까 서로 볼 수 있다.) (4,2)로 쌍을 지을 수 있다. (개수+1)

	- 2는 2보다 크거나 같으니, (2,2)로 쌍을 지을 수 있다. (개수+1)
	또한, 키가 같은 경우에는 중복이라는 뜻을 표기해야 한다.  if (v.top().first == a.first) 이 부분 처리!

	.... 쭉 반복!

	*/
	ll n;
	cin >> n;
	stack<pl> v;

	ll sum = 0;

	for (ll i = 0; i < n; i++)
	{
		ll h;
		cin >> h;
		pi a = make_pair(h, 1);

		while (!v.empty())
		{
			if (v.top().first <= a.first) //스택에 있는 키 들 중 방금 들어온 키보다 작은 애들은 +1 하고 다 날리기
			{
				sum += v.top().second;

				if (v.top().first == a.first)
				{
					a.second = v.top().second + 1;
				}
				v.pop();
			}
			else
				break;
		}

		if (!v.empty()) //while문 끝내고 왔는데도 v가 비어있지 않다는건, 방금 들어온 키보다 큰 키가 최소 하나 있다는 의미이고, 그 둘이 쌍을 지을 수 있으므로, +1 한다.
			sum += 1;

		v.push(a); //push
	}

	cout << sum << '\n';

	return 0;
}
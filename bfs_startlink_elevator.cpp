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

int button[1000001];
int visited[1000001];

int main()
{
	F_I;
	
	 /*
	 백준 5014번 : 스타트링크 (bfs)
	 */

	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	queue<int> q;
	q.push(s);
	visited[s] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		//엘리베이터가 u만큼 올라가는 경우
		if (now + u <= f && visited[now + u] == 0)
		{
			button[now + u] = button[now] + 1;
			visited[now + u] = 1;
			q.push(now + u);
		}

		//엘리베이터가 d만큼 내려가는 경우
		if (now - d >= 1 && visited[now - d] == 0)
		{
			button[now - d] = button[now] + 1;
			visited[now - d] = 1;
			q.push(now - d);
		}
	}

	if (visited[g]) //visited[g]가 true라는 것은 g층을 방문했다는 의미이다.
		cout << button[g] << '\n';
	else
		cout << "use the stairs" << '\n';

	return 0;
}
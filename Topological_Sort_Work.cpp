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

vector<int> v[10004];

int work[10004];
int ind[10004];
int d[10004]; //d[i] : i번 일을 마치는 가장 빠른 시간

int main()
{
	F_I;
	//[백준] 2056번 : 작업 (위상 정렬)

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> work[i]; //work[i] : i번째 작업이 걸리는 시간
		d[i] = work[i]; //일단 복사해놓고, 나중에 비교를 통해서 값을 갱신할 수 있으면 갱신한다.
		int cnt;
		cin >> cnt;
		while (cnt--)
		{
			int e;
			cin >> e;
			v[i].push_back(e);
			ind[e] += 1;
		}
	}

	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (ind[i] == 0) //입력 차수가 0인 경우만 큐에 넣는다.
			q.push(i);
	}

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (auto t : v[x])
		{
			ind[t] -= 1;

			/*
			x->t로 가는 상황에서, d[x] + work[t] 의 최대를 d[t]로 갱신!

			e.g.)
			i		 1 2 3
			work[i]	 2 4 3 이고,

			1->3, 2->3 일때,

			d[3] = max(d[1]+work[3] , d[2] + work[3]) = max(5,7) = 7 이다.
			더 값이 적은 d[1] + work[3]을 하면 되는거 아니냐는 질문이 있을 수도 있지만,
			어짜피 1->3 만 생각하는 게 아니라, 2->3도 생각을 해야하는 것이 bfs를 이용한 위상정렬 이므로,
			3으로 갈 수 있는 모든 화살표에 대해서 생각을 해봐야 한다.

			- 이 부분 제외하고는 일반적인 bfs를 이용한 위상정렬과 코드가 거의 같다!
			*/

			if (d[t] < d[x] + work[t]) //갱신할 수 있으면 갱신 하기!
				d[t] = d[x] + work[t];

			if (ind[t] == 0)
				q.push(t);
		}
	}

	int ans = -1;

	for (int i = 1; i <= n; i++)
	{
		if (ans == -1 || ans < d[i])
			ans = d[i];
	}

	cout << ans << '\n';

	return 0;
}
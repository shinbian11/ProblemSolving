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

struct Edge
{
	int from, to, cost;
};
ll d[504]; //d[i] : i번째 도시에 도착하는 최단 시간

int main()
{
	F_I;

	//[백준] 11657번 : 타임머신 (+ 벨만포드의 개념 설명, 음의 사이클에 대하여)

	/*
	- <벨만 포드> : 1개의 시작점에서 다른 모든 곳으로 가는 최단 거리 구하는 알고리즘이다.

	x ----> y 로 갈 때, 그 때의 시간을 cost 라고 한다면,

	모든 간선에 대해서, (x로 가는 최단 시간 + cost)가 y로 가는 최단 시간 보다도 짧다면 그 값으로 갱신 시켜준다. => 이 과정을 반복한다.

	이 과정을 1번 반복 -> 간선 1개를 사용하여 모든 정점에 대한 최단 경로 값 구하는 것
	이 과정을 2번 반복 -> 간선 최대 2개를 사용하여 모든 정점에 대한 최단 경로 값 구하는 것
	이 과정을 3번 반복 -> 간선 최대 3개를 사용하여 모든 정점에 대한 최단 경로 값 구하는 것
	....
	이 과정을 n-1번 반복 -> 간선 최대 n-1개를 사용하여 모든 정점에 대한 최단 경로 값 구하는 것

	정점이 n개일때, 한 정점과 다른 정점 사이의 최단 거리의 간선의 개수는 최대 n-1 개이므로, 다시 말해 위 과정을 n-1 번 반복하면 답이 나온다.

	근데 음의 사이클은 반복할 때마다 최단 거리가 계속 작아지는 것이므로, 결국 무한번 반복하면 최단거리가 '-무한대' 가 되는 경우이다.
	이 경우는 n-1 번 반복했을 때와, n번 반복했을 때의 최단 거리의 값이 서로 달라진다. 왜냐하면 반복할때마다 값이 계속 작아진다는 의미는
	다시 말해 값이 바뀐다는 의미니까.

	그래서 이 문제의 출력 조건에서, '1번 도시에서 출발해 어떤 도시로 가는 과정에서 시간을 무한히 오래 전으로 되돌릴 수 있다면' 이라는 의미는,
	음의 사이클이 나오는 경우라는 의미이므로, 그런 경우는 -1을 출력하고 끝날 수 있게 설계해 주어야 한다.

	이를 설계하기 위해 n-1번이 아닌 n번 반복을 하고, 만약 n번째 반복을 할때 값이 갱신이 되었다면, 값이 바뀐 것이므로, 음의 사이클이 나왔다고 판단할 수 있는 것이다!!

	배열 d를 int 가 아니라 long long 으로 해야 하는 이유 : https://www.acmicpc.net/board/view/55270
	*/
	int n, m;
	cin >> n >> m;
	vector<Edge> v(m);
	for (int i = 0; i < m; i++)
	{
		cin >> v[i].from >> v[i].to >> v[i].cost;
	}
	for (int i = 1; i <= n; i++)
	{
		d[i] = 1e9; // 무한대로 초기화
	}

	d[1] = 0; //1번 도시에서 시작하므로, 1번 도시에서 1번 도시로 가는 경우는 최단 시간이 0이다.

	bool negative = false; //negative 변수가 true 가 되면 타임머신을 무한히 오래 전으로 돌릴 수 있다는 의미이다.

	for (int i = 1; i <= n; i++) //n-1이 아니라 n번 반복
	{
		for (int j = 0; j < m; j++)
		{
			int x = v[j].from;
			int y = v[j].to;
			int cost = v[j].cost;

			if (d[x] != 1e9 && d[y] > d[x] + cost)
			{
				d[y] = d[x] + cost;

				if (i == n) //n번째 반복에서 d[y]의 값이 갱신되었다면 => 음의 사이클이다.
				{
					negative = true;
				}
			}
		}
	}

	if (negative == true)
	{
		cout << -1 << '\n';
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (d[i] == 1e9)
				cout << -1 << '\n';
			else
				cout << d[i] << '\n';
		}
	}

	return 0;
}
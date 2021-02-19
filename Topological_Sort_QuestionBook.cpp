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

//bfs
vector<int> bfs_v[32004];
int ind[32004];


int main()
{
	F_I;
	//[백준] 1766번 : 문제집 (위상정렬 + 우선순위 큐)

	// 일반적인 위상정렬과 완전 같은 코드지만, 큐가 아니라 우선순위 큐로 구현한다는 차이점만 존재한다.
	// 우선순위 큐에 들어가 있는 원소들을 크기 상관없이 앞에서부터 하나씩 꺼내는게 아니라, 가장 작은 원소부터 차례로 꺼내야 한다는 점 때문이다. (조건 3 때문)

	//BFS+우선순위 큐 

	int n, m;
	cin >> n >> m;

	while (m--)
	{
		int s, e;
		cin >> s >> e;
		bfs_v[s].push_back(e);
		ind[e] += 1; //1. 각 정점의 입력 차수를 기록한다.
	}

	
	priority_queue<int, vector<int>, greater<int> > q;
	
	//2. 맨 처음 시작점은 입력차수가 0인 점들이다. 입력 차수가 0인 점들을 큐에 넣는다.
	for (int i = 1; i <= n; i++)
	{
		if (ind[i] == 0) //입력 차수가 0이면
			q.push(i); //큐에 넣기
	}

	while (!q.empty())
	{
		int x = q.top(); //우선순위 큐는 front()가 아니라 top()이다.
		q.pop();
		cout << x << ' ';

		for (auto t : bfs_v[x]) //큐에서 꺼낸 점들과 인접한 점들의 
		{
			ind[t] -= 1; //입력 차수를 하나 줄인다.

			if (ind[t] == 0) // 그 이후, 그 점의 입력 차수가 0이면, 그 정점을 큐에 넣는다.
				q.push(t);
		}
	}

	cout << '\n';
	
	return 0;
}
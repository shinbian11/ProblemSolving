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

//dfs
/*
vector<int> dfs_v[32004];
bool dfs_ch[32004];

void dfs(int x)
{
	dfs_ch[x] = true;

	for (auto t : dfs_v[x])
	{
		if (dfs_ch[t] == false)
		{
			dfs(t);
		}
	}

	cout << x << ' '; //스택에서 빠져나온 이후 기록하기!
}
*/

int main()
{
	F_I;
	//[백준] 2252번 : 줄 세우기 (위상정렬)
\
	//DAG 와 위상정렬
	//DAG : 사이클이 없는 방향성 그래프
	//위상정렬 : 어떤 것을 먼저 할지 정하는 선행 관계에 관한 알고리즘 (BFS/DFS 모두 가능)



	/*
	e.g.)  BFS 로 위상정렬 하는 법 설명!

	1->3이고, 2->3이라면, 1과 2가 모두 방문된 이후에 3이 방문되어야 하는데, 이때 1,2는 입력 차수가 0이다.
	1을 큐에서 pop 시킨 이후, 인접된 정점인 3의 입력 차수를 하나 줄인다. (1과 3 사이의 간선을 끊는다는 의미)
	그럼에도 불구하고 3의 입력차수는 아직 1이므로, 3을 아직 큐에 넣지 않는다.

	그 다음, 2를 큐에서 꺼낸 후, 인접된 정점인 3의 입력 차수를 하나 줄인다.  (2와 3 사이의 간선을 끊는다는 의미)
	그렇게 되면 3의 입력 차수는 0이 되므로, 3을 그제서야 큐에 넣을 수 있다.

	그 이후 3을 pop하면, 큐는 empty 된다.
	*/



	//BFS 로 하는 법
	int n, m;
	cin >> n >> m;

	while (m--)
	{
		int s, e;
		cin >> s >> e;
		bfs_v[s].push_back(e);
		ind[e] += 1; //1. 각 정점의 입력 차수를 기록한다.
	}

	queue<int> q;

	//2. 맨 처음 시작점은 입력차수가 0인 점들이다. 입력 차수가 0인 점들을 큐에 넣는다.
	for (int i = 1; i <= n; i++)
	{
		if (ind[i] == 0) //입력 차수가 0이면
			q.push(i); //큐에 넣기
	}

	while (!q.empty())
	{
		int x = q.front();
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
	//----------------------------------------------------------------------------------------


	//e.g.)  DFS 로 위상정렬 하는 법 설명!

	//DFS로도 위상정렬 구현 가능하다.
	// 일단 그래프의 간선의 방향을 모두 반대로 한다. 그 다음 정점들이 스택을 빠져나오는 순서를 기록하면 된다. 여기서는 BFS와 다르게 입력 차수는 사용되지 않는다.
	// 스택에서 빠져나온다는 의미는 더 이상 방문 할 정점이 없다는 의미이고, 더 이상 방문 할 정점이 없다는 건 반대로 말해 이제 이 일을 수행할 수 있다는 의미이기 때문이다.
	/*
	e.g.) 1->3, 2->3 의 관계에서, 간선을 거꾸로 한다면, 1<-3, 2<-3 인데, 3에서 시작해서, DFS로 1을 방문한 이후에는 방문할 정점이 없으므로 1을 기록하고,
	다시 3으로 돌아온 이후에 다시 2를 방문한 이후에는 방문할 정점이 없으므로 2를 기록, 그 이후 다시 돌아오면,
	이제 더 이상 방문할 정점이 없으므로, 스택에서 3이 빠져나오게 되는데, 이때 마지막으로 3을 기록하면 된다.
	*/

	//DFS 로 하는 법

	/*
	cin >> n >> m;

	while (m--)
	{
		int s, e;
		cin >> s >> e;
		dfs_v[e].push_back(s); //간선을 거꾸로 연결. 연결 정보를 반대로 넣으면 된다.
	}

	for (int i = 1; i <= n; i++)
	{
		if (dfs_ch[i] == false)
		{
			dfs(i);
		}
	}

	cout << '\n';
	*/
	return 0;
}
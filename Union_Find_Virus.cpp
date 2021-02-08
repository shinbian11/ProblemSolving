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

int root[104];
int rank_[104];

int Find(int x)
{
	if (x == root[x])
		return x;
	else
	{
		/*
		 경로 압축. x의 루트 노드와 x의 부모의 루트 노드를 모두 동일시 해야 한다. 
		 다시 말해, 최악의 경우 높이가 최대 n이 되는 트리를 만든다면, Union-Find를 구현하는 의미가 없다.
		 child가 여러개일수는 있지만, 트리의 높이가 1이 되는 1대 n 트리를 구성해야 한다.

		o
		 o
		  o
		   o
			o

		=> (높이 4) 이런 모양의 트리는 원치 않음. 이런 모양의 트리를...


		   o
		o o o o   => (높이 1) 이렇게 바꾸어야 함. 이 모양이 올바름!
		
		- 즉, 부모 노드를 찾는 Find함수를 실행하여 그 부모들의 최종 루트 노드들을 모두 같은 값으로 갱신 해주어야 한다.
		*/

		return root[x] = Find(root[x]);
	}
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x != y)
	{
		/*
		높이가 큰(랭크가 큰) 트리 밑에서가 높이가 작은 트리를 합쳐야 한다.
		그리고 높이가 같은 두 트리라면 아무렇게나 합치고, "합친 결과 트리"의 높이를 1 증가시키면 된다.
		*/

		if (rank_[x] < rank_[y])
			root[x] = y;
		else
			root[y] = x;

		if (rank_[x] == rank_[y])
			rank_[x] += 1;
	}

	return;
}

int main()
{
	F_I;

	/*	
	[백준] 2606번 : 바이러스 (Union-Find)

	- bfs,dfs로 해결 가능하지만, Union-Find로도 해결 가능하다.
	- 1번 컴퓨터와 연결이 되어 있는 컴퓨터의 개수가 답이므로, 1번 컴퓨터와 루트가 같은 컴퓨터의 개수를 찾으면 된다.
	- 루트가 같다 == 같은 집합에 속해 있다 == 웜 바이러스에 전염된다.


	- Find 함수에서의 경로 압축 + Union 함수에서의 rank 개념 >> 이 개념을 이용하기 전 : Find, Union 모두 최악의 경우 시간복잡도 > O(N)
	- Find 함수에서의 경로 압축 + Union 함수에서의 rank 개념 >> 이 개념을 이용한 이후 : Find, Union 모두 최악의 경우 시간복잡도 > O(log N) : 훨씬 좋아졌다!
	*/

	int computer, edge;
	cin >> computer >> edge;

	for (int i = 1; i <= computer; i++)
	{
		root[i] = i;
		rank_[i] = 0;
	}

	for (int i = 0; i < edge; i++)
	{
		int x, y;
		cin >> x >> y;
		Union(x, y);
	}

	int cnt = 0;
	for (int i = 2; i <= computer; i++)
	{
		if (Find(1) == Find(i)) // 1번과 같은 부모를 가진 컴퓨터의 개수
			cnt++;
	}

	cout << cnt << '\n';

	return 0;
}
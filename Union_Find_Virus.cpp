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

int parent[101];

int Find(int x) //x의 조상을 찾는 함수. 
{
	if (x == parent[x])
		return x;
	else
	{
		// 경로 압축. x의 루트 노드와 x의 부모의 루트 노드를 모두 동일시 해야 한다. 
		// 다시 말해, 최악의 경우 높이가 최대 n이 되는 트리를 만든다면, Union-Find를 구현하는 의미가 없다.
		// child가 여러개일수는 있지만, 트리의 높이가 1이 되는 1대 n 트리를 구성해야 한다.
		/*
			  o
				o
				  o
				    o
					  o  => (높이 4) 이런 모양의 트리는 원치 않음. 이런 모양의 트리를...
		
		
		      o
           o o o o   => (높이 1) 이렇게 바꾸어야 함. 이 모양이 올바름!
		*/
		// 즉, 부모 노드를 찾는 Find함수를 실행하여 그 부모들의 최종 루트 노드들을 모두 같은 값으로 갱신 해주어야 한다.
		return parent[x] = Find(parent[x]); 
	}
}

void Union(int s, int e)
{
	int x = Find(s);
	int y = Find(e);

	if (x != y)
		parent[x] = y;
}

int main()
{
	F_I;
	
	/*
	백준 2606번 : 바이러스 (Union-Find)

	- bfs,dfs로 해결 가능하지만, Union-Find로도 해결 가능하다.
	- 1번 컴퓨터와 연결이 되어 있는 컴퓨터의 개수가 답이므로, 1번 컴퓨터와 루트가 같은 컴퓨터의 개수를 찾으면 된다.
	- 루트가 같다 == 같은 집합에 속해 있다 == 웜 바이러스에 전염된다.
	*/

	int computer;
	int edge;
	cin >> computer >> edge;

	for (int i = 1; i <= computer; i++)
		parent[i] = i;

	for (int i = 1; i <= edge; i++)
	{
		int s, e;
		cin >> s >> e;
		Union(s, e);
	}

	int ans = 0;
	for (int i = 2; i <= computer; i++) //2번 컴퓨터부터 computer번 컴퓨터까지, 1번과 루트가 같은 컴퓨터들의 개수를 찾으면 됨.
	{
		if (Find(1) == Find(i))
			ans += 1;
	}
	cout << ans << '\n';

	return 0;

}
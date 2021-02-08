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

int root[1000004];
int Rank[1000004];

int Find(int x) //x의 루트노드를 반환하는 함수
{
	if (x == root[x]) //x와 x의 루트노드가 같을 때 > x의 루트노드가 x일 때, 자기자신이 루트노드일 때
		return x; //자기자신을 반환
	else
		return root[x] = Find(root[x]); //아니면 root[x]의 루트노드를 찾는 재귀함수를 호출!
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	 
	if (x != y) //x와 y가 같은 집합에 들어가 있는게 아닐때에만 합친다.
	{
		if (Rank[x] < Rank[y]) //y가 더 높이가 높은 트리일때 (y가 더 큰 트리)
			root[x] = y; //x가 있는 트리를 y가 있는 트리에 합쳐야 하니까, x의 루트 노드를 y 로 바꾼다.
		else // 그 반대의 경우 (x 트리가 더 높은 트리거나, 두 트리의 높이가 같을 때)
		{
			root[y] = x;
		}

		//트리의 높이가 같다면, 아무거나 합치고, "합친 이후의 결과 트리"의 랭크를 1 증가한다.
		//여기서는 else 문의 경우가 x 트리와 y 트리의 높이가 같은 경우에 속하므로, 이때 y 트리를 x 트리에 합치고,
		//결과 트리인 x 트리의 rank 를 1 증가시킨다.
		if (Rank[x] == Rank[y]) 
			Rank[x] += 1;
	}

	return;

}

int main()
{
	F_I;

	//[백준] 1717번 : 집합의 표현 (Union-Find)
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		root[i] = i;
		Rank[i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int a, x, y;
		cin >> a >> x >> y;

		if (a == 0)
			Union(x, y);
		if (a == 1)
		{
			x = Find(x);
			y = Find(y);
			if (x == y)
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}

	return 0;
}
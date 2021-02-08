#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

int root[104];
int rank_[104];

int Find(int x)
{
	if (x == root[x])
		return x;
	else
	{
		/*
		 ��� ����. x�� ��Ʈ ���� x�� �θ��� ��Ʈ ��带 ��� ���Ͻ� �ؾ� �Ѵ�. 
		 �ٽ� ����, �־��� ��� ���̰� �ִ� n�� �Ǵ� Ʈ���� ����ٸ�, Union-Find�� �����ϴ� �ǹ̰� ����.
		 child�� �������ϼ��� ������, Ʈ���� ���̰� 1�� �Ǵ� 1�� n Ʈ���� �����ؾ� �Ѵ�.

		o
		 o
		  o
		   o
			o

		=> (���� 4) �̷� ����� Ʈ���� ��ġ ����. �̷� ����� Ʈ����...


		   o
		o o o o   => (���� 1) �̷��� �ٲپ�� ��. �� ����� �ùٸ�!
		
		- ��, �θ� ��带 ã�� Find�Լ��� �����Ͽ� �� �θ���� ���� ��Ʈ ������ ��� ���� ������ ���� ���־�� �Ѵ�.
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
		���̰� ū(��ũ�� ū) Ʈ�� �ؿ����� ���̰� ���� Ʈ���� ���ľ� �Ѵ�.
		�׸��� ���̰� ���� �� Ʈ����� �ƹ����Գ� ��ġ��, "��ģ ��� Ʈ��"�� ���̸� 1 ������Ű�� �ȴ�.
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
	[����] 2606�� : ���̷��� (Union-Find)

	- bfs,dfs�� �ذ� ����������, Union-Find�ε� �ذ� �����ϴ�.
	- 1�� ��ǻ�Ϳ� ������ �Ǿ� �ִ� ��ǻ���� ������ ���̹Ƿ�, 1�� ��ǻ�Ϳ� ��Ʈ�� ���� ��ǻ���� ������ ã���� �ȴ�.
	- ��Ʈ�� ���� == ���� ���տ� ���� �ִ� == �� ���̷����� �����ȴ�.


	- Find �Լ������� ��� ���� + Union �Լ������� rank ���� >> �� ������ �̿��ϱ� �� : Find, Union ��� �־��� ��� �ð����⵵ > O(N)
	- Find �Լ������� ��� ���� + Union �Լ������� rank ���� >> �� ������ �̿��� ���� : Find, Union ��� �־��� ��� �ð����⵵ > O(log N) : �ξ� ��������!
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
		if (Find(1) == Find(i)) // 1���� ���� �θ� ���� ��ǻ���� ����
			cnt++;
	}

	cout << cnt << '\n';

	return 0;
}
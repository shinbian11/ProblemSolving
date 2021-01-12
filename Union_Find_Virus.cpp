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

int parent[101];

int Find(int x) //x�� ������ ã�� �Լ�. 
{
	if (x == parent[x])
		return x;
	else
	{
		// ��� ����. x�� ��Ʈ ���� x�� �θ��� ��Ʈ ��带 ��� ���Ͻ� �ؾ� �Ѵ�. 
		// �ٽ� ����, �־��� ��� ���̰� �ִ� n�� �Ǵ� Ʈ���� ����ٸ�, Union-Find�� �����ϴ� �ǹ̰� ����.
		// child�� �������ϼ��� ������, Ʈ���� ���̰� 1�� �Ǵ� 1�� n Ʈ���� �����ؾ� �Ѵ�.
		/*
			  o
				o
				  o
				    o
					  o  => (���� 4) �̷� ����� Ʈ���� ��ġ ����. �̷� ����� Ʈ����...
		
		
		      o
           o o o o   => (���� 1) �̷��� �ٲپ�� ��. �� ����� �ùٸ�!
		*/
		// ��, �θ� ��带 ã�� Find�Լ��� �����Ͽ� �� �θ���� ���� ��Ʈ ������ ��� ���� ������ ���� ���־�� �Ѵ�.
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
	���� 2606�� : ���̷��� (Union-Find)

	- bfs,dfs�� �ذ� ����������, Union-Find�ε� �ذ� �����ϴ�.
	- 1�� ��ǻ�Ϳ� ������ �Ǿ� �ִ� ��ǻ���� ������ ���̹Ƿ�, 1�� ��ǻ�Ϳ� ��Ʈ�� ���� ��ǻ���� ������ ã���� �ȴ�.
	- ��Ʈ�� ���� == ���� ���տ� ���� �ִ� == �� ���̷����� �����ȴ�.
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
	for (int i = 2; i <= computer; i++) //2�� ��ǻ�ͺ��� computer�� ��ǻ�ͱ���, 1���� ��Ʈ�� ���� ��ǻ�͵��� ������ ã���� ��.
	{
		if (Find(1) == Find(i))
			ans += 1;
	}
	cout << ans << '\n';

	return 0;

}
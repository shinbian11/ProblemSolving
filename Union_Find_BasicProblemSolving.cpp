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

int root[1000004];
int Rank[1000004];

int Find(int x) //x�� ��Ʈ��带 ��ȯ�ϴ� �Լ�
{
	if (x == root[x]) //x�� x�� ��Ʈ��尡 ���� �� > x�� ��Ʈ��尡 x�� ��, �ڱ��ڽ��� ��Ʈ����� ��
		return x; //�ڱ��ڽ��� ��ȯ
	else
		return root[x] = Find(root[x]); //�ƴϸ� root[x]�� ��Ʈ��带 ã�� ����Լ��� ȣ��!
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	 
	if (x != y) //x�� y�� ���� ���տ� �� �ִ°� �ƴҶ����� ��ģ��.
	{
		if (Rank[x] < Rank[y]) //y�� �� ���̰� ���� Ʈ���϶� (y�� �� ū Ʈ��)
			root[x] = y; //x�� �ִ� Ʈ���� y�� �ִ� Ʈ���� ���ľ� �ϴϱ�, x�� ��Ʈ ��带 y �� �ٲ۴�.
		else // �� �ݴ��� ��� (x Ʈ���� �� ���� Ʈ���ų�, �� Ʈ���� ���̰� ���� ��)
		{
			root[y] = x;
		}

		//Ʈ���� ���̰� ���ٸ�, �ƹ��ų� ��ġ��, "��ģ ������ ��� Ʈ��"�� ��ũ�� 1 �����Ѵ�.
		//���⼭�� else ���� ��찡 x Ʈ���� y Ʈ���� ���̰� ���� ��쿡 ���ϹǷ�, �̶� y Ʈ���� x Ʈ���� ��ġ��,
		//��� Ʈ���� x Ʈ���� rank �� 1 ������Ų��.
		if (Rank[x] == Rank[y]) 
			Rank[x] += 1;
	}

	return;

}

int main()
{
	F_I;

	//[����] 1717�� : ������ ǥ�� (Union-Find)
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
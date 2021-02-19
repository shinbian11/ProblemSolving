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

//bfs
vector<int> bfs_v[32004];
int ind[32004];


int main()
{
	F_I;
	//[����] 1766�� : ������ (�������� + �켱���� ť)

	// �Ϲ����� �������İ� ���� ���� �ڵ�����, ť�� �ƴ϶� �켱���� ť�� �����Ѵٴ� �������� �����Ѵ�.
	// �켱���� ť�� �� �ִ� ���ҵ��� ũ�� ������� �տ������� �ϳ��� �����°� �ƴ϶�, ���� ���� ���Һ��� ���ʷ� ������ �Ѵٴ� �� �����̴�. (���� 3 ����)

	//BFS+�켱���� ť 

	int n, m;
	cin >> n >> m;

	while (m--)
	{
		int s, e;
		cin >> s >> e;
		bfs_v[s].push_back(e);
		ind[e] += 1; //1. �� ������ �Է� ������ ����Ѵ�.
	}

	
	priority_queue<int, vector<int>, greater<int> > q;
	
	//2. �� ó�� �������� �Է������� 0�� �����̴�. �Է� ������ 0�� ������ ť�� �ִ´�.
	for (int i = 1; i <= n; i++)
	{
		if (ind[i] == 0) //�Է� ������ 0�̸�
			q.push(i); //ť�� �ֱ�
	}

	while (!q.empty())
	{
		int x = q.top(); //�켱���� ť�� front()�� �ƴ϶� top()�̴�.
		q.pop();
		cout << x << ' ';

		for (auto t : bfs_v[x]) //ť���� ���� ����� ������ ������ 
		{
			ind[t] -= 1; //�Է� ������ �ϳ� ���δ�.

			if (ind[t] == 0) // �� ����, �� ���� �Է� ������ 0�̸�, �� ������ ť�� �ִ´�.
				q.push(t);
		}
	}

	cout << '\n';
	
	return 0;
}
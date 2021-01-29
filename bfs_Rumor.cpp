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

int main()
{
	//[����] 19538�� : ��� (bfs)
	//�Ϲ����� bfs �� Ʋ����, ����� ������� ���� �̻��� ��Ӹ� �ϰ� �� ���������� ��μ� ���ε� ��Ӹ� �ϴ´ٴ� ó���� �߰������� ���ָ� �Ǵ� bfs �����̴�.

	int n;
	cin >> n;
	vector< vector<int> > v(n+1);
	for (int i = 1; i <= n; i++)
	{
		while (true)
		{
			int num;
			cin >> num;
			if (num == 0)
				break;
			v[i].push_back(num);
			v[num].push_back(i);
		}
	}

	int m;
	cin >> m;
	vector<int> r(m); //�ʱ� ��� ������
	vector<bool> visited(n + 1, false); // visited[i] = true : i��° ����� rumor �� �ϰ� �ִ�.
	vector<int> rumor(n + 1, 0); //���� �̻��� ����� ��Ӹ� �ϴ´� >> �� ó���� �� �� �ʿ��� ���� 
	vector<int> d(n+1,-1); //ó�� ��Ӹ� �ϴ� �ð��� ��� �ִ�.

	queue<int> q;

	for (int i = 0; i < m; i++)
	{
		cin >> r[i];

		//���� �����ڵ鿡 ���� ó��
		q.push(r[i]);
		visited[r[i]] = true; 
		d[r[i]] = 0; //0�ʿ� �ٷ� �ϴ´�.
	}

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto k : v[x])
		{
			if (visited[k] == false)
			{
				rumor[k] += 1; //�ֺ��ε��� �� 1 ����

				if (rumor[k] >= (v[k].size() + 1) / 2) //���� �̻��� ��Ӹ� ������
				{
					//���ε� ��Ӹ� �ϴ´�.
					visited[k] = true;
					d[k] = d[x] + 1;
					q.push(k);
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		cout << d[i] << ' ';
	cout << '\n';
	
	return 0;
}
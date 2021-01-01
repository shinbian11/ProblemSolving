#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

int prime[10001];
int visited[10001];
int d[10001];

int changeDigit(int x, int i, int j)// ���� x�� i��° �ε����� j�� �ٲ� ���� �Ҽ������� �Ǵ��ϴ� �Լ�
{
	if (i == 0 && j == 0) //0��° �ε����� 0���� �ٲٸ� ���ڸ����� �Ǵϱ�, �� ���� �ȵ�!!
		return -100;

	string now = to_string(x);
	now[i] = j + '0'; //ascii��
	int a = stoi(now);
	if (prime[a]) //�ٲ� ���� �Ҽ��� �� ���� ��ȯ
		return a;
	else
		return -100;
}

int main()
{
	F_I;

	//���� 1963�� �Ҽ� ��� : n���� m���� ���� ������ �ϴµ�, �� �ڸ��� �ٲٸ鼭 , �ּ� Ƚ��(�ִ� ���)�� ���ϴ� �����̹Ƿ�, bfs�� ����!
	// ��� ���� ��ã�� ������ �ƴ϶� bfs�� Ǯ �� ���ٰ� ���� �� ���� �ִµ�, bfs�� Ǯ �� �ִ� ������ ������ �� �����ϸ� bfs�� Ǯ �� �ִ�!


	//2���� 10000������ �� �� �Ҽ��� ���ϴ� ���(�����佺�׳׽��� ü)
	for (int i = 2; i <= 10000; i++)
	{
		for (int j = i * i; j <= 10000; j += i)
		{
			if (prime[j] == false)
				prime[j] = true;
		}

	}
	for (int i = 2; i <= 10000; i++)
	{
		prime[i] = !prime[i]; //�Ҽ��ΰ͸� 1�� ǥ��!
	}



	int tc;
	cin >> tc;
	while (tc--)
	{
		int s, e;
		cin >> s >> e;
		memset(visited, 0, sizeof(visited));
		memset(d, 0, sizeof(d));

		queue<int> q;
		q.push(s);

		d[s] = 0;
		visited[s] = 1;

		while (!q.empty())
		{
			int x = q.front();

			q.pop();
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j <= 9; j++)
				{
					int nextNumber = changeDigit(x, i, j);
					if (nextNumber != -100 && visited[nextNumber] == 0) //���� x�� i��° �ε����� j�� �ٲ� ����� (nextNumber)�� �Ҽ��̸�, ���� �湮���� ���� ���϶�! (���� ���)
					{
						d[nextNumber] = d[x] + 1;
						visited[nextNumber] = 1;
						q.push(nextNumber);
					}
				}
			}
		}
		cout << d[e] << '\n';
	}

	return 0;
}
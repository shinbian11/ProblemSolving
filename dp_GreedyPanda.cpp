#include <bits/stdc++.h>
#include <unordered_set>

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

int arr[504][504];
int d[504][504];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n;

/*
d[i][j] : (i,j)���� �������� �� �Ǵٰ� �� �� �ִ� �ִ� �� ��(�̵��� �� �ִ� �ִ� ĭ ��)
(i,j) -> (x,y) -> ..... -> (��) �̶�� �׸��� �׷��� �� , d[i][j] = d[x][y] + 1 �̴�.
�̶� (x,y)�� 3���� ������ �����ϴ� ���ε�,
���� 1 : (i,j)���� �����¿� ������ ĭ�̾�� �Ѵ�.
���� 2 : (x,y)�� matrix ������ ����� �ȵȴ�.
���� 3 : arr[i][j]���� arr[x][y]�� �� ū ���� ������ �Ѵ�. (�׷��� ������� �Ǵٰ� �̵� �� �� �����ϱ�)
-> 3���� ������ �����ϴ� (x,y)�� ã�°� �߿��� ����Ʈ�̴�.
*/
int panda(int i, int j) //(i,j)���� �������� �� �Ǵ��� �ִ� ���� �� ���� ��ȯ�ϴ� �Լ�
{
	if (d[i][j] != -1) return d[i][j]; //memoization

	d[i][j] = 1; //�� ������ �Ǵٰ� ������ �� �ִ� ĭ�� �ִ� ������ ���ϴ� �����̰�, (i,j)ĭ�� �ִ� �͵� 1ĭ���� �����ǹǷ� 1�� �ʱ�ȭ�Ѵ�.

	for (int k = 0; k < 4; k++)
	{
		//���� 1 : ������ �����¿� ĭ
		int x = i + dx[k];
		int y = j + dy[k];

		//���� 2 : ���� üũ
		if (x >= 0 && x < n && y >= 0 && y < n)
		{
			//���� 3 : arr[i][j]���� �� ū ������ ��
			if (arr[i][j] < arr[x][y])
			{
				if (d[i][j] < panda(x, y) + 1) //'�ִ�' �� ��!
					d[i][j] = panda(x, y) + 1;
			}
		}
	}

	return d[i][j];
}

int main()
{
	F_I;
	//[����] 1937�� : ������� �Ǵ� (dp, Top_down)

	//int n;
	cin >> n;

	memset(d, -1, sizeof(d));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	//�Ǵ��� �������� ������ ���� �ƴϹǷ�, ��� ĭ�� ���ؼ� ���� ���� ���� �ִ� �̵� ĭ�� (�ִ� ���� �� ��)�� ���Ѵ�.
	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ans < panda(i, j))
				ans = panda(i, j);
		}
	}

	cout << ans << '\n';

	return 0;
}
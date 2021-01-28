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

int arr[20][20];
int n;

int go(int x, int y, int move) //move : 1�� ����, 2�� �Ʒ�, 3�� �밢�� �Ʒ� �������� �̵�
{
	//��������
	if (x == n && y == n) //(n,n)�� �����ߴٴ� ��� �� �� 1���� ����� ã�� ���̹Ƿ�, 1 ��ȯ
		return 1;

	int ans = 0;

	if (move == 1)
	{
		if (y + 1 <= n && arr[x][y + 1] == 0)
		{
			ans += go(x, y + 1, 1);
		}
		//�밢������ �̵��Ϸ��� ������ ��� ��ĭ�̾�� �Ѵ�. ���� �� �б�!
		if (x + 1 <= n && y + 1 <= n && arr[x + 1][y] == 0 && arr[x][y + 1] == 0 && arr[x + 1][y + 1] == 0) 
		{
			ans += go(x + 1, y + 1, 3);
		}
	}
	if (move == 2)
	{
		if (x + 1 <= n && arr[x + 1][y] == 0)
		{
			ans += go(x+1, y, 2);
		}
		if (x + 1 <= n && y + 1 <= n && arr[x + 1][y] == 0 && arr[x][y + 1] == 0 && arr[x + 1][y + 1] == 0)
		{
			ans += go(x + 1, y + 1, 3);
		}
	}
	if (move == 3) 
	{
		if (y + 1 <= n && arr[x][y + 1] == 0)
		{
			ans += go(x, y + 1, 1);
		}
		if (x + 1 <= n && arr[x + 1][y] == 0)
		{
			ans += go(x + 1, y, 2);
		}
		if (x + 1 <= n && y + 1 <= n && arr[x + 1][y] == 0 && arr[x][y + 1] == 0 && arr[x + 1][y + 1] == 0)
		{
			ans += go(x + 1, y + 1, 3);
		}
	}

	return ans;
}

int main()
{
	//[����] 17070�� : ������ �ű�� 1 (���Ʈ ����)

	//int n;
	cin >> n;
	//vector< vector<int> > arr(n+1, vector<int>(n+1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	}

	cout << go(1, 2, 1) << '\n'; //�������� (1,2)�̰�, (1,1)���� (1,2) �������� �̵��ϴϱ�(������ �������� ���ϱ� �� ��° ���ڴ� 1�̴�)

	return 0;
}
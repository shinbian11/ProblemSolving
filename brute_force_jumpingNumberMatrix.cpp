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
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int n = 5;
vector< vector<int> > arr(n, vector<int>(n));
set<int> d;

void func(int x, int y, int num, int len)
{
	if (len == 6)
	{
		d.insert(num);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n)
		{
			func(nx, ny, 10 * num + arr[nx][ny], len + 1);
		}
	}

	return;
}

int main()
{
	F_I;
	/*
	[����] 2210�� : ������ ���� ( ���Ʈ ���� + �ߺ� ����)

	- ��ư� ������ �ʿ� ����. ������ �����¿�� ��� ���ư���, ���̰� 6�� �Ǹ� �ڷᱸ���� �����ϰ�, �ߺ� ���� ���� ���� ��� �ϸ� �Ǵ� ������ �����̴�.
	set�� �̿��ϸ� �ߺ� ���Ű� �������Ƿ� set �̿�. ����Լ� �̿��Ͽ� ���� ó�� �����ϴ�!4

	*/
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			func(i, j, arr[i][j], 1);
		}
	}

	cout << d.size() << '\n';

	return 0;
}
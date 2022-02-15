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

int p[3000][3000];
int cnt[3];

int same(int i, int j, int m)// i�� j������ m * m ����� ��� ������ 1, �ƴϸ� 0 ��ȯ
{
	for (int x = i; x < i + m; x++)
	{
		for (int y = j ; y < j + m; y++)
		{
			if (p[i][j] != p[x][y])
				return 0;
		}
	}
	return 1;
}

void solve(int i, int j, int n) 
{
	if (same(i, j, n)) //i�� j������ n * n ����� ��� ������
	{
		cnt[p[i][j] + 1] += 1; // �� i�� j���� �ش��ϴ� ������ ���� ����صα�!
		return;
	}
	else
	{
		int m = n / 3;
		for (int x = 0; x < 3; x++) // i�� j������ n * n ����� �ٸ� ���� ������
		{
			for (int y = 0; y < 3; y++)
			{
				solve(i + m * x, j + m * y, m); //������ 9���� ���̷� ���� �߶�, �ڸ� 9����� ��� ����Լ��� ȣ���Ѵ�.
			}
		}
	}
}
int main() 
{
	F_I;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> p[i][j];
	}

	solve(0, 0, n);

	for (int i = 0; i < 3; i++)
		cout << cnt[i] << '\n';
	return 0;
}
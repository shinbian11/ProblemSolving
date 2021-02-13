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

ll d[54][54][54][54];
ll mod = 1e9 + 7;

/*
 e.g.)

n��° ���� a,b�� �θ��ٰ� ������, d[n-1][a-1][b-1][c]�� �Ǵ� ���̴�.
n��° ���� a,c�� �θ��ٰ� ������, d[n-1][a-1][b][c-1]�� �Ǵ� ���̴�.
....
....
....

- ��, d[n][a][b][c] = d[n-1][a-i][b-j][c-k]�� ���̴�. (i,j,k�� 0~1�̴�.)
*/

ll go(int n, int a, int b, int c)
{
	if (n == 0)
	{
		if (a == 0 && b == 0 && c == 0) //n���� ���� ���� a,b,c�� �� �� ���ǿ� �°� �� �ҷ�����, 1���� ��� �߰�!
			return 1;
		else
			return 0;
	}

	if (a < 0 || b < 0 || c < 0) return 0; //���� üũ

	//memoization
	if (d[n][a][b][c] != -1)
		return d[n][a][b][c];

	ll ans = 0;

	//i,j,k�� 1�̴� >> �� ����� �� ���� �θ��ٴ� �ǹ�!
	for (int i = 0; i <= 1; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			for (int k = 0; k <= 1; k++)
			{
				if (i == 0 && j == 0 && k == 0) continue; //��ΰ� ���� �� �θ��� ��� ����
				ans += go(n - 1, a - i, b - j, c - k);
			}
		}
	}

	ans %= mod;

	return d[n][a][b][c] = ans;
}

int main()
{
	//[����] 12996�� : Acka (dp)
	F_I;
	int n, a, b, c;
	cin >> n >> a >> b >> c;

	memset(d, -1, sizeof(d)); //-1�� �ʱ�ȭ (�޸������̼��� ���ؼ�)

	cout << go(n, a, b, c) << '\n';

	return 0;
}
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


int arr[504][2];
int d[504][504];
int n;

int go(int i, int j)
{
	//d[i][j] : i��° ��ĺ��� j��° ��ı��� ��� ������ �� ���� �ʿ��� ������ �ּ� ���� Ƚ��

	if (d[i][j] != -1) //memoization
		return d[i][j];

	if (i == j)//n == 1
		return 0;

	if (i + 1 == j)//n == 2
		return d[i][j] = arr[i][0] * arr[i][1] * arr[j][1];

	int ans = -1;
	
	for (int k = i; k < j; k++) // n >= 3
	{
		int tmp = go(i, k) + go(k + 1, j) + (arr[i][0] * arr[k][1] * arr[j][1]);
		if (ans == -1 || ans > tmp)
			ans = tmp;
	}


	return d[i][j] = ans;

}

int main()
{
	F_I;
	/*
	[����] 11049�� : ��� ���� ���� (dp, Top-down)
	- 11066�� ������ġ�� ������ �ſ� ����� �����̴�. 
	*/

	//int n;
	cin >> n;

	memset(d, -1, sizeof(d));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 2; j++)
			cin >> arr[i][j];
	}

	cout << go(1, n);

	return 0;
}
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

int arr[1004][1004];
int d[1004][1004];

int main()
{
	// F_I;

	//[����] 1915�� : ���� ū ���簢�� (dp- Bottom up)

	//���ذ� �ȵǸ� ���� pdf ���� ����!

	//d[i][j] : (i,j)�� ������ �ϴ� �������� �ϴ� 1�θ� �̷���� ���� ū ���簢���� �� ���� ����
	//d[i][j] = (i,j-1), (i-1,j), (i-1,j-1)�� �����ϴ� �������� �ϴ� 1�θ� �̷���� ���� ū ���簢���� ���̵� �� �ּҰ� + 1 �̴�.
	//(i,j)ĭ�� Ȯ��Ǹ鼭 ���簢���� ���� ���̰� 1 �����ϴ� ���̹Ƿ� + 1 �� �Ѵ�.
	//���� arr[i][j]�� 0 �̸� ���ʿ� ������ �ȵǹǷ�, arr[i][j]�� 1�� ��쿡�� �ش� ������ �����Ѵ�.

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			scanf("%1d", &arr[i][j]);
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] == 0) continue;

			d[i][j] = min({ d[i - 1][j], d[i][j - 1], d[i - 1][j - 1] }) + 1;
		}
	}

	int mx = 0; //���簢���� �ּ� ���̴� 0�̹Ƿ�, 0���� �ʱ�ȭ �ؾ� �Ѵ�.

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (mx < d[i][j])
				mx = d[i][j];
		}
	}

	cout << mx * mx << '\n';

	return 0;
}
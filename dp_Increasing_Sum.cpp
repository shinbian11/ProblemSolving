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

ll arr[1004];
ll d[1004];

int main()
{
	F_I;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		d[i] = arr[i];
	}
	
	//d[i] : i�� �ε��������� ���� ū �κ� ������ ��
	//arr[j] < arr[i] : �����ϴ� �����̶�� ��
	//d[j] + arr[i] > d[i] : ���ݱ����� �ִ� + arr[i]�� �ִ���, �װ��� d[i]�� �Ǿ�� �Ѵ�.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && d[j] + arr[i] > d[i])
			{
				d[i] = d[j] + arr[i];
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		if (ans < d[i])
			ans = d[i];
	}
	cout << ans << '\n';

	return 0;
}
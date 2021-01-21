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
	F_I;

	/*
	
	[����] 17088�� : �������� ��ȯ (���Ʈ ���� + ����)

	�������� an�� an = a0+(n-1)*d�ε�, a0�� 3������ ���� �� �ִ�. (a0 / a0 + 1 / a0 - 1)
	����, d = a1-a0�ε�, a1�� a0�� ���������� 3������ �����ϰ�, a0�� �տ��� ���������Ƿ�,
	an�� ����� ���� �� 3*3 = 9���� �̴�. ��� �õ��غ��� �ȴ�. (���Ʈ ����)

	*/

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	if (n == 1)
	{
		cout << 0 << '\n';
		return 0;
	}

	int ans = 1e9;

	for (int d1 = -1; d1 <= 1; d1++) //a0�� ���� ����� �� : 3����  (a0-1 / a0 / a0+1)
	{
		for (int d2 = -1; d2 <= 1; d2++)  //a1�� ���� ����� �� : 3����  (a1-1 / a1 / a1+1)
		{
			int change = 0; //����Ƚ���� ��

			if (d1 != 0) change += 1; //d1 != 0�̶�� �� + 1 �̳� - 1 �� ������ 1�� �ߴٴ� �Ŵϱ�
			if (d2 != 0) change += 1; //d2 != 0�̶�� �� + 1 �̳� - 1 �� ������ 1�� �ߴٴ� �Ŵϱ�

			int a0 = (arr[0] + d1); //ù��° ��
			int d = (arr[1] + d2) - a0; //����

			bool flag = true;
			int na = a0 + d;

			for (int i = 2; i < n; i++)
			{
				na += d;

				if (arr[i] == na) continue;

				if (arr[i] + 1 == na || arr[i] - 1 == na)
					change += 1;
				else
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				if (ans > change)
				{
					ans = change;
				}
			}
		}
	}

	if (ans == 1e9)
		cout << -1 << '\n';
	else
		cout << ans << '\n';

	return 0;
}
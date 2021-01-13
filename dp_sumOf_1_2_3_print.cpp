#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

int d[14];
int n, k;

void print(int n, int k)
{
	/*n�� 4�϶�, �������� 7�����ε� �̸� ���������� �����ϸ�,
	
	1+1+1+1
	1+1+2
	1+2+1
	1+3

	2+1+1
	2+2

	3+1

	-> �� ������� ����������. 
	-> �� ���캸�� �̷� ��Ģ�� ���´�.

	-> 1�� �����ϴ� ���� : 4�� (=d[3])
	-> 2�� �����ϴ� ���� : 2�� (=d[2])
	-> 3�� �����ϴ� ���� : 1�� (=d[1])

	*/
	for (int i = 1; i <= 3; i++)
	{
		if (d[n - i] < k)
			k -= d[n - i];
		else
		{
			if (n - i > 0)
			{
				cout << i;
				cout << '+';
				print(n - i, k);
			}
			else
				cout << i << '\n';
			break;
		}
	}
	return;
}

int main()
{
	F_I;

	//���� 12101�� : 1, 2, 3 ���ϱ� 2 (dp, ��Ģ��)

	cin >> n >> k;
	
	memset(d, 0, sizeof(d));

	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= 10; i++)
	{
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}

	print(n, k);
	return 0;
}
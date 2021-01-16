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

int main()
{
	F_I;

	/*

	���� 17436�� : �Ҽ��� ��� (����/������ ���� : Inclusion-exclusion Principle)

	- a�� b�� ������ : a+b - a�� b�� ������  =>  (�Ѱ����� ����) - (�ΰ����� ������)
	- a/b/c�� ������ : a+b+c  - (�ΰ����� ������) + (3������ ������) => (�Ѱ����� ����) - (�ΰ����� ������) + (�������� ������)

	...

	- n���� ������ : (�Ѱ��� ����) - (�ΰ����� ������) + (�������� ������) - (4������ ������)+ ...
	=> ¦�����϶��� ���ְ�, Ȧ�����϶��� �����ش�.

	*/

	ll arr[15];

	ll n, m;
	ll sum = 0;
	ll ans = 0;
	cin >> n >> m;
	

	for (ll i = 0; i < n; i++)
		cin >> arr[i];

	//���� �ȵǸ� ���� �ᰡ�鼭 �غ���!
	for (ll i = 1; i < ((ll)1 << n); i++)
	{
		ll cnt = 0;
		ll num = 1;

		for (ll j = 0; j < n; j++)
		{
			//j��° �Ҽ��� �����ϴ� �۾� => �Ҽ� 2�� 3�� ���ߴٴ� ��, m���� ���� ��������, �װ͵��� ���� 6�� ����� ������ ���ϰڴٴ� �ǹ��̴�!
			//�׷��� num���ٰ� �Ҽ����� ���ϴ� ���̴�.
			if (i & ((ll)1 << j))
			{
				num *= arr[j]; 
				cnt += 1;
			}
		}

		if (cnt % 2 == 0) //¦�����϶��� ���ְ�,
		{
			ans -= (m / num); //m�� 100�̰�, num�� 2*3 = 6�̶��, 100���� ���� 6�� ����� ������ , 100/6 = 16���̴�.
		}
		else // Ȧ�����϶��� �����ش�.
			ans += (m / num);
	}

	cout << ans << '\n';

	return 0;
}
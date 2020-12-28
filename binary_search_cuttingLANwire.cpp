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


ll k, n;
ll ran[10001];
ll calc(ll mid)
{
	ll ans = 0;
	for (int i = 0; i < k; i++)
	{
		ans += (ran[i] / mid);
	}
	return ans;
}
int main() //���� 1654�� : ���� �ڸ��� (�̺� Ž��), c++

{
	F_I;

	
	ll m = -1; //m : ������ �߿��� ���� �� ����.
	cin >> k >> n;
	for (ll i = 0; i < k; i++)
	{
		cin >> ran[i];
		if (m < ran[i])
			m = ran[i];
	}
	ll start = 1;
	ll end = m;
	ll mid;
	ll x = -1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		ll cnt = calc(mid);
		if (cnt >= n)
		{
			/* ������ ���̷� ������ �߶��� ��, 
			
			1) �� ������ ���ϴ� ����(n) ���� ���� ���ü��� �ְ�, 
			2) ���� ���� �ְ�, 
			3) ���� ���� ���� �ִµ�,

			3)���� ���� ������ ����, ���� else ������ ó���� �ϸ� �Ǵ°��̰�, 1),2)�� ��쿡�� �� if���� ���� ����ε�,
			1), 2)���� ���ϴ� ��� �߿���, ������ ������ �ִ밪�� ���ϴ� ����(�� �κи� ����)�̹Ƿ�, �ִ밪�� ���ϴ� ó���� ���� ���־�� �Ѵ�.

			*/
			if (mid > x)    
				x = mid;
				
			start = mid + 1;
		}
		else if (cnt < n)
		{
			end = mid - 1;
		}
		
	}

	cout << x << '\n'; //�ִ밪 ���

	return 0;

}
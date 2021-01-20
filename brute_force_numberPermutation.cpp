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
	//���� 16943�� : ���� ���ġ (���Ʈ ���� + stoi)

	/*
	* 
	���� a�� string ���� �Է¹޾Ƽ�, ������ ���ҵ��� next_permutation���� ������ �����鼭 ���ϸ� �ȴ�.
	a�� �ִ밡 1e9�̹Ƿ�, O(10!) = 3628800�̹Ƿ� ����� �ð� ���� �����ϴ�.
	
	- ���ڿ��� ������ �ٲٴ� ��� (stoi) >> �߿��� �Լ��̹Ƿ� �� �ؾ���� �� ��!
	*/
	string a;
	int b;
	cin >> a >> b;
	int ans = -1;
	sort(a.begin(), a.end());

	do
	{
		int num = stoi(a);
		if (a[0] != '0' && num < b)
		{
			if (ans < num)
				ans = num;
		}

	} while (next_permutation(a.begin(), a.end()));

	cout << ans << '\n';

	return 0;
}
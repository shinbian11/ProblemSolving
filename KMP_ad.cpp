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
	���� 1305�� : ���� (KMP �˰���)
	*/

	int n;
	cin >> n;
	vector<int> fail(n);
	fail[0] = 0;
	string ad;
	cin >> ad;

	int idx, j = 0;
	/*
	idx    0 1 2 3 4 5 6 7 8 9

	ad     a b a c a b a b a c
	fail   0 0 1 0 1 2 3 2 3 4

	- fail[idx]�� �ǹ� : ���� fail[5]=2 ��, ó�� ���λ�κ��� 2����, ������ ���̻�κ��� 2���ڰ� ���ٴ� �ǹ�.

	(�߿�)
	- idx�� 7�϶�, (j�� 3�̰�, idx�� 7�� ��Ȳ) > ad[7] != ad[3] �̹Ƿ� fail[7]�� 0�� �־�� �ϳ�?? �ƴϴ�.
	  ��� ad[7]�� ad[3]�� ���� ������, �պκб����� �������Ƿ� �� ������ �̿� �ؾ� �Ѵ�. 
	  j�� 1 ���ҽ��� j�� 6�϶��� ����. fail[6]=3 �̶�� �ǹ̴�, ���λ�/���̻� �κ� 3���ھ��� ��ġ�ߴٴ� �ǹ��̴�('aba' c 'aba')
	  �̶� ��ġ�ϴ� �κ��� ���̰� 3�̹Ƿ�, ���� ��ġ�ϴ� �κ��� ������ �ε����� 2�ϰ��̴�. (�ε����� 0���� �����̹Ƿ�, �� aba���� ������ a�� idx�� 2�̴�)
	  �� �κ����� ���ư��� �׶��� fail�Լ��� ����! �� j�� fail[j-1]���� �ְ�, �׶��� fail[j]�� �������ڴ� �ǹ��̴�. 
	  fail[3-1] = 1�̴�. j�� 1�� �ְ� , fail[1] �� fail[7] (=fail[i])�� ������ ����. �����Ƿ� fail[7] = j+1 = 1+1 = 2�� ����.
	*/
	for (idx = 1; idx < n; idx++)
	{
		while (j > 0 && ad[idx] != ad[j])
			j = fail[j - 1];

		if (ad[idx] == ad[j]) //i��° ���ڿ� j��° ���ڰ� ���ٸ�, fail �Լ� ���� 1 ��������, ����� ���λ�� ���̻��� ���̸� +1 ��Ų��.
		{
			fail[idx] = j + 1;
			j += 1;
		}
		else
			fail[idx] = 0;
	}
	
	cout << n - fail[n - 1] << '\n';
	return 0;
}
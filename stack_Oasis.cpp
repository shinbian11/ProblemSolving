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
	 
	���� 3015�� : ���ƽý� ����� (������ ����)

	- a �� b �� ������, a���� b�� �� ũ�ٸ�, b �ڿ� �� �������� a�� �� �� ���ٴ� ����� �̿��Ѵ�.
	*** stack���� ���� ���� ���� �ִ� '���ɼ�'�� �ִ� ������'��' �־���� ������ �Ѵ�.

	n=7�̰�, ������ Ű�� 2 4 1 2 2 5 1 �� ��, 2�� �ְ�,

	- 4�� 2���� ũ�ϱ�, (2,4) �� ���� ���� �� �ִ�. (���� + 1)
	����, 2 �ڿ� 4 �� ���� �̻�, 4 �ڿ��� 2�� ���� Ȯ���� ���� �������Ƿ�, 2�� pop ��Ų��.
	
	- 1�� 4���� �����ϱ�, �׳� ���ÿ� �ְ�, (1,4) �� ���� ���� �� �ִ�. (����+1)

	- 2�� 1���� ũ�ϱ�, (1,2) �� ���� ���� �� �ִ�. (���� + 1)
	����, 1 �ڿ� 2 �� ���� �̻�, 2 �ڿ��� 1�� ���� Ȯ���� ���� �������Ƿ�, 1�� pop ��Ų��.
	���ÿ� ���� 4�� 2�� �� �� �����Ƿ�(���̿� �� ���� �ֵ鸸.. ���̿� 1�ۿ� �����ϱ� ���� �� �� �ִ�.) (4,2)�� ���� ���� �� �ִ�. (����+1)

	- 2�� 2���� ũ�ų� ������, (2,2)�� ���� ���� �� �ִ�. (����+1)
	����, Ű�� ���� ��쿡�� �ߺ��̶�� ���� ǥ���ؾ� �Ѵ�.  if (v.top().first == a.first) �� �κ� ó��!

	.... �� �ݺ�!

	*/
	ll n;
	cin >> n;
	stack<pl> v;

	ll sum = 0;

	for (ll i = 0; i < n; i++)
	{
		ll h;
		cin >> h;
		pi a = make_pair(h, 1);

		while (!v.empty())
		{
			if (v.top().first <= a.first) //���ÿ� �ִ� Ű �� �� ��� ���� Ű���� ���� �ֵ��� +1 �ϰ� �� ������
			{
				sum += v.top().second;

				if (v.top().first == a.first)
				{
					a.second = v.top().second + 1;
				}
				v.pop();
			}
			else
				break;
		}

		if (!v.empty()) //while�� ������ �Դµ��� v�� ������� �ʴٴ°�, ��� ���� Ű���� ū Ű�� �ּ� �ϳ� �ִٴ� �ǹ��̰�, �� ���� ���� ���� �� �����Ƿ�, +1 �Ѵ�.
			sum += 1;

		v.push(a); //push
	}

	cout << sum << '\n';

	return 0;
}
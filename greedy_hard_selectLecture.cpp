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


int cmp(tuple<int,int,bool>& a, tuple<int, int, bool>& b)
{
	return get<0>(a) > get<0>(b);
}

int main()
{
	F_I;

	/*
	- ���� 2109�� : ��ȸ ���� (c++, �׸��� �˰���). 
	���� �ð��� ������ 10000���� 1���� ���, ���� �ð����� ū �ð����� ��� ���õ� �� �ִ� �ĺ����̴�.
	�ֳ��ϸ�, d�� �ȿ��� �ϸ� �ȴٴ� �ǹ̴�, �� �� day�� �Ǿ��� �� �ϴ� �ǹ̵� ������, �� day�� �Ǳ� ���� �ص� �ȴٴ� �ǹ��̴�.

	c.f)

	n = 3

	p  d
	1  1

	10 2

	10 2 

	> �̷� ��쿡��, 1+10 �ؼ� 11���� �ƴ϶�, 10+10 = 20���� ���̴�. 
	���� 1�Ͽ� 1��¥�� ���Ǹ� �ؼ� �Ϸ縦 �Һ��ϴ� �� ���ٴ�(�̷��� �Ǹ� 10�� ¥�� ���Ǵ� 1���ۿ� ����)
	2�� ���� 10�� ¥�� ���Ǹ� �ΰ� �ϴ°� �ξ� ����. 
	(���� 1���� 1���� �ҿ�Ǵ� �� ���������̴�.)
	
	*/

	int n;
	cin >> n;
	vector< tuple<int,int,bool> > v; //p��, d��, �湮ó��

	for (int i = 0; i < n; i++)
	{
		int p, d;
		cin >> p >> d;
		v.push_back(make_tuple(d, p, false));
	}

	sort(v.begin(), v.end(), cmp); //d���� �������� ��������(ū ������) ������ ��.

	int ans = 0;
	
	//���ĵ� �κп���, ����ð����� �Էµ� �ð��� �� ũ��, ���� ���� �� �ִ� �ĺ����� �ǹǷ�, �� �ĺ��� �߿��� ���� ���� ���� �ִ� ���Ǹ� ���ϸ� �ȴ�.
	for (int i = 10000; i >= 1; i--)
	{
		int m = -1;
		int m_idx = -1;
		for (int j = 0; j < n; j++)
		{
			if (i <= get<0>(v[j]) && get<2>(v[j]) == false) //����ð�(i)���� �Էµ� �ð�(get<0>(v[j]))�� �� ũ��, �̹� ������ ���ǰ� �ƴ϶��,
			{
				if (m < get<1>(v[j])) //�װ͵��� ��� �ĺ��� �ǰ�, �� �ĺ��� �߿��� ���� ���� ���� �ִ� ����(get<1>(v[j]) �߿����� �ִ�)�� ������ ���� ���̴�.
				{
					m = get<1>(v[j]);
					m_idx = j;
				}
			}
		}
		if (m != -1 && m_idx != -1)
		{
			ans += m;
			get<2>(v[m_idx]) = true; //������ ���Ǵ� �湮�ߴٰ� ó���� �ؾ�, ���߿� �� ���߼��õǴ� ���� ����!
		}

	}

	cout << ans << '\n'; //���� �� ���

	return 0;
}

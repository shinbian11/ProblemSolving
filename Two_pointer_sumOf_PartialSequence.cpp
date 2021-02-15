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

	//[����] 1208�� : �κм����� �� 2 (�߰����� ������ + �� ������)

	/*
	- ������ ���� ������ �ִ� 40���̰�, �׷��Ƿ� �� ������ �κ� ������ ������ �ִ� 2^40�������� �����ϴ�.
	������ 2^40�� �ð��ʰ��� �߻��� ������ ū ���̹Ƿ�, �� ������δ� Ǯ �� ����
	- ������ �� ����� �ɰ�� (�ݹݾ�) , ������ ���� 2^20, 2^20������ �κ� ������ ���� ���ϴ� ������ �ϴ� ����� ���?
	�̷��� �Ǹ� 2^20 + 2^20 �̶� ����� �����ϴ�!
	- �̰��� �߰����� ������(meet in the middle) + �� ������ ����̴�!!
	- �պκ� �迭�� ���� �� �ִ� �κ� ������ �����, �޺κ� �迭�� ���� �� �ִ� �κ� ������ ���� ���� ���ϸ鼭 Ž���غ���!
	*/

	int n, s;
	cin >> n >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int m = n / 2;
	n = n - m;

	vector<int> first(1<<n); //�պκ� ���� (2^n ��)
	vector<int> second(1<<m); //�޺κ� ���� (2^m ��)

	//������ �κ� ���� ������ֱ�
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
				first[i] += v[j];
		}
		
	}
	for (int i = 0; i < (1 << m); i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i & (1 << j))
				second[i] += v[j+n];
		}
	}

	//first�� ��������, second�� ������������ ����!
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	reverse(second.begin(), second.end());

	n = (1 << n);
	m = (1 << m);
	int up= 0, down = 0;
	ll ans = 0;

	while (up < n && down < m)
	{
		if (first[up] + second[down] == s) //s ���� first[up] + second[down]�� ������ >> (first[up]�� ���� ���� ���� X second[down]�� ���� ���� ����)�� ���Ѵ�.
		{
			ll up_cnt = 1, down_cnt = 1;
			up += 1;
			down += 1;

			while (up < n && first[up] == first[up - 1])
			{
				up_cnt += 1;
				up += 1;
			}
			while (down < m && second[down] == second[down - 1])
			{
				down_cnt += 1;
				down += 1;
			}

			ans += (up_cnt * down_cnt);
		}
		else if (first[up] + second[down] < s) //s ���� first[up] + second[down]���� ũ�� >> up�� 1 �������Ѽ�, first���� �� ū ���� ã�´�. first�� ���������̴ϱ�.
		{
			up += 1;
		}
		else if (first[up] + second[down] > s) //s ���� first[up] + second[down]���� ������ >> down�� 1 �������Ѽ�, second���� �� ���� ���� ã�´�. second�� ���������̴ϱ�.
		{
			down += 1;	
		}
		
	}
	/* 
	s�� 0�̰�, ���� v�� 1 2 3 4 ��, 
	first��  0 1 2 3 
	second�� 7 4 3 0 �ε�,
	�̷��� �Ǹ� �κм����� ������ ã���� �ϴ� s�� ã�� ���� �����Ƿ� 0�� ���̾�� ������,
	�κ� �������� �׻� 0�� ���ԵǹǷ�, ���� ������ �˰��� ���ؼ��� first[0] + second[3] = 0 + 0 = 0����, ans�� 1�� �ȴ�.
	��, s=0 �ϋ�, ans�� 1 ���ҽ��Ѿ� �Ѵ�.
	*/
	if (s == 0) ans -= 1;

	cout << ans << '\n';
	
	return 0;
}



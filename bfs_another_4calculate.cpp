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

	//���� 14395 : 4���� (�̰͵� bfs �� Ǯ �� �ִ� �����̴�.)

	ll n, m;
	cin >> n >> m;

	set<ll> s; //set : �ߺ� ��� x, �ڵ������� �����ͺ��� ��������!
	queue<pair<ll, string>> q;
	s.insert(n);

	q.push(make_pair(n, ""));

	while (!q.empty())
	{
		ll x;
		string str;
		tie(x, str) = q.front();
		q.pop();

		if (x == m) //x�� m�̶� ������
		{
			if (str.length() == 0) //str ���̰� 0�̶�� ��, �ѹ��� �����ڰ� ����� �ʾҴٴ� ���̹Ƿ�, ó������ n==m �̾��ٴ� �ǹ��̴�.
				cout << 0 << '\n';
			else
			{
				cout << str << '\n';
			}
			return 0;
		}


		//������ �ƽ�Ű �ڵ� ������ * + - / �����̴�.
		if (x * x >= 1 && s.count(x * x) == 0) //x*x�� �� ���� && x*x�� �ѹ��� �غ����� ����� ��. s.count(x*x)==1 �̸� �̹� �ѹ� �Ȱ��� ������� �ٲ� ���� �ִٴ� �ǹ��̹Ƿ� �ȵ�.
		{
			s.insert(x * x);
			q.push(make_pair(x * x, str + "*"));
		}
		if (x + x >= 1 && s.count(x + x) == 0) //x+x�� �� ���� && x+x�� �ѹ��� �غ����� ����� ��. s.count(x+x)==1 �̸� �̹� �ѹ� �Ȱ��� ������� �ٲ� ���� �ִٴ� �ǹ��̹Ƿ� �ȵ�.
		{
			s.insert(x + x);
			q.push(make_pair(x + x, str + "+"));
		}
		if (x - x >= 0 && s.count(x - x) == 0) //x-x�� �� ���� && x-x�� �ѹ��� �غ����� ����� ��. s.count(x-x)==1 �̸� �̹� �ѹ� �Ȱ��� ������� �ٲ� ���� �ִٴ� �ǹ��̹Ƿ� �ȵ�.
		{
			s.insert(x - x);
			q.push(make_pair(x - x, str + "-"));
		}

		if (x != 0 && x / x >= 1 && s.count(x / x) == 0) //x/x�� �� ���� && x/x�� �ѹ��� �غ����� ����� ��. s.count(x/x)==1 �̸� �̹� �ѹ� �Ȱ��� ������� �ٲ� ���� �ִٴ� �ǹ��̹Ƿ� �ȵ�.
		{
			s.insert(x / x);
			q.push(make_pair(x / x, str + "/"));
		}
	}

	cout << -1 << '\n';


	return 0;
}
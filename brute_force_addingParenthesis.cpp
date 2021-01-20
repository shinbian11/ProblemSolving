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
struct Info
{
	int num;
	int op; // 0: ������, 1: + , 2: - ,3: *
};
int main()
{
	F_I;

	//[����] 16637�� : ��ȣ �߰��ϱ� (���Ʈ ���� + ���)

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<Info> v(n);
	//�����ڿ� �ǿ������� �������� ���� ����
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) //������
		{
			v[i].num = s[i] - '0';
			v[i].op = 0;
		}
		else //�ǿ�����
		{
			v[i].num = 0;
			if (s[i] == '+')
				v[i].op = 1;
			else if (s[i] == '-')
				v[i].op = 2;
			else if (s[i] == '*')
				v[i].op = 3;
		}

	}

	int mx = -2147483648; //���� ��� ��

	int m = (n - 1) / 2; //�������� ����

	for (int i = 0; i < (1 << m); i++)
	{
		//step1) ��ȣ ġ�� ����� ���鿡 ���� ���� ���� (���Ʈ ����)
		bool flag = false;
		for (int j = 0; j < m - 1; j++)
		{
			//j��° �����ڿ� j+1 ��° �����ڰ� ���������� ��ȣ�� ������ �ȵȴ�.
			//�����ڰ� �������� ��ȣ�� ������ > e.g.) (1+(3*4)) , (1+3+2) >> �̷��� �ȵȴٴ� �ǹ�! ���� ������ �������� ����.
			if ((i & (1 << j)) > 0 && (i & (1 << (j + 1))) > 0) 
			{
				flag = true;
			}
		}

		if (flag)
		{
			continue;
		}

		vector<Info> b(n);
		b = v;

		//step2) ��ȣ�� ������, ����ϱ� ���� ���� ������
		for (int j = 0; j < m; j++) 
		{
			if ((i & (1 << j)) > 0) //j��° ����
			{
				int idx = 2 * j + 1;
				if (b[idx].op == 1) //e.g.) 1+5 �� 6+0 ���� �ٲ� -> �׷��� ���ӵǴ� ����� �߸��� ���� �������� ����.
				{
					b[idx - 1].num += b[idx + 1].num;
					b[idx + 1].num = 0;
				}
				else if (b[idx].op == 2) //e.g.) 1-5 �� -4+0 ���� �ٲ� -> �׷��� ���ӵǴ� ����� �߸��� ���� �������� ����.
				{
					b[idx - 1].num -= b[idx + 1].num;
					b[idx].op = 1;
					b[idx + 1].num = 0;
				}
				else if (b[idx].op == 3) // e.g.)  3*4 �� 12*1 ���� �ٲ� -> �׷��� ���ӵǴ� ����� �߸��� ���� �������� ����.
				{
					b[idx - 1].num *= b[idx + 1].num;
					b[idx].op = 1;
					b[idx + 1].num = 0;
				}
			}
		}

		//step3 : ������ ���� ����ؼ� �ִ밪 ��󳻱�
		int ans = b[0].num;
		for (int j = 0; j < m; j++)
		{
			int idx = 2 * j + 1;
			if (b[idx].op == 1)
				ans += b[idx + 1].num;
			else if (b[idx].op == 2)
				ans -= b[idx + 1].num;
			else if (b[idx].op == 3)
				ans *= b[idx + 1].num;
		}

		if (mx < ans)
			mx = ans;
	}

	cout << mx << '\n';

	return 0;
}
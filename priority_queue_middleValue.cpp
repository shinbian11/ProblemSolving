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
	���� 1655�� : ����� ���ؿ� (�켱���� ť)
	- ���� ���� ������ sort �Լ��� �̿��Ͽ� ����� ����ϴ� ���� O(n* nlogn)�� �ҿ�ǹǷ� �ð��ʰ��̴�!
	- ���Ḯ��Ʈ�� �����ص� O(n*n)�̹Ƿ� �ð��ʰ��̴�!

	- �켱���� ť 2���� ���� �����ϴ� ������� Ǯ��!
	- 2���� ������ �׻� �����ؾ� �Ѵ�
	���� 1. l�� �ִ� ��� ������ �׻� r�� �ִ� ��� ������ �۾ƾ� �Ѵ�. �� l�� �ִ밪 <= r�� �ִ밪
	���� 2. l�� ���� ������ r�� ���� ������ ���ƾ� �Ѵ�(���� n/2����) => n�� Ȧ����� l�� ���� ������ r�� ���� �������� 1�� �� ���ƾ� �Ѵ�.

	l�� �ִ� ���̹Ƿ�, �׻� top ���� l�� �ִ� ���ҵ� �� ���� ���̴�.
	r�� �ּ� ���̹Ƿ�, �׻� top ���� r�� �ִ� ���ҵ� �� ���� ���̴�.
	*/

	priority_queue<int, vector<int>> l; //����(l�� �ִ� ��)
	priority_queue<int, vector<int>, greater<int> > r;// ������(r�� �ּ� ��)

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{

		int x;
		cin >> x;

		//���� 1�� �����ϱ� ���� �ݺ� �۾�

		if (l.empty() || r.empty()) //�� ó������ l�� �־���� �Ѵ�. 
			l.push(x);
		else
		{
			if (l.top() >= x) //�̹��� �ԷµǾ� ���� x�� l�� �ִ밪���� ������, l�� ���;� ��
				l.push(x);
			else if (r.top() <= x) //�̹��� �ԷµǾ� ���� x�� r�� �ּҰ����� ũ��, r�� ���;� ��
				r.push(x);
			else //�̹��� �ԷµǾ� ���� x�� l�� �ִ밪�� r�� �ּҰ� ���̿� �ִ� ���̸�, l�� ���;� ��.
				l.push(x);
		}

		// ���� 2�� �����ϱ� ���� �ݺ� �۾�

		while (true)
		{
			if ((l.size() == r.size()) || (l.size() == r.size() + 1)) //���� 2�� ������ ������ �ݺ�
				break;
			if (l.size() > r.size())
			{
				r.push(l.top());
				l.pop();
			}
			else if (l.size() < r.size())
			{
				l.push(r.top());
				r.pop();
			}
		}

		cout << l.top() << '\n'; //�׻� l�� �ִ��� �߰����̴�.
	}
	return 0;

}
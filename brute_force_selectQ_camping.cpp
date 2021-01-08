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

int hard[16]; //������ ���̵�
bool selectQ[16]; //������ �����ߴ����� ����(e.g. selectQ[i]�� true�̸� i��° ������ �����ߴٴ� �ǹ�.
int n, l, r, x;

int select_question(int index)
{
	
	if (index == n) //Ż������!
	{
		int cnt = 0; //�� ���� ���� üŷ
		int sum = 0; //�� �������� ���̵��� ��

		//�� ���� �� �ְ� ���̵� h, ���� ���̵� e
		int h = -1;
		int e = 1e9; 

		for (int i = 0; i < n; i++)
		{
			if (selectQ[i])
			{
				cnt += 1;
				sum += hard[i];

				if (h < hard[i])
					h = hard[i];

				if (e > hard[i])
					e = hard[i];
			}
			
		}
		if (cnt >= 2 && sum >= l && sum <= r && (h - e) >= x)
			return 1; //������ ���� 1���� ����� ��!
		else
			return 0;
	}

	selectQ[index] = true; //index��° ������ �������� ��
	int a1 = select_question(index + 1);

	selectQ[index] = false; //index��° ������ �������� �ʾ��� ��
	int a2 = select_question(index + 1);

	return a1 + a2;
}

int main()
{
	F_I;
	 /*
	 ���� 16938�� : ķ�� �غ�
	- ������ �� �� �̻� ���� �ϴϱ� ���� ����� ���� �� 2^n���̴�. O(2^n) �̰� n<=15 �̹Ƿ� 2^15 = 32768 >>> ���Ʈ ������ ����!
	- ������ ������ �� ���� �� ���� ������ ���õ� ���ǿ� �����ϴ��� �ǵ� �ϴ� ����� �ְ�(�� �ҽ��ڵ�)
	- ������ �ϳ��� �������� üŷ�ϴ� ����� �ִ�.
	- ���� �ð����⵵�� ���� ���̰� ���� �ʰ�, ���������� �ణ�� ���̰� �ִ�.
	 */

	//int n, l, r, x;
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++)
		cin >> hard[i]; //������ ���̵� ����

	cout << select_question(0) << '\n';

	return 0;
}
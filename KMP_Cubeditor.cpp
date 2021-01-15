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

vector<int> getFailFunction(string& a) //���ڿ� a�� ���� fail�Լ� ���ϴ� ���
{
	int num = a.length();
	vector<int> failfunc(num);
	int j = 0;
	failfunc[0] = 0;
	for (int i = 1; i < num; i++)
	{
		while (j > 0 && a[i] != a[j])
			j = failfunc[j - 1];
		if (a[i] == a[j])
		{
			failfunc[i] = j + 1;
			j += 1;
		}
		else
			failfunc[i] = 0;
	}
	
	return failfunc;
}

int main()
{
	F_I;
	/*
	
	<KMP �˰���>

	- KMP �˰�����, S�� ��ü ���ڿ�, P�� ã���� �ϴ� ������ ��, S �ȿ� P�� ���ԵǾ� �ִ����� �Ǵ��ϴ� �˰����̴�.
	- KMP �� �ð����⵵ :  O(��S�� + ��P��)

	---------------------------------------------------------------
	���� 1701�� : Cubeditor (KMP)

	- 2�� �̻� ������ �κй��ڿ� �� �߿����� �ִ� ���̸� ���ϴ� ����. 
	- fail �Լ��� �ִ밪�� ���ϸ� �Ǵ� �ܼ��� �����̴�. 
	�ֳ��ϸ� fail �Լ��� ���� ��ü��, �ִ���� ���� �����ϴ� �Լ��̰�, ���� 2�� �̻� ������ �ʴ´ٸ� fail �Լ��� Ư�� ���� ������� ���ϱ� �����̴�.
	
	e.g.)
	pattern   a b c d a b a b c a a
	fail      0 0 0 0 1 2 1 2 3 1 1
	
	- �̶�, fail �Լ��� �ִ밪�� 3�� �� �ڸ����� ��ġ�Ǵ� ���λ�/���̻��� �ִ� ���� ���̰�(3), 0 �� �ƴ� ���̹Ƿ�, �̹� �ѹ� ���� ���ڿ��̶�� ���̴�.

	- �ٽ� ����, �Է¹��� ���ڿ��� fail �Լ��� ����, �� fail �Լ� �� �߿� �ִ밪�� ���ϸ� �ȴ�!


	
	- �׷���, �� fail �Լ��� ���λ�/���̻� �϶����� �ش�Ǵ� �Լ��̴�.
	- �� ������ �ݺ��Ǵ� ���ڿ��� �� ���λ�/���̻� ��ġ�� ���� �ʾƵ� �ȴ�.
	
	e.g.)
	pattern   d a b c d a b a b c a a
	fail      0 0 0 0 1 2 0 0 0 0 0 0 
	
	- �̷��� �����µ�, �׷��ٰ� ���� 2�� �ƴϴ�! ������ ���� 3�̴�. (abc)
	- �� abc�� ���̻�/���λ簡 �ƴ϶�, ���ڿ� �߰��� �����ִ�.

	- ��, ���� �� �ִ� ��� ���ڿ��� ���� fail �Լ��� ���� ���ϰ�, �� fail �Լ��� �ִ� ��� ���� �� �ִ밪�� ���ϸ� �ȴ�.

	d�϶�
	d a b�϶�
	d a b c�϶�
	d a b c d�϶�
	d a b c d a�϶�
	d a b c d a b�϶�
	d a b c d a b a�϶�
	d a b c d a b a b�϶�
	d a b c d a b a b c�϶� 
	d a b c d a b a b c a�϶�
	d a b c d a b a b c a a�϶�
	
	- ���� fail �Լ��� ���ؾ� �Ѵ�.
	*/

	int ans = -1;
	string s;
	cin >> s;
	int n = s.length();

	//���� �� �ִ� ��� ���ڿ��� ���� fail �Լ��� ���� ���ؼ� fail �Լ����� �ִ밪�� ���ϴ� ����
	for (int i = 0; i < n; i++)
	{
		string a = s.substr(i, n - i); //i��° idx���� n-i���� �����ؼ� fail �Լ� ���ϱ�
		vector<int> failfunc = getFailFunction(a);
		for (int j = 0; j < n - i; j++)
		{
			if (ans < failfunc[j])
				ans = failfunc[j];
		}
	}

	cout << ans << '\n'; //��� fail �Լ��� �߿����� �ִ� ���

	return 0;
}
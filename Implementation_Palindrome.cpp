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

	//[����] 1213�� : �Ӹ���� ����� (����, �Ӹ������ ����)

	vector<int> alpha(26);
	string str;
	cin >> str;
	int len = str.length();

	//�Ӹ������ ���� 2����

	//1. ��� ���ڰ� ¦����
	//2. �� ���ڰ� Ȧ����, ������ ��� ���ڴ� ¦����

	for (int i = 0; i < len; i++)
		alpha[str[i]-'A'] += 1; //���ڿ��� ������ �ִ� ������ �������� ���

	int even = 0, odd = 0, odd_number_idx = 0;
	for (int i = 0; i < alpha.size(); i++)
	{
		if (alpha[i] == 0) continue;

		if (alpha[i] % 2 == 0) even += 1; //¦�� ����
		else
		{
			odd += 1; //Ȧ�� ���� 
			odd_number_idx = i; 
		}
	}

	string ans = "";

	if (odd <= 1) //1. ��� ���ڰ� ¦����, 2. �� ���ڰ� Ȧ����, ������ ��� ���ڴ� ¦������ ���
	{
		for (int i = 0; i < alpha.size(); i++)
		{
			for (int j = 0; j < alpha[i] / 2; j++) //�� ���ĺ��� ������ �� ���� ����Ѵ�.
			{
				ans += (char)((int)'A' + i);
			}

		}

		string ans2 = ans;
		reverse(ans2.begin(), ans2.end()); //�Ӹ������ ������ �ϹǷ�, ans�� reverse ���ڿ��� ���δ�.

		if (odd == 1) //2���� ��쿡��
			ans += (char)((int)'A' + odd_number_idx); //Ȧ�� ������ ������ ���ڿ��� �߰��� �� �� ���δ�.

		ans += ans2; //������ ���ڿ��� �ڿ� ���δ�. (�Ӹ������ ����)


	}
	else // Ȧ�� ������ 2�� �̻�. �Ӹ���� �Ұ�
	{
		ans = "I'm Sorry Hansoo";
	}
	
	cout << ans << '\n';

	return 0;
}
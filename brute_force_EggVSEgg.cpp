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

int s[10]; //s[i] : i��° ����� ������
int w[10]; //w[i] : i��° ����� ����
int n;

int go(int index) //index ��° ����� �տ� ��� ���� ��,
{
	if (index == n)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++) //���� ����� ���� ����
		{
			if (s[i] <= 0)
				cnt += 1;
		}
		return cnt;
	}

	if (s[index] <= 0) //�տ� ��� �ִ� ����� ���� �����϶�, �׳� �� �������� �Ѿ��
	{
		return go(index + 1);
	}

	int ans = 0; //�� �� �ִ� ����� �ִ� ����

	bool flag = false;

	for (int i = 0; i < n; i++)
	{
		int j = index; // ���� ��� �ִ� ����� �ε���
		if (i == j) continue; //���� ������� ���� �� �� ����. �ݵ�� �ٸ� ������� �����ϴϱ�!
		if (s[i] > 0)
		{
			flag = true; //�� �� �ִ� ����� �� �Ѱ��� ������, flag �� true �� �ٲ۴�.

			s[i] -= w[j];
			s[j] -= w[i];

			int tmp = go(index + 1); //i��° ����� j��° ����� ���ٰ� �����ϰ� �� �������� �Ѿ�� ���� ��

			if (ans < tmp) 
				ans = tmp; //�ִ밪 ��

			//���󺹱�
			s[i] += w[j];
			s[j] += w[i];
		}
	}
	if (!flag) //flag�� false��� �ǹ�.. >> �� �� �ִ� ����� �� �Ѱ��� ���ٴ� �ǹ� => �׳� �� �������� �Ѿ��
	{
		return go(index + 1);
	}

	return ans;
}

int main()
{
	F_I;

	//[����] 16987�� : ������� ���ġ�� (���Ʈ ����)
	// N <= 8 �̰�, ��� �Ѱ��� �� �� �ִ� ����� ����� ���� (N-1)�����̴�. �� (N-1)^N �� �ð����⵵�̴�. ����� ���Ʈ ������ ����!

	
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> s[i] >> w[i];

	cout << go(0) << '\n';

	return 0;
}
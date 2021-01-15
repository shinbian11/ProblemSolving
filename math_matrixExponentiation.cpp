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


//������ �����ε�! *�� ������ ������ �ƴ϶� ����� ��������!
vector<vector<int>> operator *(const vector<vector<int>>& a, const vector<vector<int>>& b) 
{
	int n = a[0].size();
	vector<vector<int>> ans(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				ans[i][j] += (a[i][k] * b[k][j]);
				ans[i][j] %= 1000;
			}
		}
	}

	return ans;
}

int main()
{
	F_I;

	/* 
	���� 10830�� : ��� ���� (���� + �ŵ������� ������ �����ε�)
	*/
	int n;
	ll m;
	cin >> n >> m;

	vector<vector<int>> arr(n, vector<int>(n));
	vector<vector<int>> matrix_init(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) //�������
	{
		matrix_init[i][i] = 1;
	}

	//������ �ŵ������� ������ ����. �ٸ�, ���⼭�� ����� �ŵ������̹Ƿ� '������ �����ε�'�� �̿��Ͽ�, * �� ������ ���� �������־�� �Ѵ�.
	while (true) 
	{
		if (m == 0)
			break;
		if (m % 2 != 0)
		{
			//������ �ŵ����������� matrix_init �ڸ��� 1�� ����. ����� �ŵ����������� ��������� ������ 1�� ���� ������ �Ѵ�.
			matrix_init = matrix_init * arr; 
		}
		arr = arr * arr;
		m /= 2;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix_init[i][j] << ' ';

		cout << '\n';
	}

	return 0;
}
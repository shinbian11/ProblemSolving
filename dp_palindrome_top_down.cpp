#include <bits/stdc++.h>
//#include <unordered_set>
//#include <unordered_map>

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

int arr[2004];
int d[2004][2004];

int dp(int i, int j)
{
	if (d[i][j] >= 0) return d[i][j]; //memoization

	if (i == j) //���� 1
		return d[i][j] = 1;

	else if (max(i, j) - min(i, j) == 1) //���� 2
	{
		if (arr[i] == arr[j])
			return d[min(i, j)][max(i, j)] = 1;
		else
			return d[min(i, j)][max(i, j)] = 0;
	}

	else //���� 3 �̻�~
	{
		if (arr[i] != arr[j])
			return d[i][j] = 0;
		else
		{
			return d[i][j] = dp(i + 1, j - 1);
		}
	}
}
int main()
{
	F_I;
	/*
	* ���� 10942�� : �Ӹ����? (dp : top-down (����Լ�) )
	* d[i][j] = i��° �ε������� j��° �ε��������� ������ �Ӹ�����̸� 1, �ƴϸ� 0
	- i��° �ε������� j��° �ε��������� ������ �Ӹ�������� �ƴ� ���! 
	���� 1. �� ���� ���� arr[i]�� arr[j]�� ����, 
	���� 2. i+1��° �ε������� j-1��° �ε��������� �Ӹ�����̸� �Ӹ�����̴�.
	*/

	memset(d, -1, sizeof(d));

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];


	//bottom-up (�ݺ���)
	//for (int i = 1; i <= n; i++) //(���� 1) i���� i������ ������ �Ӹ�����̴�.
	//	d[i][i] = 1;

	//for (int i = 1; i <= n - 1; i++)// (���� 2) arr[i]�� arr[i+1]�� ���ƾ� �Ӹ����. 
	//{
	//	if (arr[i] == arr[i + 1])
	//		d[i][i + 1] = 1;
	//	else
	//		d[i][i + 1] = 0;
	//}

	//for (int len = 3; len <= n; len++) //���� 3����~
	//{
	//	for (int start = 1; start <= n - len + 1; start++) //������
	//	{
	//		int end = start + len - 1; //����

	//		if (arr[start] == arr[end] && d[start + 1][end - 1] == 1) //���� 1 & ���� 2
	//			d[start][end] = 1;
	//		else
	//			d[start][end] = 0;
	//	}
	//}

	int m;
	cin >> m;
	while (m--)
	{
		int s, e;
		cin >> s >> e;
		cout << dp(s, e) << '\n';
	}

	return 0;
}
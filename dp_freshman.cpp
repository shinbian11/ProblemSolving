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

ll d[104][104];

int main()
{
	/*
	[����] 5557�� : 1�г� (dp, bottom-up)

	d[i][j] => i��° ������ ����ؼ� j��� ���� ���� �� �ִ� ����� ��
	e.g.) d[3][5] = 3��° ������ +,- ������ �̿��Ͽ� 5�� ����� �� �� �ִ� ����� ��

	e.g.)
	n=11 �̶��, ������ 1���� ���ϴ� ���̹Ƿ�, goal �̶�� ������ ���� �Է¹���!

	d[i][goal]��... >> i��° �� ���� ����ؼ� goal �̶�� ���� ����� �� �� �ִ� ����� ��

	a1  a2 ... + ai = goal    >> a1  a2   a(i-1) = goal-ai  >> d[i-1][goal-ai]
	a1  a2     - ai = goal    >> a1  a2   a(i-1) = goal+ai  >> d[i-1][goal+ai]

	�� 2���� ����� ���̴�.
	*/

	int n;
	cin >> n;
	n -= 1;
	vector<int> arr(n+1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	int goal;
	cin >> goal;

	d[1][arr[1]] = 1; //1��° ������ �̿��ؼ� arr[1]�� ����� ���� ��� : 1���� (1��° ���� �� arr[1]�̴ϱ�)

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (j - arr[i] >= 0) //�迭 idx ���� ����!!
				d[i][j] += d[i - 1][j - arr[i]];
			if (j + arr[i] <= 20) //�迭 idx ���� ����!!
				d[i][j] += d[i - 1][j + arr[i]];
		}
	}
	
	cout << d[n][goal] << '\n'; //n��° �� ���� ��� ����Ͽ� goal �̶�� ���� ����� ����� ��!

	return 0;
}
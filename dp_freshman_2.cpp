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
ll arr[104];


ll go(ll idx, ll ans)
{
	//��������(Ż������)-------------
	if (idx == 1 && ans == arr[1])
		return d[idx][ans] = 1;
	if (idx == 1 && ans != arr[1])
		return d[idx][ans] = 0;

	//memoization
	if (d[idx][ans] != -1)
		return d[idx][ans];
	
	//����Լ�
	ll a = 0;

	if (ans - arr[idx] >= 0)
		a += go(idx - 1, ans - arr[idx]);
	if (ans + arr[idx] <= 20)
		a += go(idx - 1, ans + arr[idx]);

	return d[idx][ans] = a;
}

int main()
{
	/*
	[����] 5557�� : 1�г� (dp, Top-down)

	d[i][j] => i��° ������ ����ؼ� j��� ���� ���� �� �ִ� ����� ��
	e.g.) d[3][5] = 3��° ������ +,- ������ �̿��Ͽ� 5�� ����� �� �� �ִ� ����� ��

	e.g.)
	n=11 �̶��, ������ 1���� ���ϴ� ���̹Ƿ�, goal �̶�� ������ ���� �Է¹���!

	d[i][goal]��... >> i��° �� ���� ����ؼ� goal �̶�� ���� ����� �� �� �ִ� ����� ��

	a1  a2 ... + ai = goal    >> a1  a2   a(i-1) = goal-ai  >> d[i-1][goal-ai]
	a1  a2     - ai = goal    >> a1  a2   a(i-1) = goal+ai  >> d[i-1][goal+ai]

	�� 2���� ����� ���̴�.
	*/

	ll n;
	cin >> n;
	n -= 1;

	memset(d, -1, sizeof(d));

	for (ll i = 1; i <= n; i++)
		cin >> arr[i];

	ll goal;
	cin >> goal;

	cout << go(n, goal) << '\n';

	return 0;
}
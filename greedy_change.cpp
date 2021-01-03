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

void change(vector<int>& a, int idx)
{
	for (int i = idx - 1; i <= idx + 1; i++)
	{
		if (i >= 0 && i < a.size())
		{
			a[i] = 1 - a[i]; //a[i] = !a[i];
		}
	}
	return;
}

/* 
vector<int> &a ��� �ϸ� �ȵ�. &�� ����ϸ� �ּҿ� ���� ��ȯ�̹Ƿ�, a�� ���� �� ��ü�� �����ϹǷ�, 
p1���� �ߴ� ������� p2�� ������� �״�� ������ �ش�. �ٵ� p1�� p2�� ���� ���Ҷ��� a�� b�� �Է¹޾��� ���� ���� �״�� �����ؾ� �ϹǷ�
check�Լ��� ù��° �Ű������� &�� ����ϸ� �ȵȴ�.
*/

pair<bool, int> check(vector<int> a, vector<int>& b) 
{
	int ans = 0;
	int size = a.size();
	for (int i = 0; i < size-1; i++)
	{
		if (a[i] != b[i])
		{
			change(a, i+1);
			ans += 1;
		}
	}
	if (a[size-1] == b[size-1])
		return make_pair(true, ans);
	else
		return make_pair(false, ans);
}

int main()
{
	//F_I;

	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; i++)
		scanf("%1d",&a[i]);

	for (int i = 0; i < n; i++)
		scanf("%1d", &b[i]);
	
	/*
	* ���� 2138�� : ������ ����ġ (�׸��� �˰��� + �Լ� �Ű������� ��/�ּҿ� ���� ����)
	
	������ ���ҵ� �߿��� �� ������ ���� �����ų �� �ִ� �ɷ��� ���� ����ġ�� ������ 1���� ���� ��Ȳ�� �ʿ��ϴ�.
	�� a �迭�� 0��° ����ġ�� ������ ���� ������ �ʾ��� ���� ����� �����Ѵ�.
	0��° ����ġ�� �����ų� ������ �ʾ�����, 0��° ������ ���� �����ų �� �ִ� �ɷ��� ���� ����ġ�� ������ 1��(1���� �ε����� ����ġ)�� �Ǵϱ�! 
	(�������� 2������. 0, 1��° �ε����� ����ġ)
	*/

	pair<bool, int> a1 = check(a, b); //a �迭�� 0��° ����ġ�� �� ������ ��

	change(a, 0); //a�迭�� 0 ��° �ε����� ����ġ ����
	pair<bool, int> a2 = check(a, b); //a �迭�� 0��° ����ġ�� ������ ��

	if (a2.first)
		a2.second += 1; //change(a,0)�� ���ؼ� �̹� ����ġ �ѹ� �������ϱ�. ���� Ƚ���� + 1 ���־�� �Ѵ�.

	
	if (!a1.first && !a2.first) //0��° ����ġ�� �� ������ ���� false�̰�, ������ ���� false�϶�
		cout << -1 << '\n'; //��� �ص� a�� b�� �ٲ� �� �����Ƿ� -1 ���
	else if (a1.first && !a2.first) //0��° ����ġ�� �� ������ ���� true�̰�, ������ ���� false�϶�
		cout << a1.second << '\n'; //0��° ����ġ�� �� ������ ���� ���� ���
	else if (!a1.first && a2.first) //0��° ����ġ�� �� ������ ���� false�̰�, ������ ���� true�϶�
		cout << a2.second << '\n'; //0��° ����ġ�� ������ ���� ���� ���
	else //0��° ����ġ�� ������ �� ������ �Ѵ� true�϶�
		cout << Min(a1.second, a2.second) << '\n'; //�� ���� �ּ� Ƚ��(�ּҰ�)�� ���
	
	return 0;
}
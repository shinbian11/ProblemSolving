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

int main()
{
	F_I;

	/*
	���� 1764�� : �躸�� (multiset �� set)

	- �赵 ���� �̸��� n��ŭ �Է��ϰ�,
	- ���� ���� �̸��� m��ŭ �Է¹����鼭, ������ �赵 ���� �̸����� ������ �̸��� �־��ٸ�, ans set���ٰ� ���� �Űܳ���!
	*/

	multiset<string> a;
	set<string> ans;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		a.insert(name);
	}
	for (int i = 0; i < m; i++)
	{
		string name;
		cin >> name;
		a.insert(name);
		if (a.count(name) == 2)
			ans.insert(name);
	}

	cout << ans.size() << '\n';
	for (set<string>::iterator it = ans.begin(); it != ans.end(); it++)
	{
		cout << *it << '\n';
	}

	return 0;
}
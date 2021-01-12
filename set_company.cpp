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
	7785�� : ȸ�翡 �ִ� ��� (set�� ����)
	- set�� �̿��Ͽ� enter�� �� ����� insert, leave�� �� ����� erase �Ѵ�. ���������� �����ִ� ������� �������� ���
	- set�� �̿��Ͽ� ����� ��, ������ ������ �������� ��� �ϴ� ����� ���!
	*/

	set<string> s;
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name, state;
		cin >> name >> state;
		if (state == "enter")
			s.insert(name);
		else if (state == "leave")
			s.erase(name);
	}

	//(set<string>::iterator it = s.begin(); it != s.end(); it++) >> ���� ���� ���
	//(set<string>::reverse_iterator it = s.rbegin(); it != s.rend(); it++) >> ���� ���
	for (set<string>::reverse_iterator it = s.rbegin(); it != s.rend(); it++)
		cout << *it << '\n';

	return 0;
}
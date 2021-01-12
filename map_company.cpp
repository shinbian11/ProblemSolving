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
	7785�� : ȸ�翡 �ִ� ��� (map�� ����)
	- map�� �̿��Ͽ� enter�� �� ����� insert, leave�� �� ����� erase �Ѵ�. ���������� �����ִ� ������� �������� ���
	- map�� �̿��Ͽ� ����� ��, ������ ������ �������� ��� �ϴ� ����� ���!
	*/

	map<string, int> s;
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name, state;
		cin >> name >> state;
		if (state == "enter")
			s.insert(make_pair(name, 0));
		else if (state == "leave")
			s.erase(name);
	}

	//set �϶�
	//(set<string>::iterator it = s.begin(); it != s.end(); it++) >> ���� ���� ���
	//(set<string>::reverse_iterator it = s.rbegin(); it != s.rend(); it++) >> ���� ���

	//map �϶�
	//(map<string, int>::iterator it = s.begin(); it != s.end(); it++) >> ���� ���� ���
	//(map<string, int>::reverse_iterator it = s.rbegin(); it != s.rend(); it++) >> ���� ���
	for (map<string, int>::reverse_iterator it = s.rbegin(); it != s.rend(); it++)
		cout << it->first << '\n'; //name�� ���

	return 0;
}
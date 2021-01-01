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

	//���� 10814�� : ���̼� ���� (c++�� sort �Լ��� �켱������ �˾Ƽ� �����ش�. �� �켱������ �� �տ� �ִ� field�����̴�.)
	//���⼭�� age, idx, name ������ ���������Ƿ�, age������ ��������, age�� ������ idx��, �� ������ name������ �������ش�!
	int n;
	cin >> n;
	vector<tuple<int, int, string>> v;
	for (int i = 0; i < n; i++)
	{
		int age;
		string name;
		cin >> age >> name;
		v.push_back(make_tuple(age, i, name));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		int age, idx;
		string name;
		tie(age, idx, name) = v[i];
		cout << age << ' ' << name << '\n';
	}
	return 0;
}
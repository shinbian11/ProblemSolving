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

	//C++ stl lower_bound, upper_bound �� ����

	vector<int> a;

	a.push_back(4);
	a.push_back(6);
	a.push_back(1);
	a.push_back(2);
	a.push_back(9);
	a.push_back(2);

	sort(a.begin(), a.end());

	for (int i = 0; i < 6; i++)
		cout << a[i] << ' '; // 1 2 2 4 6 9

	cout << '\n';

	/*
	- ���� : �������� ����
	
	lower_bound(a.begin(),a.end(),num) -> num���� 'ũ�ų� ����' ������ ������ ��ġ�� ����Ŵ
	upper_bound(a.begin(),a.end(),num) -> num���� 'ū' ������ ������ ��ġ�� ����Ŵ

	[0] [1] [2] [3] [4] [5]
	 1   2   2   4   6   9 ���� num�� 2��,  lower_bound�� [1]��° �ε����� ����Ű��, upper_bound�� [3]��° �ε����� ����Ŵ.

	*/
	auto it = lower_bound(a.begin(), a.end(), 2);
	cout << *it << '\n'; // 2


	auto it2 = upper_bound(a.begin(), a.end(), 2);
	cout << *it2 << '\n'; // 4
	 
	return 0;
}
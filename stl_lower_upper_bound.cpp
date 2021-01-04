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

	int n;
	cin >> n;
	//12015�� : ���� �� �����ϴ� �κ� ���� 2 (lower_bound, upper_bound) 
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		
		auto it = lower_bound(a.begin(), a.end(), num);
		
		if (it == a.end()) { //num�� ������ a�迭�� �ִ� ��� ���ҵ� ���� ũ�ų�, �ƴ� ���ҵ��� �ִ밪�� ���� ũ���
			a.push_back(num); //a������ ���� �߰�
		}
		else {//num�� a ������ �ִ� ���� ������ -> �� num�� ������ �� �ƴϴ�!

			/*
			* 3 1 2 >> �̷��� �Է� �޾�����, else ���� ������, a���Ϳ��� ���������� 3�� ���� �ȴ�. �ٵ� a���Ϳ��� 1�� 2�� �־�� �Ѵ�.
			* �׷��Ƿ� num�� a������ �ִ밪���� �۴ٰ� �ؼ� �� num�� ���������� �ȵȴ�.
			* a���Ϳ� �ִ� ���ҵ� �߿���, num���� ���� ���� �ְ� num���� ū���� �����ٵ�, �� �� ������� ����Ű�� �ִ� �κ��� num���� ���� �ؾ��Ѵ�.
			* 3 1 2 ���� num=3 �̸� a ���Ϳ��� 3�� �� �ְ�, �״��� num=1 �϶��� lower_bound�� ���ؼ� it�� 3�� ����Ű�� �ִµ�, �� 3�� 1�� �����Ѵ�.
			* �״��� num=2�� a�� push_back�ؼ�, ��������δ� 1 2 �� ���´�.
			* 
			* 2 4 1 5 3 6 >> �̷��� �Է¹޾������� else�� ��� �ɰͰ��� ������ �Ǿ�����, 3 1 2 >> �̷��� �Է¹޾����� ��μ� else ���� �ʿ��ϴٴ� ���� ���ݰ� �Ǿ���.
			
			*/
			*it = num; 
		}
	}
	cout << a.size() << '\n';

	return 0;
}
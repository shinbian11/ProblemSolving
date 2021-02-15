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

	//[����] 1644�� : �Ҽ��� ������ (�Ҽ� �迭������ �� ����Ʈ + �����佺�׳׽��� ü)

	int n;
	cin >> n;

	//�����佺�׳׽��� ü�� �Ҽ� ���ϱ�
	vector<bool> p(n + 1);
	vector<int> v;
	for (int i = 2; i <= n; i++) {
		if (p[i] == false) {
			v.push_back(i);
			for (int j = i * 2; j <= n; j += i) {
				p[j] = true;
			}
		}
	}

	int left = 0, right = 0, ans = 0;

	//n�� 1�̸�, ���� v���� �ƹ��͵� ���� �ʾ����Ƿ�, sum=0 ó�� ���ְ�, �ڿ����� len=0�̶�� ���༭, while���� ���� �ʰ� �Ѵ�!
	int sum = v.empty() ? 0 : v[0]; 
	int len = v.size();
	
	while (left <= right && right < len)
	{
		if (sum < n)
		{
			right += 1;
			if(right< len)
				sum += v[right];
		}
		else if (sum > n)
		{
			sum -= v[left];
			left += 1;

			//if (left > right && left < len)
			//{
			//	right = left;
			//	sum = v[left];
			//}
		}
		else if (sum == n)
		{
			ans += 1;
			right += 1;
			if (right < len)
				sum += v[right];

		}
	}

	cout << ans << '\n';

	return 0;
}



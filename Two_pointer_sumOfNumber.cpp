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

	//[����] 2003�� : ������ �� 2 (��縣���� + �� ������)

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int left = 0, right = 0, sum = v[0], ans = 0;
	while (left <= right && right < n)
	{
		if (sum < m) //ã���� �ϴ� ������ ������ 
		{
			right += 1;
			if (right < n) //right �� 1 ���� �������� ����ó��
				sum += v[right];
	
		}
		else if (sum > m) //ã���� �ϴ� ������ ũ�� 
		{
			sum -= v[left];
			left += 1;

			if (left > right && left < n) //left �� 1 ���� �������� ����ó��
			{
				right = left;
				sum = v[left];
			}
			
		}
		else if(sum==m) //ã���� �ϴ� ���̸�
		{
			ans += 1;

			right += 1;

			if (right < n) //right �� 1 ���� �������� ����ó��
				sum += v[right];	
		}

	}

	cout << ans << '\n';

	return 0;
}



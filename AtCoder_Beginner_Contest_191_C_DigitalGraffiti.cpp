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

	//AtCoder Beginner Contest 191 : C - Digital Graffiti
	
	//#���� �̷���� �ٰ����� ��������� ���ϴ� ���� -> ���� ������ ���ų�, �������� ������ �����ָ� �ȴ�.

	/*
	- �������� ���� ����� ���!
	 
	- �ϴ� #�� 1��, .�� 0���� ��ȯ�Ѵ�.
	
	- �������� ũ�� �� ���� ��찡 �ִµ�,

##
#.
	>> �� ����,

..
.#
	>> �� ��찡 �ִ�.

	- ù��° ���� �� ������ ���� 3�̰�, �ι�° ���� ���� 1�̴�. 
	- ��, �� ������ ���� ���� ���� 1 or 3�� ��찡 �������̹Ƿ�, �׷��� ����� ������ �����ָ� �ȴ�.

	*/

	int h, w;

	cin >> h >> w;

	vector<string> arr(h);
	vector< vector<int> >d(h, vector<int>(w, 0));

	for (int i = 0; i < h; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (arr[i][j] == '#')
			{
				d[i][j] = 1;
			}
			else
				d[i][j] = 0;
		}
	}
	int ans = 0;
	for (int i = 0; i < h - 1; i++)
	{
		for (int j = 0; j < w - 1; j++)
		{
			//������ �� ������ ���� 1 or 3�̸� ans 1 ������Ű��!
			int sum = d[i][j] + d[i + 1][j] + d[i][j + 1] + d[i + 1][j + 1];
			if (sum & 1)
				ans += 1;
		}
	}

	cout << ans << '\n';

	return 0;
}


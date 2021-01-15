#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

ll wave[1500005];

int main()
{
	F_I;
	
	/*
	
	���� 2749�� : �Ǻ���ġ �� 3

	- n��° �Ǻ���ġ ���� m���� ���� �������� ���ϴ� ����
	- �Ǻ���ġ ������ m���� ���� ���������� ���� �迭�� �ݵ�� �ֱ� k �� ������ �ݺ��ȴ�.
	  �� �迭���� n��° �Ǻ���ġ ���� m���� ���� ��������, n%k��° �Ǻ���ġ ���� ����!!

	  e.g.) 
	  n     0  1  2  3  4  5  6  7   |  8  9  10  11  12   13  14  15
	 fibo   0  1  1  2  3  5  8  13  |  21 34 55  89  144  233 377 610
	fibo%3  0  1  1  2  0  2  2  1   |  0  1   1   2   0    2   2   1

	- 3���� �������� ���� �ֱ�� 8�̹Ƿ�, ���� ��� 13��° �Ǻ���ġ ���� 3���� ���� ��������, 13%8 => 5��° �Ǻ���ġ ���� ����.


	- ����, m�� 10�� �ŵ����� (10^p)�� �����̰�, p>2 ���, �׶��� �ֱ�� �׻� 15 * 10^(p-1) �̴�.

	- �� ���������� m�� 1000000(10^6)�̹Ƿ�, �ֱ�� 15 * 10^5 = 1500000�̴�.
	  n��° �Ǻ���ġ ���� m(10^6)���� ���� ��������, n % 1500000 ��° �Ǻ���ġ ���� ����!!

	*/ 

	int mod = 1e6;

	
	wave[0] = 0;
	wave[1] = 1;

	for (int i = 2; i < 1500000; i++)
	{
		wave[i] = wave[i - 1] + wave[i - 2];
		wave[i] %= mod;
	}

	ll n;
	cin >> n;

	cout << wave[n % 1500000] << '\n';

	return 0;
}
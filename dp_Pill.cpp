#include <bits/stdc++.h>
#include <unordered_set>

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

//d[f][h] : �˾� �� ������ f��, �˾� �� ������ h�� �϶�, ���� �� �ִ� ����� �� (���ڿ��� ����� ��)
//�� ������ �����ϴ� ���: �� ������ -1 ������, �������� +1 �ȴ�.
//�� ������ �����ϴ� ���: �� ������ �״������, �������� -1 �ȴ�.
//�� d[f][h] = d[f-1][h+1] + d[f][h-1]�̴�.
ll d[31][31]; 

ll calc(int f, int h)
{
	if (d[f][h] != -1) return d[f][h]; //memoization
	if (f == 0) return 1; //�� ������ ���� �� ������ �ִ� ��� > �������� ��� �����Ƿ� ����� �� 1�����̴�.
	if (h == 0) return calc(f - 1, 1); //�� ������ ���� �� ������ f �� �ִ� ��� > �� ������ f-1 ��, �������� 1���� �ȴ�.
	return d[f][h] = calc(f - 1, h + 1) + calc(f, h - 1); //�� �� ��찡 �ƴ� ���
}

int main()
{
	F_I;

	//[����] 4811�� : �˾� (dp_ Top down)

	while (true)
	{
		memset(d, -1, sizeof(d));
		int n;
		cin >> n;
		if (n == 0)
			return 0;
		cout << calc(n, 0) << '\n'; //�� ó������ �������� n��, �������� 0���ϱ�.
	}

	return 0;
}
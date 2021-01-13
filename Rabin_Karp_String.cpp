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

int mod = 127;
int base = 256;


int hash_val(string str)
{
	int ans = 0;
	for (char ch : str)
	{
		ans = (ans * base + ch) % mod;
	}
	return ans;
}

int match(string& a, string& b)
{
	//substr(i,m) : i��° �ε�������, m����ŭ�� �����Ѵٴ� ��! (i��° ~ i+m-1��° ����)

	int n = a.length();
	int m = b.length();

	if (n < m)
		return 0;

	int pattern = hash_val(b); //ã���� �ϴ� ������ hash �� ���ϱ�

	int f = hash_val(a.substr(0, m)); //���ڿ��� ù��° ����� hash �� ���ϱ� (�ι�° ������ʹ� �� �� ������� ���ߴ� hash���� �Ϻκ��� �̿�)

	int first = 1;

	for (int i = 0; i < m - 1; i++)
		first = (first * base) % mod; //pow(base, m-1) ���� �� ������� �ϱ�! ��¥�� pow()�� �ϸ� ���Ҷ� ���� % mod �� ���ϴϱ� ���� ó����!

	for (int i = 0; i <= n - m; i++)
	{
		if (f == pattern) //hash ���� ������
		{
			if (a.substr(i, m) == b) return 1; //���� ���ڿ����� Ȯ��
		}
		else
		{
			/*
			���� ���ڿ� ����� 123 �̾��ٰ�, �̹� ����� 234 ���,
			123���� 1�� ���� (123->23)  : (f - ((int)(a[i] * first) % mod))
			23�� �������� ���� (23->230)  : * base) % mod)
			4�� �߰��ؾ� �Ѵ� (230->234)  :  + a[i + m]) % mod;
			*/
			if (i + m < n) // i+m >= n �̸�, a[i+m] �κп��� �迭 �޸� ���� ���� ����ϱ�!
				f = ((((f - ((int)(a[i] * first) % mod)) * base) % mod) + a[i + m]) % mod;
		}
	}
	return 0;
}
int main()
{
	F_I;
	/*
	���� 16916�� : �κ� ���ڿ� (���-ī�� ���ڿ� �˰���)
	*/
	string n, m;
	cin >> n >> m;
	cout << match(n, m) << '\n';
	return 0;
}
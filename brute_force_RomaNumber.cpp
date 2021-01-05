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

int arr[20 * 50 + 1];

int main()
{
	F_I;

	int n;
	cin >> n;
	/*
	���� 16922�� : �θ� ���� ����� (���Ʈ ���� + ������ ��ȯ)

	- I,V,X,L ���ڷ� ���

	- N�� 20�϶�, ������ �ڸ��� ���� �� �ִ� ����� ���� 4�����̴� -> O(4^20) : ���ѽð� �ʰ�!
	- I,V,X,L�� ������ ������. (I�� i��, V�� j�� , X�� k��, L�� l��) -> �� ������ �ִ� N�� �����ϹǷ� -> O(N^4) : ���ѽð� �ʰ� x
	- �ٵ� I,V,X�� ������ ���ϸ�, L�� ������ �ڿ����� ��������. �ݺ��� ���� �ʿ� ����. -> l = n - i - j - k�� -> O(N^3) : ���ѽð� �ʰ� x (���� ȿ����)
	*/

	for (int i = 0; i <= n; i++) //I�� ����
	{
		for (int j = 0; j <= n - i; j++) //V�� ����
		{
			for (int k = 0; k <= n - i - j; k++) //X�� ����
			{
				int l = n - i - j - k; // L�� ����
				int sum = i * 1 + j * 5 + k * 10 + l * 50; //������ ������ �������ٰ� ���� ���� ���ؼ� ��� ������� ��. �װ͵��� ���� �� �ִ� ���ڵ�!
				arr[sum] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 20 * 50 + 1; i++)
	{
		if (arr[i]) 
			ans += 1;
	}

	cout << ans << '\n';
	return 0;
}
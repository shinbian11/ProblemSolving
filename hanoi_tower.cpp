#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����


//���� 11729�� : �ϳ��� ž �̵� ���� (���� ����) (c++)
void solve(int n, int x, int y)
{
	// step 1 . 1 ~ n-1 ������ ���ǵ��� �ٸ� ������� �Űܳ���, 
	// step 2 . �� ���� n��° ������ ���� �������� �ű� ����, 
	// step 3. step 1���� �Űܳ��� ���ǵ��� n��° ���� ���� �ű��
	if (n == 0)
		return;
	//1,2,3�� �� ����� �ִµ�, x,y ����� �ƴ� ������ ����� 6-x-y�� ǥ���ߴ�! ���� x = 1, y = 2 �� ������ ����� 3�� 6-1-2 = 3�̴ϱ�.
	solve(n - 1, x, 6 - x - y);
	cout << x << ' ' << y << '\n';
	solve(n - 1, 6 - x - y, y);
}

int main() 
{
	F_I;
	int n;
	cin >> n;
	// D[n] = n���� ������ ������ ���������� �ϳ��� �̵��� �� ���� Ƚ����� �Ѵٸ�,
	// D[1] = 1 �̰�, D[n] = D[n-1] + 1 + D[n-1] �̴�.(solve�Լ��� step 1~3 ����)
	// �纯�� 1�� ���ϸ� D[n] + 1 = 2(D[n-1]+1)�̰�, D[n]+1 = E[n]�̶� ġȯ�ϸ�,
	// E[1]=D[1]+1 = 2�̰�, E[n] = 2*E[n-1] = 2^n�̹Ƿ�, D[n]+1 = 2^n �̰�, ��������� D[n] = (2^n) - 1 �̴�.
	cout << pow(2, n) - 1 << '\n';

	solve(n,1,3); //n���� ������ ��� 1���� ��� 3���� �ű��
	return 0;

}
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

int arr[1004];
int d[1004][1004];

int n, m;

/*
index��° ���ڸ� �� ���̰�, �� �ٿ� �̹� count���� ĭ�� ����� ��Ȳ����,
���� �ٿ� index��° ���ڸ� �� ���̶�� >> d[index+1][count+arr[index]+1] : ������ +1 �� ������ 1ĭ�� �ݿ��� ���̴�.
���� �ٿ� index��° ���ڸ� �� ���̶�� >> d[index+1][arr[index]+1] + (m - count + 1) * (m - count + 1)�̴�.
�̶�, (m - count + 1)�� ���� ���� ������� �ʰ� ���� �Ǵ� ĭ�� �� �̴�. �̶��� +1�� ������ 1ĭ�� �ݿ��� ���̴�.
���ذ� �ȵȴٸ� �׸��� ���� �׷�����!!
*/

int go(int index, int count) //d[index][count] : index��° ���ڸ� �� ���̰�, �� �ٿ� �̹� count���� ĭ�� ������� ��!
{

	if (index >= n) //���� üũ
		return 0;

	//memoization
	int& ans = d[index][count];
	if (ans != -1)
		return ans;

	//���� �ٿ� ���ڸ� �� ���̶��
	ans = go(index + 1, arr[index] + 1) + (m - count + 1) * (m - count + 1);

	//���� �ٿ� ���ڸ� �� ���̶��
	if (count + arr[index] <= m) //���� üũ
	{
		int tmp = go(index + 1, count + arr[index] + 1);

		if (ans > tmp) //�ּҸ� return
			ans = tmp;
	}

	return ans;
}

int main()
{
	//[����] 2281�� : ������Ʈ (dp,TOP down)
	F_I;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	memset(d, -1, sizeof(d)); //memoization�� ���� �ʱ�ȭ!

	cout << go(1, arr[0] + 1); //index 1 ��° ���ڸ� �� ���̰�, ���� arr[0]+1 ��ŭ�� ĭ�� �� ������ �����϶�! 

	return 0;
}
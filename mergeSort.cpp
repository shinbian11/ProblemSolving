//c++

//MergeSort

/*
1�� ���� : i�� ������ i = 0 ~ i < k ������ �ϸ� �ð��ʰ� ���� ����

> s���� e���� �ؾ� �ð� ���⵵�� O(nlogn)�� �ȴ�. 0���� �����ϸ� O(n^2)�� �ȴ�. �� �������� n�� �ִ� 1,000,000

���� �����ϹǷ�, n^2�� �Ǹ� 1,000,000 x 1,000,000 = 1,000,000,000,000�� �ǹǷ� �ð��ʰ��� ���� �� �ۿ� ����.

2�� ���� : ans[i]�� �� ������ѳ��� �ٽ� v[i]�� ������ �Ű� ��ƾ� �ϴ� ����

> ���ĵ� ������ �ٽ� v�� ������ ���� �� ū ������ ��ĥ �� "�̹� ���ĵ� �� �κ��� merge�Ѵ�"�� ������ ��ų �� �ִ�. �׷��� �ʴٸ� ������ ���ĵ��� ���� ���¿��� merge�� �õ��ϰ� �ǹǷ� �ùٸ� ����� ���� �� ����.

3�� ���� : s <= e�� �ϸ� �ȵǴ� ����?

> s <= e�� �� ��� s == e�� ��� mid�� s�� ��������.

�׷��� Partition(s, mid)�� ���ȣ��� �� �ٽ� s == e�� �ǰ�, �� �ȿ��� �ٽ� Partition(s, mid)�� ȣ��ǰ�... �� ������ ������ �ݺ��ϰ� �Ǿ� ��ͽ����� ������ ���̱� ������ �޸� �ʰ��� �ȴ�.
*/
#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

int v[1000000];
int ans[1000000];

void Merge(int s, int e)
{
	int i, j, k, mid;
	mid = (s + e) / 2;
	i = s;
	j = mid + 1;
	k = s;

	while (i <= mid && j <= e)
	{
		if (v[i] > v[j])
			ans[k++] = v[j++];
		else
			ans[k++] = v[i++];
	}

	if (i > mid)
	{
		for (int l = j; l <= e; l++)
			ans[k++] = v[l];
	}
	else if (j > e)
	{
		for (int l = i; l <= mid; l++)
			ans[k++] = v[l];
	}
	for (int i = s; i <= e; i++) // 1�� ���� : i�� ������ i = 0 ~ i < k ������ �ϸ� �ð��ʰ� ���� ����
		v[i] = ans[i]; //2�� ���� : ans[i]�� �� ������ѳ��� �ٽ� v[i]�� ������ �Ű� ��ƾ� �ϴ� ����
}
void Partition(int s, int e)
{
	int mid;
	if (s < e) // 3�� ���� : s <= e�� �ϸ� �ȵǴ� ����? 
	{
		mid = (s + e) / 2;
		Partition(s, mid);
		Partition(mid + 1, e);
		Merge(s, e);
	}
}
int main()
{
	F_I;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	Partition(0, n - 1);
	for (int i = 0; i < n; i++)
		cout << v[i] << '\n';
	return 0;
}
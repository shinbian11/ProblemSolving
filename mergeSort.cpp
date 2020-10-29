//c++

//MergeSort

/*
1번 질문 : i의 범위를 i = 0 ~ i < k 까지로 하면 시간초과 나는 이유

> s부터 e까지 해야 시간 복잡도가 O(nlogn)이 된다. 0부터 시작하면 O(n^2)이 된다. 이 문제에서 n은 최대 1,000,000

까지 가능하므로, n^2이 되면 1,000,000 x 1,000,000 = 1,000,000,000,000이 되므로 시간초과가 나올 수 밖에 없다.

2번 질문 : ans[i]로 값 저장시켜놓고 다시 v[i]로 일일히 옮겨 담아야 하는 이유

> 정렬된 내용을 다시 v에 담아줘야 이후 더 큰 범위를 합칠 때 "이미 정렬된 양 부분을 merge한다"는 로직을 지킬 수 있다. 그렇지 않다면 양쪽이 정렬되지 않은 상태에서 merge를 시도하게 되므로 올바른 결과가 나올 수 없다.

3번 질문 : s <= e로 하면 안되는 이유?

> s <= e로 할 경우 s == e인 경우 mid는 s와 같아진다.

그래서 Partition(s, mid)가 재귀호출될 때 다시 s == e가 되고, 그 안에서 다시 Partition(s, mid)가 호출되고... 이 과정을 무한히 반복하게 되어 재귀스택이 무한히 쌓이기 때문에 메모리 초과가 된다.
*/
#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

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
	for (int i = s; i <= e; i++) // 1번 질문 : i의 범위를 i = 0 ~ i < k 까지로 하면 시간초과 나는 이유
		v[i] = ans[i]; //2번 질문 : ans[i]로 값 저장시켜놓고 다시 v[i]로 일일히 옮겨 담아야 하는 이유
}
void Partition(int s, int e)
{
	int mid;
	if (s < e) // 3번 질문 : s <= e로 하면 안되는 이유? 
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
//세그먼트 트리 이용 (2042번 - 구간 합 구하기)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll init(vector <ll>& v, vector<ll>& tree, int node, int start, int end)
{
	if (start == end)
	{
		return tree[node] = v[start];
	}
	ll mid = (start + end) / 2;
	return tree[node] = init(v, tree, node * 2, start, mid) + init(v, tree, node * 2 + 1, mid + 1, end);
}
void update(vector<ll>& tree, int node, int start, int end, ll index, ll diff)
{
	if ((start > index) || (end < index))
		return;
	tree[node] += diff;
	if (start != end)
	{
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2+1, mid+1, end, index, diff);
	}
}
ll sum(vector<ll>& tree, int node, int start, int end, ll left, ll right)
{
	if ((right < start) || (end < left))
		return 0;
	if ((left <= start) && (end <= right))
		return tree[node];
	int mid = (start + end) / 2;
	return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}
int main()
{
	-ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, k;
	
	cin >> n >> m >> k;
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));

	vector<ll> v(n);
	vector<ll> tree(tree_size);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	init(v, tree, 1, 0, n - 1);
	for (int i = 0; i <= m + k - 1; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			ll diff = c - v[b - 1];
			v[b - 1] = c;
			update(tree, 1, 0, n - 1, b - 1, diff);
		}
		else if (a == 2)
		{
			cout << sum(tree, 1, 0, n - 1, b - 1, c - 1) << '\n';
		}
	}
}
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

	/*
	���� 1202�� : ���� ���� (�׸��� + cmp���Լ� ���� ���ο� ���)

	- �� ������ �ð����⵵�� �� ���� �Ѵ�. ���ѽð��� n, k�� �ִ������ ��������, O(n*k)�� �ð����⵵�� ������ �ð��ʰ��� ���.
	 ��, vector�ϳ����ٰ� ������ ������ ������ �� �����ؾ� �Ѵ�. ���� ������ �����ϰ�, ������ ������ ������ �� �ִ� bool ������ �ϳ� �߰��Ѵ�.
	 �׷��� �ð����⵵�� O(n+k)�� ���̴� ���� �����̴�.

	- sort�� �� �� cmp ���Լ��� ���ٿ� �����ϴ� ���� ���� ���. ���� �Լ� �������� �ʰ�!

	-�켱������ ���ؼ� ���. �ִ� ���� default�ε�, �ּ� ������ �����ϰ� ������ priority_queue<int> q �� �ƴ϶�,
	priority_queue<int, vector<int>, greater<int> > q; ��� �ϸ� ��. (�ڷ����� int�� �ƴϸ� �ٸ� �ڷ������� �����ϸ� �ȴ�)
	��� vector<int>�� �׳� ���ָ� �ǰ�, greater<int> �� �̿��ϸ� �ȴ�.
	�����, less<int> q�� �ִ� ���ε� ��¥�� default�� ��ü�� �ִ� ���̴ϱ� ���� �� �ʿ�� ����!

	 */

	int n, k;
	cin >> n >> k;

	vector< tuple<int, int, bool> > v(n + k); //����, ��ġ, checking(false > ����, true > ����)
	for (int i = 0; i < n; i++)
	{
		cin >> get<0>(v[i]) >> get<1>(v[i]); //������ ���Կ� ��ġ �Է¹ް�, 
		get<2>(v[i]) = false; //�����̴ϱ� false
	}
	for (int i = n; i < n + k; i++)
	{
		cin >> get<0>(v[i]); //������ ���Ը� �Է¹ް�, 
		get<1>(v[i]) = 0; //������ ��ġ�� ���⼭ ������ �����ϱ� �׳� 0���� �ʱ�ȭ
		get<2>(v[i]) = true; //�����̴ϱ� true
	}

	//cmp ���Լ� ���� ������ �ʰ�, �ѹ��� �����ϴ� ��! [] (�Ű����� �ڷ����� �̸�) { ���ǹ�; }
	sort(v.begin(), v.end(), [](tuple<int, int, bool> a, tuple<int, int, bool> b) {
		return get<0>(a) < get<0>(b) || (get<0>(a) == get<0>(b) && get<2>(a) < get<2>(b));  //���Ը� 1������, ����/���� �Ǵ� ������ 2������ ����.
		});
	//�̷��� ������ �ϸ�, ������ ���Ժ��� ������ �������� ��� �� ���溸�� ���� ���ĵǾ� ������ ������, 
	//�ٽ� ����, ���� ��Ȳ���� ������ �������� �ĺ����� �Ǻ��ϱⰡ ��������.(���溸�� ���� ���ĵ� ������ �߿��� ���� ū ��ġ�� ���� ������ ���ϸ� �Ǵϱ�)
	//�� �ִ밪 (���� ū ��ġ)�� ������ ������ �켱���� ť�� ã��!


	priority_queue<int> q; //�ּ� ������ ���� �ϰ� ������ : priority_queue<int, vector<int>, greater<int> > q;
	ll max_value = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (get<2>(v[i]) == 0) //�����϶�
			q.push(get<1>(v[i])); //������ ��ġ�� �켱���� ť�� �ִ´�. (�ִ� ��)
		else //������ ������ ��
		{
			if (!q.empty()) //while�� �ƴ϶� if�̴�! ����! �켱���� ť�� ��������� ������ �ȴ�!
			{
				max_value += (ll)q.top(); //���� top�� �ִ� �� (�̶����� �� ������ ��ġ�� �� �ִ밪�� �˾Ƽ� top�� �ִ�. �켱���� ť�ϱ�)
				q.pop();
			}
		}
	}

	cout << max_value << '\n';
	return 0;
}

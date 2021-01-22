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
	[����] 15686�� : ġŲ ��� (���Ʈ ����)

	- ������ ġŲ ���� ���ؼ� bfs �� ���� ��� ����� �ʿ� ����. 
	- ���� ���ܽ�Ű�� ���� ġŲ���� ����, �� ġŲ����� ���� ������ �Ÿ��� ���ϸ� �ȴ�.
	- ġŲ ���� �ִ� 13�� �̹Ƿ�, �ð����⵵�� �ִ� O(2^13)�̴�.  
	*/

	int n, m;
	cin >> n >> m;
	vector< vector<int> > a(n, vector<int>(n));
	vector<pi> house; //�� ����
	vector<pi> chicken; //ġŲ�� ����

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1) //�� ���� 
				house.emplace_back(i, j);
			if (a[i][j] == 2) //ġŲ �� ����
				chicken.emplace_back(i, j);
		}
	}

	vector<int> select(chicken.size(), 0);
	
	/*
	ġŲ �� �� �߿��� �ִ� m �� ���� ��� ��Ű�� ���� ��츦 ����� ���Ͽ� select �Լ� ����.
	e.g.) ġŲ���� 4����, m�� 2���, ����� 0��/1��/2�� ��Ű�� ��찡 �����ϰ�, 
	1�� m�� ��ŭ �־�ΰ� select �Լ��� ���ؼ� ������ ������ �ȴ�.
	
	select[0]=select[1]= 1,	select[2]=select[3]= 0�� �����̴�.
	�� ���� 0,1��° ġŲ���� �/ 2,3���� ġŲ���� ����ߴٴ� �ǹ��̴�.

	�� ���� permutation�� 1010 �̴�. (1100 ������ prev_permutation�� ��)
	1010 > 0,2��° ġŲ�� �/ 1,3��° ġŲ�� ���

	... �ݺ�!!

	*/
	for (int i = 0; i < m; i++) 
		select[i] = 1;

	int ans = 1e9;

	do
	{
		int sum = 0; 
		for (int i = 0; i < house.size(); i++)
		{
			vector<int> dist; //���������� ġŲ��������� ��� �Ÿ� ���� �����ϱ�

			for (int j = 0; j < select.size(); j++)
			{
				if (select[j] == 0) continue; //��� �� ġŲ���� �Ÿ� ��꿡�� ����!

				int x = chicken[j].first - house[i].first;
				int y = chicken[j].second - house[i].second;
				dist.push_back(abs(x) + abs(y));
			}
			sort(dist.begin(), dist.end()); //dist�� �ּҰ� 
			sum += dist[0];
		}
		
		if (ans > sum)
			ans = sum;

	} while (prev_permutation(select.begin(), select.end()));

	cout << ans << '\n';

	return 0;
}
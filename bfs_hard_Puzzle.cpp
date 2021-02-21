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

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
	F_I;

	//[����] 1525�� : ���� (bfs)

	/*
	* <bfs ������ ����>
	* 1. �ּ�Ƚ�� ���ϴ� ����
	* 2. ��� ������ (move)�� ����ġ�� 1�̰�
	* 3. ������ ������ ������ �۴�


	�Է� ���� 3 x 3 ������ �ϳ��� ������ �ٲٰ�,
	�� ������ ���ڿ�ȭ �Ѵ���, �� ���� ��ĭ�� ������ ���ڵ�� swap�� �Ͽ� ��ĭ���� ���ڸ� �̵���Ű�� ȿ���� �� ����,
	�� ����� �ٽ� ����ȭ ��Ű��, �� ����� �ּ� Ƚ���� �����ϴ� ������ �ݺ��Ѵ�.
	*/

	int n = 3;
	int num = 0;

	//�Է� ���� 3 x 3 ������ �ϳ��� ������ �ٲٱ�
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			if (a == 0)
				a = 9;
			num = num * 10 + a;
		}
	}

	map<int, int> d; //map �������� ���� ���̱�. �迭�� �ϸ� �޸� �ʰ���.

	d[num] = 0; //num�̶�� ���ڸ� ����µ����� 0���� �ð��� �ɸ���. �ֳ��ϸ� num���� �����ϴ� �Ŵϱ�

	queue<int> q;
	q.push(num);

	while (!q.empty())
	{
		int now = q.front(); q.pop();
		
		string now_str = to_string(now);
		int blank_idx = now_str.find('9'); // ��ĭ�� �ε��� �� ã�ƶ�!
		int x = blank_idx / 3;
		int y = blank_idx % 3;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) //��ĭ�� ������ ���ڵ�� �ڸ��� �ٲ� �� �ִ�.
			{
				string next_str = now_str;
				swap(next_str[x * 3 + y], next_str[nx * 3 + ny]); //swap �ϰ�,
				int next = stoi(next_str); //�� ����� �ٽ� ����ȭ �Ѵ�!

				//map����, next ��� key�� ������ d�� value�� 0�̶��,
				//(value�� �ʱ�ȭ �ÿ� 0���� �ʱ�ȭ �ǹǷ�, value�� 0�̶�� �ǹ̴� �ѹ��� ���ŵ� �� ���ٴ� �ǹ� -> visited[i] == false�� ���� �ƶ��� �ǹ�!)  
				if (d.count(next) == 0) //next_now ���ڿ��� �ѹ��� ���� ���� ���ٸ�,
				{
					d[next] = d[now] + 1; //�ּ� Ƚ�� + 1 ���ش�.
					q.push(next);
				}
			}
		}
	}

	//key : 123456789�� �ش��ϴ� ���� ���̴�.
	if (d.count(123456789) == 0)  // �ѹ��� ���� �� �� ���ٸ�, ������ ���¸� �� �̻� ���� �� ���ٴ� �ǹ��̹Ƿ� -1 ���
		cout << -1 << '\n';
	else
		cout << d[123456789] << '\n';

	return 0;
}
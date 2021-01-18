#include <bits/stdc++.h>
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

	/*
	[����] 2151�� : �ſ� ��ġ (BFS)

	e.g.) 

	***#*
	*.!.*
	*!.!*
	*.!.*
	*#***

	- �̷� �迭�� ���� ��, number �迭�� 0 1 2 3 4 5 �� ������, 
	info �迭��
	0 3 (#)
	1 2 (!)
	2 1 (!)
	2 3 (!)
	3 2 (!)
	4 1 (#)
	�� ���´�.

	����, exist �迭�� �Ʒ��� ���� ���´�.

	0 0 0 1 0 0   (0���� 3��)
	0 0 0 0 1 0   (1���� 4��)
	0 0 0 1 0 1   (2���� 3��) (2���� 5��)
	1 0 1 0 0 0   (3���� 0��) (3���� 2��)
	0 1 0 0 0 0   (4���� 1��)
	0 0 1 0 0 0   (5���� 2��)

	����������, dist �迭�� �Ʒ��� ���� ���´�.
	0 -1 2 1 -1 3

	*/

	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> number; //���̳� �ſ��� ��ġ �� �� �ִ� ��ġ�� ��� ã�Ƽ� ���� numbering �س���
	vector<pi> info; //�׶��� x,y�� ����

	int start = -1, end = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == '#') //��
			{
				if (start == -1) //ù��° ���̸�
				{
					start = number.size(); //��ȣ �ű��
					number.push_back(start);  //��ȣ ����
				}
				else if (start != -1 && end == -1) //�ι�° ���̸�
				{ 
					end = number.size(); //��ȣ �ű��
					number.push_back(end); //��ȣ ����
				}
				info.push_back(make_pair(i, j)); //x�� y���� ���� �����ϰ�
			}
			if (arr[i][j] == '!') //�ſ� ��ġ �� �� �ִ� ��
			{
				number.push_back(number.size()); //��ȣ �ű��
				info.push_back(make_pair(i, j)); //x�� y���� ���� �����ϰ�
			}
		}
	}
	int size = number.size();
	
	

	//exist[i][j] => number �迭���� �Ű��� �ִ� ��ȣ�� ����, i�� ��/�ſ￡�� j�� ��/�ſ����� �ſ��� ��ġ �� �� ������ true, ������ false
	//i��° ��ҿ��� ���� �������� �� ���� ��, �ش�Ǵ� ��� j�� true��!

	vector< vector<bool> > exist(size, vector<bool>(size)); 

	for (int i = 0; i < size; i++)
	{
		int x = info[i].first;
		int y = info[i].second;
		for (int j = 0; j < 4; j++)
		{
			int nx = x + dx[j];
			int ny = y + dy[j];

			while (nx >= 0 && nx < n && ny >= 0 && ny < n) //�迭 ���� üũ
			{
				if (arr[nx][ny] == '*')
					break;
				if (arr[nx][ny] == '#' || arr[nx][ny] == '!')
				{
					for (int k = 0;k < size; k++)
					{
						if (info[k].first == nx && info[k].second == ny)
						{
							exist[i][k] = true; //i������ k������ �ſ� ��ġ ����!
							break;
						}
					}
					
				}
				//���� �������� ��� ���� (�迭 ���� �ѱ� ��������)
				nx += dx[j];
				ny += dy[j];
			}
		}
	}

	
	vector<int> dist(size, -1); //�Ÿ� ���

	queue<int> q;
	q.push(start);
	dist[start] = 0;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < size; i++)
		{
			if (exist[x][i] && dist[i] == -1)
			{
				dist[i] = dist[x] + 1;
				q.push(i);
			}
		}
	}
	
	cout << dist[end] - 1 << '\n';

	return 0;
}
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

int n, m;
int arr[1004][1004];
int group_numbering[1004][1004];
int group_size[1000 * 1000 + 4];
int group_cnt;

int dir_x[4] = { 1,0,-1,0 };
int dir_y[4] = { 0,1,0,-1 };

void bfs(int i, int j)
{
	queue<pi> q;
	q.push(make_pair(i, j));

	group_cnt += 1; //group_cnt : �׷� ��ȣ �ű�� ����.

	group_numbering[i][j] = group_cnt; //i�� j���� ĭ�� group_cnt��° �׷쿡 �����ִ�.

	int cnt = 1; // group_cnt��° �׷��� ũ�� (1�� ����) üũ

	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (arr[nx][ny] == 1 && group_numbering[nx][ny] == 0) //�������ִ� nx�� ny���� ĭ�� 1�̰�, �� ĭ�� ���� Ư�� �׷쿡 ���� ���� ���� ��,
				{
					group_numbering[nx][ny] = group_cnt; //�������ִ� nx�� ny���� ĭ�� group_cnt��° �׷쿡 �����ִ�.

					cnt += 1; //group_cnt��° �׷��� 1�� ������ 1 ������Ŵ
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	group_size[group_cnt] = cnt; // group_cnt��° �׷��� ũ��� cnt �̴�.(group_cnt��° �׷쿡 �ִ� 1�� cnt���̴�.)

}

int main()
{
	F_I;

	//16932�� : ��� ����� (BFS + ������ �ߺ� ���� ��� (unique) + ���� ���� �̿�)

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	//�Է¹��� n * n �迭���� ����� �������´�.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1 && group_numbering[i][j] == 0)
				bfs(i, j);
		}
	}

	//0�� �ش�Ǵ� �κ��� 1�� �ٲ��� ��, � ��ȭ�� �Ͼ������ ����
	//0�� �ش�Ǵ� ĭ�� 1�� �ٲٸ�, �� ĭ�� �����Ǿ� �ִ� ĭ�� �߿�, �׷쿡 �����ִ� ���Ұ� �ִٸ�,
	//�� ���ҵ��� �����ִ� �׷�鳢�� �̾�����! 
	//0�� �ش�Ǵ� �κ��� 1�� �ٲ��� ���� ���(�׷�)�� ũ���� �ִ밪 > ������ �׷��� �������� �� + 1 �̴�.
	/*
	 
	- ���(�׷�)�� 2���� 4*4�迭! ���� ����� �׷��� 1�� �׷�, ���� �ϴ��� �׷��� 2�� �׷��̶� ����.
	
	1 1 0 0
	1 0 0 0 
	0 0 1 1
	0 0 0 0

	- �̷��� ����� �׷쿡��, 1�� 1���� 0�� 1�� �ٲ۴ٸ�, 1�� �׷�� 2�� �׷��� �̾�����!

	1 1 0 0
	1'1'0 0
	0 0 1 1
	0 0 0 0

	> �׷��� �Ǹ�, 1�� �׷��� ũ�� + 2�� �׷��� ũ�� + 1�� 1���� ũ��  => 3 + 2 + 1 = ũ�� 6�� ���(�׷�)�� ���� �� �ִ�.

	> �̷��� ���� �� �ִ� ����� ũ��� ��, �ִ밪�� ����ϱ�! (���⼭�� ans��� ������ ���̴�.)
	*/

	int ans = -1; // ���� ����ϰ��� �ϴ� ��

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0) //0�� 1�� �ٲ�����
			{
				vector<int> near_info;
				
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dir_x[k];
					int ny = j + dir_y[k];

					if (nx >= 0 && nx < n && ny >= 0 && ny < m)
					{
						if (arr[nx][ny] == 1) //���� �κ��� 1�̶��, �� 1�� group_numbering�� near_info �迭���ٰ� ��� �����س��´�.
						{
							near_info.push_back(group_numbering[nx][ny]);
						}
						/*
						arr[i][j]==0�϶�, �� ĭ�� ������ �����¿� ĭ�� �߿���, ��,�� ���⿡ 1�� �ְ� �� ���⿣ 0, �� ���⿡ 1�� �ִٰ� �����ϰ�,
						��,�� ������ 1�� 1�� �׷�, �� ������ 1�� 2�� �׷��϶�, near_info ���Ϳ��� 1 2����, 2 1���� ���� �� �ִ�.
						*/
					}
				}

				//���� : http://blog.naver.com/PostView.nhn?blogId=withham1&logNo=221102099316
				//�ߺ��� ������ ���� (1�� �׷� 2��, 2�� �׷� 1�� �� �ִµ�, ������� 1������ üũ�ؾ� �ϹǷ�!)
				//near_info ���� ���� ������ 1�� �׷� 2��, 2�� �׷� 1�� -> 1�� �׷� 1��, 2�� �׷� 1�� ���� �����ϱ�!

				/*
				e.g.) near_info ���Ͱ� 1 3 2 1 1 3 �� ���� ��,

				�����ϸ� : 1 1 1 2 3 3 �� �ǰ�, 

				unique�� ���� �ߺ��Ǵ� ���� �� �ڷ� ���� : 1 2 3 ? ? ? (�տ� 1 2 3 �� �ߺ� �ȵ� ��, �ڿ� ? ? ? �� �ߺ��� ��(1 �ΰ��� 3 1��))

				�̋� unique�� �ߺ����� �ʴ� �κ��� end() �ּ� (== ? ���� ���� ��ġ �ּ�)�� ��ȯ�Ѵ�.

				erase(a,b)�� [a,b)�� �����ִ� �Լ��̹Ƿ�, 3��° �ε��� ���� 5��° �ε������� ����� �ʹٸ� .erase(3,6)�� ���� �ȴ�.

				�Ʊ����� unique���� �ߺ��Ǵ� �κ��� ù �κ��� ��ȯ�Ѵٰ� �����Ƿ�,
				������ �ߺ� �κ��� �����ϰ� ������ erase �Լ��� 'ù �κ�'�� unique �Լ��� ��ȯ�� ��, '������ �κ�'�� ������ end()�� �־��ָ� �ȴ�.

				near_info.erase(    unique(near_info.begin(), near_info.end())  ,  near_info.end()   ); 
				-> 1 2 3 ? ? ? ���� ? ? ? �κ� ���� => 1 2 3 �� ���´�.

				*/
				sort(near_info.begin(), near_info.end()); //�����ϰ�,
				near_info.erase(unique(near_info.begin(), near_info.end()), near_info.end()); //������ �ߺ� ���Ź�� (unique)

				int sum = 1;

				for (int l = 0; l < near_info.size(); l++)
				{
					sum += group_size[near_info[l]];
				}

				if (ans < sum)
					ans = sum;

			}
		}
	}

	cout << ans << '\n';

	return 0;
}
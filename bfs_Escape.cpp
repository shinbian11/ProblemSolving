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

char arr[54][54];
int d[54][54];
bool water[54][54];
bool gosum_move[54][54];

int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

typedef struct info
{
	int x, y, check;
} INFO;
INFO info;

int n, m;
int dest_x, dest_y;

bool cmp(INFO a, INFO b)
{
	/*
	����ġ�� ���� �� ������ ĭ���� �̵��� �� ����. ��, ���� �ð��� ���� �� ������ ĭ���� ����ġ�� �̵��� �� ���� ��� ���� ���ؼ�,
	���� ���� ������ 4�������� �̵���Ű��, �� ���Ŀ� ����ġ�� �̵���Ű�� ������ ������ �ϵ��� �����ϱ� ���ؼ�,
	���� check = 0��, ����ġ�� check = 1�� �־, queue�� ���� ������ �� ���� �������� ���� queue�� �տ� ������ sort ���Ѿ� �Ѵ�.
	*/
	return a.check < b.check;
}

int main()
{
	F_I;

	//[����] 3055�� : Ż�� (bfs)

	vector<INFO> v;
	memset(d, -1, sizeof(d));

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = s[j];

			if (arr[i][j] == '*') //��
			{
				info.x = i;
				info.y = j;
				info.check = 0;
				v.push_back(info);
			}
			else if (arr[i][j] == 'S') //����ġ
			{
				d[i][j] = 0; //����ġ�� ó�� �ִ� ��ġ�� ���� �ð��� 0�ʴ�.
				
				info.x = i;
				info.y = j;
				info.check = 1;
				v.push_back(info);
			}
			else if (arr[i][j] == 'D')
			{
				dest_x = i;
				dest_y = j;
			}
		}
	}

	sort(v.begin(), v.end(), cmp); //���� ���� ������ �� �ֵ��� cmp �Լ��� �����Ѵ�.

	
	queue<INFO> q;
	for (int i = 0; i < v.size(); i++)
	{
		q.push(v[i]);
	}

	while (!q.empty())
	{

		int x, y, check;
		x = q.front().x;
		y = q.front().y;
		check = q.front().check;
		
		q.pop();

		if (x == dest_x && y == dest_y) //����ġ��, ��� �ұ��� �����ߴٸ�
		{
			break; //������
		}


		if (check == 0) //���̸�, ���� 4�������� '���' ������. water[nx][ny] == true >> nx�� ny���� ���� ���ö���.
		{
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m) //���� üũ
				{
					if (arr[nx][ny] == 'X' || arr[nx][ny] == 'D') continue; //���� ��('X') �� ����Ǽұ�('D') �� �̵� �� �� ����.

					if (water[nx][ny] == false) //���� ���� �������� ���� ���̸�
					{
						water[nx][ny] = true; //�������� �Ѵ�.

						//�������� �� ���� ��ġ ������ ť�� push �Ѵ�.

						info.x = nx;
						info.y = ny;
						info.check = 0; //���̴ϱ�

						q.push(info); //push
					}

				}
			}
		}

		else if (check == 1) //����ġ���
		{
			gosum_move[x][y] = true; //����ġ�� �̹� �̵��� ��ġ��� ��!

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m) //���� üũ
				{
					if (arr[nx][ny] == 'X') continue; //���̸� �̵� ����
					if (water[nx][ny] == true) continue; //���� �� ������ �̵� ����

					if (gosum_move[nx][ny] == false) //���� ����ġ�� �ѹ��� �������� ���� �����θ� �̵� �����ϹǷ�!
					{
						
						d[nx][ny] = d[x][y] + 1; //�ð� + 1 ���ְ�!
						gosum_move[nx][ny] = true;

						//�����̰� �� ����ġ�� ��ġ ������ ť�� push �Ѵ�.

						info.x = nx;
						info.y = ny;
						info.check = 1; //����ġ�ϱ�

						q.push(info); //push
					}
				}
			}
		}
	}
	
	if (d[dest_x][dest_y] != -1) 
		cout << d[dest_x][dest_y] << '\n';
	else //-1�̸� ���� ���ѰŴϱ�
		cout << "KAKTUS" << '\n';
	
	return 0;
}
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

int n, m, g, x, y;

int arr[34][14];

int res(int column) //column ��ġ���� ��ٸ� Ÿ�� ������ �������� ��, �������� ��ġ
{
	int row = 1;
	while (row <= n)
	{
		//arr[row][column] == 1 �̸� > ���� ���̹Ƿ�, ���������� ���ߵ�. (column -> column+1), ���� �������� ��. (row -> row+1)
		//arr[row][column] == 2 �̸� > ������ ���̹Ƿ�, �������� ���ߵ�. (column -> column-1), ���� �������� ��. (row -> row+1)
		//arr[row][column] == 0 �̸� > �׳� �������⸸ �ϸ� ��. (row -> row+1)

		if (arr[row][column] == 1)
		{
			column += 1;
		}
		else if (arr[row][column] == 2)
		{
			column -= 1;

		}
		row += 1;
	}
	return column;
}

bool correct()
{
	for (int i = 1; i <= m; i++)
	{
		if (i != res(i)) //��� i�� ���ؼ�, i�� ��ٸ��� ����� i���� �ƴ� ��찡 �ϳ��� ���� �� -> ���ǿ� �������� ����!
		{
			return false;
		}
	}

	//��� i�� ��ٸ��� ����� i�� �϶�
	return true;
}

int main()
{
	F_I;

	//[����] 15684�� : ��ٸ� ���� (���Ʈ ����)

	cin >> m >> g >> n;
	for (int i = 0; i < g; i++)
	{
		cin >> x >> y;

		//arr[x][y]=0; // (x,y)���� �ƹ��� ���� ������ �ִ� ���µ� �ƴϴ�.
		arr[x][y] = 1; //�̹� ������ �ִ� ���μ��� ���� �� : 1 �� ǥ��
		arr[x][y+1] = 2; //�̹� ������ �ִ� ���μ��� ������ �� : 2 �� ǥ��	
	}
	
	vector<pi> can; //���μ��� ���� �� �ִ� �ڰ��� �ִ� ��ġ���� ���� ����

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m-1; j++)
		{
			if (arr[i][j] == 0 && arr[i][j + 1] == 0) // ���� ���� (i,j)�̰�, ������ ���� (i,j+1)�� �κп� ���μ��� ���� �� �ִ�.
			{
				can.push_back(make_pair(i, j)); //�������� ���� ���� �� ������ �ϴ� �����ϱ�!
			}
		}
	}

	int size = can.size();
	
	int ans = -1; //default

	if (correct())
	{	
		cout << 0 << '\n';
		return 0;
	}

	for (int i = 0; i < size; i++)
	{
		int x1 = can[i].first; //can �迭�� ���ִ� ù ��° �ĺ��� ���� �� x ��ǥ
		int y1 = can[i].second; //can �迭�� ���ִ� ù ��° �ĺ��� ���� �� y ��ǥ

		if (arr[x1][y1] == 0 && arr[x1][y1 + 1] == 0)
		{
			//���� ���� ������ �� �� �� 0 �̸� (�� ��ġ�� ���μ� ��ġ �����ϴٸ�) , ��ġ�غ���!
			arr[x1][y1] = 1;
			arr[x1][y1 + 1] = 2;

			//1���� ��ġ�ߴµ��� ���ǿ� �����ϸ�?
			if (correct())
			{
				/*
				- ans == -1 ���� ans > 1�� ���ǵ� ���� ����??

				e.g.)
				i = 0,j = 1,k = 2�� ��Ȳ���� ans�� 3�̾��µ�,
				i = 0,j = 1,k = 3�� ��Ȳ���� ���μ��� �Ѱ��� ��ġ �ص� ���ǿ� �����Ѵٸ�,
				ans > 1 �̰� correct() �Լ��� true�̹Ƿ�, ans = 1 �� �ȴ�.

				- ��, ������ �߾��� Ƚ������ �� ���� Ƚ���ε� ������ ���� ����Ͽ� ans > 1 �̶�� ���ǵ� �־���� ���̴�.
				*/
				if (ans == -1 || ans > 1)
				{
					ans = 1; //���� 1��!
				}
			}

			for (int j = i + 1; j < size; j++)
			{
				int x2 = can[j].first; //can �迭�� ���ִ� �� ���� �ĺ��� ���� �� x ��ǥ
				int y2 = can[j].second; //can �迭�� ���ִ� �� ���� �ĺ��� ���� �� y ��ǥ

				if (arr[x2][y2] == 0 && arr[x2][y2 + 1] == 0)
				{
					//���� ���� ������ �� �� �� 0 �̸� (�� ��ġ�� ���μ� ��ġ �����ϴٸ�) , ��ġ�غ���!
					arr[x2][y2] = 1;
					arr[x2][y2 + 1] = 2;

					//2���� ��ġ�ߴµ��� ���ǿ� �����ϸ�?
					if (correct())
					{
						if (ans == -1 || ans > 2)
						{
							ans = 2;
						}
					}

					for (int k = j + 1; k < size; k++)
					{
						int x3 = can[k].first;
						int y3 = can[k].second;

						if (arr[x3][y3] == 0 && arr[x3][y3 + 1] == 0)
						{
							//���� ���� ������ �� �� �� 0 �̸� (�� ��ġ�� ���μ� ��ġ �����ϴٸ�) , ��ġ�غ���!
							arr[x3][y3] = 1;
							arr[x3][y3 + 1] = 2;

							//3�� �� ��ġ�� ���Ŀ� ���ǿ� �����ϸ�?
							if (correct())
							{
								if (ans == -1 || ans > 3)
								{
									ans = 3;
								}
							}
							arr[x3][y3] = 0;
							arr[x3][y3 + 1] = 0;
						}
					}
					arr[x2][y2] = 0;
					arr[x2][y2 + 1] = 0;
				}
			}
			arr[x1][y1] = 0;
			arr[x1][y1 + 1] = 0;
		}
	}

	cout << ans << '\n';


	return 0;
}
#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int n, m, g, x, y;

int arr[34][14];

int res(int column) //column 위치에서 사다리 타고 끝까지 내려갔을 때, 최종적인 위치
{
	int row = 1;
	while (row <= n)
	{
		//arr[row][column] == 1 이면 > 왼쪽 끝이므로, 오른쪽으로 가야됨. (column -> column+1), 또한 내려가야 됨. (row -> row+1)
		//arr[row][column] == 2 이면 > 오른쪽 끝이므로, 왼쪽으로 가야됨. (column -> column-1), 또한 내려가야 됨. (row -> row+1)
		//arr[row][column] == 0 이면 > 그냥 내려가기만 하면 됨. (row -> row+1)

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
		if (i != res(i)) //모든 i에 대해서, i번 사다리의 결과가 i번이 아닌 경우가 하나라도 있을 때 -> 조건에 부합하지 않음!
		{
			return false;
		}
	}

	//모든 i번 사다리의 결과가 i번 일때
	return true;
}

int main()
{
	F_I;

	//[백준] 15684번 : 사다리 조작 (브루트 포스)

	cin >> m >> g >> n;
	for (int i = 0; i < g; i++)
	{
		cin >> x >> y;

		//arr[x][y]=0; // (x,y)에는 아무런 선이 놓여져 있는 상태도 아니다.
		arr[x][y] = 1; //이미 놓여져 있는 가로선의 왼쪽 끝 : 1 로 표기
		arr[x][y+1] = 2; //이미 놓여져 있는 가로선의 오른쪽 끝 : 2 로 표기	
	}
	
	vector<pi> can; //가로선을 놓을 수 있는 자격이 있는 위치들의 정보 저장

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m-1; j++)
		{
			if (arr[i][j] == 0 && arr[i][j + 1] == 0) // 왼쪽 끝이 (i,j)이고, 오른쪽 끝이 (i,j+1)인 부분에 가로선을 놓을 수 있다.
			{
				can.push_back(make_pair(i, j)); //가독성을 위해 왼쪽 끝 정보만 일단 저장하기!
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
		int x1 = can[i].first; //can 배열에 들어가있는 첫 번째 후보의 왼쪽 끝 x 좌표
		int y1 = can[i].second; //can 배열에 들어가있는 첫 번째 후보의 왼쪽 끝 y 좌표

		if (arr[x1][y1] == 0 && arr[x1][y1 + 1] == 0)
		{
			//왼쪽 끝과 오른쪽 끝 둘 다 0 이면 (그 위치에 가로선 설치 가능하다면) , 설치해보기!
			arr[x1][y1] = 1;
			arr[x1][y1 + 1] = 2;

			//1개만 설치했는데도 조건에 만족하면?
			if (correct())
			{
				/*
				- ans == -1 말고 ans > 1의 조건도 넣은 이유??

				e.g.)
				i = 0,j = 1,k = 2인 상황에서 ans가 3이었는데,
				i = 0,j = 1,k = 3인 상황에서 가로선을 한개만 설치 해도 조건에 부합한다면,
				ans > 1 이고 correct() 함수가 true이므로, ans = 1 이 된다.

				- 즉, 이전에 했었던 횟수보다 더 작은 횟수로도 가능할 때를 대비하여 ans > 1 이라는 조건도 넣어놓은 것이다.
				*/
				if (ans == -1 || ans > 1)
				{
					ans = 1; //답을 1로!
				}
			}

			for (int j = i + 1; j < size; j++)
			{
				int x2 = can[j].first; //can 배열에 들어가있는 그 다음 후보의 왼쪽 끝 x 좌표
				int y2 = can[j].second; //can 배열에 들어가있는 그 다음 후보의 왼쪽 끝 y 좌표

				if (arr[x2][y2] == 0 && arr[x2][y2 + 1] == 0)
				{
					//왼쪽 끝과 오른쪽 끝 둘 다 0 이면 (그 위치에 가로선 설치 가능하다면) , 설치해보기!
					arr[x2][y2] = 1;
					arr[x2][y2 + 1] = 2;

					//2개만 설치했는데도 조건에 만족하면?
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
							//왼쪽 끝과 오른쪽 끝 둘 다 0 이면 (그 위치에 가로선 설치 가능하다면) , 설치해보기!
							arr[x3][y3] = 1;
							arr[x3][y3 + 1] = 2;

							//3개 다 설치한 이후에 조건에 만족하면?
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
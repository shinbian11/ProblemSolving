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

int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int main()
{
	F_I;

	 /*
	 백준 16956번 : 늑대와 양 (BFS)

	- 입력받은 목장 지도에서, 단 한마리의 늑대라도, 양과 바로 인접한 곳(거리 1의 상하좌우 칸)에 위치하고 있으면 , 
	울타리를 어떻게 쳐도 소용 없으므로 0 출력. 그게 아니라면 그냥 빈칸에 모조리 울타리를 쳐버리면 되므로 1 출력.

	- 설치해야 하는 울타리의 최소의 개수를 구하는 문제가 아니다! 생각의 전환만 한다면 쉬운 문제이다.
	 */

	int r, c;
	cin >> r >> c;

	vector<string> v(r);

	for (int i = 0; i < r; i++)
		cin >> v[i];

	bool exist = false; //늑대가 양과 바로 인접한 공간에 있으면(exist = true), 울타리를 치더라도 소용없기 때문에, 이런 경우는 0 출력

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (v[i][j] == 'S')
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dir[k][0];
					int ny = j + dir[k][1];
					if (nx >= 0 && nx < r && ny >= 0 && ny < c)
					{
						if (v[nx][ny] == 'W')
						{
							exist = true;
							break;
						}
					}
				}
			}
		}
	}

	if (exist) //최소 한 마리의 늑대가 바로 양 인접한 곳에 있으므로, 울타리를 어떤 방식으로 설치해도 늑대는 양이 있는 곳으로 움직일 수 있다.
		cout << 0 << '\n';
	else
	{
		cout << 1 << '\n';

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++) 
			{
				if (v[i][j] == '.')
					cout << 'D';
				else
					cout << v[i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}
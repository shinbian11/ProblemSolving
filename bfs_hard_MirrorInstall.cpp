#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{

	/*
	[백준] 2151번 : 거울 설치 (BFS)

	e.g.) 

	***#*
	*.!.*
	*!.!*
	*.!.*
	*#***

	- 이런 배열이 있을 때, number 배열은 0 1 2 3 4 5 가 나오고, 
	info 배열은
	0 3 (#)
	1 2 (!)
	2 1 (!)
	2 3 (!)
	3 2 (!)
	4 1 (#)
	이 나온다.

	또한, exist 배열은 아래와 같이 나온다.

	0 0 0 1 0 0   (0번과 3번)
	0 0 0 0 1 0   (1번과 4번)
	0 0 0 1 0 1   (2번과 3번) (2번과 5번)
	1 0 1 0 0 0   (3번과 0번) (3번과 2번)
	0 1 0 0 0 0   (4번과 1번)
	0 0 1 0 0 0   (5번과 2번)

	마지막으로, dist 배열은 아래와 같이 나온다.
	0 -1 2 1 -1 3

	*/

	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> number; //문이나 거울을 설치 할 수 있는 위치를 모두 찾아서 각각 numbering 해놓기
	vector<pi> info; //그때의 x,y값 저장

	int start = -1, end = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == '#') //문
			{
				if (start == -1) //첫번째 문이면
				{
					start = number.size(); //번호 매기고
					number.push_back(start);  //번호 저장
				}
				else if (start != -1 && end == -1) //두번째 문이면
				{ 
					end = number.size(); //번호 매기고
					number.push_back(end); //번호 저장
				}
				info.push_back(make_pair(i, j)); //x행 y열의 정보 저장하고
			}
			if (arr[i][j] == '!') //거울 설치 할 수 있는 곳
			{
				number.push_back(number.size()); //번호 매기고
				info.push_back(make_pair(i, j)); //x행 y열의 정보 저장하고
			}
		}
	}
	int size = number.size();
	
	

	//exist[i][j] => number 배열에서 매겨져 있는 번호를 토대로, i번 문/거울에서 j번 문/거울으로 거울을 설치 할 수 있으면 true, 없으면 false
	//i번째 장소에서 같은 방향으로 쭉 갔을 때, 해당되는 모든 j를 true로!

	vector< vector<bool> > exist(size, vector<bool>(size)); 

	for (int i = 0; i < size; i++)
	{
		int x = info[i].first;
		int y = info[i].second;
		for (int j = 0; j < 4; j++)
		{
			int nx = x + dx[j];
			int ny = y + dy[j];

			while (nx >= 0 && nx < n && ny >= 0 && ny < n) //배열 범위 체크
			{
				if (arr[nx][ny] == '*')
					break;
				if (arr[nx][ny] == '#' || arr[nx][ny] == '!')
				{
					for (int k = 0;k < size; k++)
					{
						if (info[k].first == nx && info[k].second == ny)
						{
							exist[i][k] = true; //i번에서 k번으로 거울 설치 가능!
							break;
						}
					}
					
				}
				//같은 방향으로 계속 직진 (배열 범위 넘기 직전까지)
				nx += dx[j];
				ny += dy[j];
			}
		}
	}

	
	vector<int> dist(size, -1); //거리 계산

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
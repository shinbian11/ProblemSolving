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
	고슴도치는 물이 찰 예정인 칸으로 이동할 수 없다. 즉, 다음 시간에 물이 찰 예정인 칸으로 고슴도치는 이동할 수 없다 라는 말에 의해서,
	물을 먼저 인접한 4방향으로 이동시키고, 그 이후에 고슴도치를 이동시키는 순서로 진행을 하도록 설계하기 위해서,
	물은 check = 0을, 고슴도치는 check = 1을 넣어서, queue에 들어온 정보들 중 물의 정보들을 먼저 queue의 앞에 오도록 sort 시켜야 한다.
	*/
	return a.check < b.check;
}

int main()
{
	F_I;

	//[백준] 3055번 : 탈출 (bfs)

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

			if (arr[i][j] == '*') //물
			{
				info.x = i;
				info.y = j;
				info.check = 0;
				v.push_back(info);
			}
			else if (arr[i][j] == 'S') //고슴도치
			{
				d[i][j] = 0; //고슴도치가 처음 있는 위치는 현재 시간이 0초다.
				
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

	sort(v.begin(), v.end(), cmp); //물이 먼저 움직일 수 있도록 cmp 함수에 정의한다.

	
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

		if (x == dest_x && y == dest_y) //고슴도치가, 비버 소굴에 도착했다면
		{
			break; //나가기
		}


		if (check == 0) //물이면, 인접 4방향으로 '모두' 퍼진다. water[nx][ny] == true >> nx행 ny열에 물이 차올랐다.
		{
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m) //범위 체크
				{
					if (arr[nx][ny] == 'X' || arr[nx][ny] == 'D') continue; //물은 돌('X') 과 비버의소굴('D') 로 이동 할 수 없다.

					if (water[nx][ny] == false) //아직 물이 도달하지 못한 곳이면
					{
						water[nx][ny] = true; //차오르게 한다.

						//차오르게 된 물의 위치 정보를 큐에 push 한다.

						info.x = nx;
						info.y = ny;
						info.check = 0; //물이니까

						q.push(info); //push
					}

				}
			}
		}

		else if (check == 1) //고슴도치라면
		{
			gosum_move[x][y] = true; //고슴도치가 이미 이동한 위치라는 뜻!

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m) //범위 체크
				{
					if (arr[nx][ny] == 'X') continue; //돌이면 이동 못함
					if (water[nx][ny] == true) continue; //물이 차 있으면 이동 못함

					if (gosum_move[nx][ny] == false) //아직 고슴도치가 한번도 도달하지 못한 곳으로만 이동 가능하므로!
					{
						
						d[nx][ny] = d[x][y] + 1; //시간 + 1 해주고!
						gosum_move[nx][ny] = true;

						//움직이게 된 고슴도치의 위치 정보를 큐에 push 한다.

						info.x = nx;
						info.y = ny;
						info.check = 1; //고슴도치니까

						q.push(info); //push
					}
				}
			}
		}
	}
	
	if (d[dest_x][dest_y] != -1) 
		cout << d[dest_x][dest_y] << '\n';
	else //-1이면 도달 못한거니까
		cout << "KAKTUS" << '\n';
	
	return 0;
}
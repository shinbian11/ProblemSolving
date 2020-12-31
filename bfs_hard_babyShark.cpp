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

int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int n;

int isinside(int nx, int ny)
{
	if (nx >= 0 && nx < n && ny >= 0 && ny < n)
		return 1;
	else
		return 0;
}

tuple<int, int, int> bfs(int current_x, int current_y, vector< vector<int> > v, int current_size)
{
	//current_x행, current_y열(현재위치) 에서, 여러가지 사항을 따졌을 때, 다음에 이동할 최적의 원소의 위치를 찾는 함수이다.

	int n = v.size();
	queue< pair<int, int> > q;
	vector< vector<int> > d(n, vector<int>(n, -1)); //n * n 행렬. 모든 원소는 -1로 초기화시킨다. 거리의 값을 저장하는 배열
	vector< tuple<int, int, int> > eating;

	q.push(make_pair(current_x, current_y));
	d[current_x][current_y] = 0;

	while (!q.empty()) //n*n 배열에서 탐색 가능한 모든 곳을 다 돌아다니기!
	{
		int x, y;
		tie(x, y) = q.front();

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			//int nx = x + dir[i][0];
			//int ny = y + dir[i][1];

			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			// nx행 ny열 원소가 배열 안에 있고, 한번도 방문하지 않았을 때(visited 배열 대신, d[nx][ny] == -1 으로 방문처리를 대신함)
			// d배열을 처음에 -1로 초기화했으므로, d[nx][ny] == -1 이라는건 아직 그 곳에 한번도 간 적 없다는 의미이다.
			if (isinside(nx, ny) && d[nx][ny] == -1)
			{
				bool eat = false;
				bool move = false;

				// 가고자 하는 자리가 빈칸이면(0) , 그냥 이동만 가능 (물고기가 없으니 먹을 순 없다)
				if (v[nx][ny] == 0) //질문 : 이 조건이 마지막에 오면 안되는 이유???
					move = true;

				//아기상어의 크기와 가고자 하는 자리의 물고기의 크기가 같으면, 먹을 순 없고, 이동만 가능.
				else if (v[nx][ny] == current_size)
					move = true;
				//그 다음에 가고자 하는 후보 자리(nx행 ny열)의 물고기의 크기가 v[nx][ny]인데, 현재 아기상어의 크기(current_size)가 더 크면 먹을 수 있고, 이동도 가능하다.
				else if (v[nx][ny] < current_size)
					move = eat = true;


				if (move)// 이동 가능하면
				{
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
					if (eat) //이동 가능하고, 먹을 수도 있으면,
					{
						eating.push_back(make_tuple(d[nx][ny], nx, ny)); //먹으러 가는 그 경로(상어가 움직이는 정보)를 일일히 저장해둔다)
					}
				}

			}
		}
	}
	// eating 벡터가 비었다는 의미는, 그 자리에서 갈 수 있는 모든 곳을 bfs로 탐색했는데도 불구하고, 먹을 수 있는 물고기가 없다는 의미이므로,
	// 이때는 이제 작업을 끝내고 최종 답을 내야 한다는 의미이므로, 그 의미를 전달해주어야 함!
	if (eating.empty())
	{
		return make_tuple(-1, -1, -1);
	}
	else
	{
		/*
		만약 먹을 수 있는 물고기가 여러 마리일때, 우선순위를 따져야 하는데,
		문제에 따라 1순위는 거리(최소), 2순위는 행(위쪽), 3순위는 열(왼쪽)이다.
		정렬을 하면, 거리를 기준으로 내림차순이 되고, 거리가 같으면 행이 작을수록(위에 있는 물고기일수록), 행도 같으면 열이 작을수록(왼쪽에 있는 물고기일수록) > 이 기준으로 정렬이 된다.
		즉 eating[0]은 3가지 우선순위를 모두 고려했을 때, 먹을 수 있는 물고기들의 후보 들 중에 가장 적합한 물고기이다. 아기상어는 그 쪽으로 이동을 해야한다.
		*/
		sort(eating.begin(), eating.end());
		/*
		- tuple 출력법 배움! v[2]의 2번째 원소 출력 하고 싶으면 : get<2>(v[2]) 라고 하면 된다!
		for (int i = 0; i < eating.size(); i++)
			cout << get<0>(eating[i]) << ' ' << get<1>(eating[i]) << ' ' << get<2>(eating[i]) << ' ' << '\n';
			*/
		return eating[0];
	}
}
int main()
{
	/*
	일단 n^2 * n^2 로, 문제를 2덩어리로 나눠야 한다.
	현재 위치에서 어디로 가야할 지 찾는 부분(bfs(shark_x, shark_y, v, shark_size) 함수가 담당. 이거는 최대 n^2 시간이 걸림. 최악의 경우 배열의 모든 원소를 다 따져봐야 하는 경우도 있으니까)
	그리고 모든 위치위치마다 그 경우를 따져야 하니까(main함수의 while문에서 담당), 그것도 최악의 경우 n^2만큼 걸린다.
	즉 n^2 * n^2 = O(n^4)만큼의 시간복잡도가 소요된다!
	*/

	// 백준 16236번 : 아기상어 (bfs 심화 + vector< tuple<int, int, int> > 의 원소 출력 방법 공부!!!)
	F_I;
	//int n;
	cin >> n;
	vector< vector<int> > v(n, vector<int>(n)); //입력받는 배열. 
	//vector<int> 자료형을 띄고 있는 원소 n개를 넣을건데, 그 원소들은 각각 int형의 n개의 원소를 가지고 있다는 의미
	//다시 말해 n * n 2차원 배열을 선언하는 것과 같은 의미이다.

	int shark_x, shark_y; //상어의 위치를 기록. 

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == 9) //맨 처음 상어의 위치를 발견했으면,
			{
				shark_x = i; //기록하기 (x 좌표)
				shark_y = j; //기록하기 (y 좌표)
				v[i][j] = 0; //상어의 위치를 기록했으면 그냥 빈칸 취급 해도 된다.
			}
		}
	}


	int shark_size = 2; //처음 아기 상어의 크기는 2이다.
	int exp = 0; //경험치. 물고기를 먹을 때마다 exp가 1씩 증가하며, exp가 shark_size랑 같아지면, shark_size는 1 증가하고, exp는 0으로 초기화
	int final_dist = 0; //최종 답. 이 변수를 출력

	while (true)
	{
		int local_dist, local_nx, local_ny;
		tie(local_dist, local_nx, local_ny) = bfs(shark_x, shark_y, v, shark_size); //bfs는 현재 아기상어의 위치와 사이즈를 통해, 그 다음으로 움직여야 하는 최적의 정보를 반환하는 함수이다.

		if (local_dist == -1)//현재 위치에서 탐색을 했을 때, 어떤 곳으로 가더라도 더 이상 먹을 수 있는 물고기가 없을 때, tuple<-1,-1,-1>을 반환하므로!
		{
			cout << final_dist << '\n';
			return 0;
		}
		v[local_nx][local_ny] = 0; //물고기를 먹으면, 그 자리는 빈칸이 된다고 문제에서 언급함

		/*
		최적의 경로만큼 더해주기. 예를 들어 최적의 다음 장소로 가려면 2만큼이 필요하면 local_dist에는 2가 반환됨.
		그 2를 final_dist 에 더해주기
		*/
		final_dist += local_dist;

		exp += 1; //경험치 + 1 해주고(물고기 먹었으니까)

		//경험치랑 아기상어 크기랑 같을 때에는 아기상어의 크기를 1 증가시킨다고 문제에서 언급했으므로(물고기 1마리 먹을때마다 아기상어의 사이즈가 1씩 증가하는 게 아니다.)
		if (exp == shark_size)
		{
			shark_size += 1;
			exp = 0;
		}
		shark_x = local_nx;
		shark_y = local_ny;
	}

	return 0;
}
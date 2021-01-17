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

	group_cnt += 1; //group_cnt : 그룹 번호 매기는 변수.

	group_numbering[i][j] = group_cnt; //i행 j열의 칸은 group_cnt번째 그룹에 속해있다.

	int cnt = 1; // group_cnt번째 그룹의 크기 (1의 개수) 체크

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
				if (arr[nx][ny] == 1 && group_numbering[nx][ny] == 0) //인접해있는 nx행 ny열의 칸도 1이고, 그 칸이 아직 특정 그룹에 속해 있지 않을 때,
				{
					group_numbering[nx][ny] = group_cnt; //인접해있는 nx행 ny열의 칸은 group_cnt번째 그룹에 속해있다.

					cnt += 1; //group_cnt번째 그룹의 1의 개수를 1 증가시킴
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	group_size[group_cnt] = cnt; // group_cnt번째 그룹의 크기는 cnt 이다.(group_cnt번째 그룹에 있는 1은 cnt개이다.)

}

int main()
{
	F_I;

	//16932번 : 모양 만들기 (BFS + 벡터의 중복 제거 방법 (unique) + 인접 정보 이용)

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	//입력받은 n * n 배열에서 모양을 구분짓는다.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1 && group_numbering[i][j] == 0)
				bfs(i, j);
		}
	}

	//0에 해당되는 부분을 1로 바꿨을 때, 어떤 변화가 일어나는지를 조사
	//0에 해당되는 칸을 1로 바꾸면, 그 칸의 인접되어 있는 칸들 중에, 그룹에 속해있는 원소가 있다면,
	//그 원소들이 속해있는 그룹들끼리 이어진다! 
	//0에 해당되는 부분을 1로 바꿨을 때의 모양(그룹)의 크기의 최대값 > 각각의 그룹의 사이즈의 합 + 1 이다.
	/*
	 
	- 모양(그룹)이 2개인 4*4배열! 왼쪽 상단의 그룹을 1번 그룹, 우측 하단의 그룹을 2번 그룹이라 하자.
	
	1 1 0 0
	1 0 0 0 
	0 0 1 1
	0 0 0 0

	- 이러한 모양의 그룹에서, 1행 1열의 0을 1로 바꾼다면, 1번 그룹과 2번 그룹은 이어진다!

	1 1 0 0
	1'1'0 0
	0 0 1 1
	0 0 0 0

	> 그렇게 되면, 1번 그룹의 크기 + 2번 그룹의 크기 + 1행 1열의 크기  => 3 + 2 + 1 = 크기 6의 모양(그룹)을 얻을 수 있다.

	> 이렇게 얻을 수 있는 모양의 크기들 중, 최대값을 출력하기! (여기서는 ans라는 변수가 답이다.)
	*/

	int ans = -1; // 최종 출력하고자 하는 답

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0) //0을 1로 바꿨을때
			{
				vector<int> near_info;
				
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dir_x[k];
					int ny = j + dir_y[k];

					if (nx >= 0 && nx < n && ny >= 0 && ny < m)
					{
						if (arr[nx][ny] == 1) //인접 부분이 1이라면, 그 1의 group_numbering을 near_info 배열에다가 모두 저장해놓는다.
						{
							near_info.push_back(group_numbering[nx][ny]);
						}
						/*
						arr[i][j]==0일때, 그 칸의 인접한 상하좌우 칸들 중에서, 상,좌 방향에 1이 있고 우 방향엔 0, 하 방향에 1이 있다고 가정하고,
						상,좌 방향의 1은 1번 그룹, 하 방향의 1은 2번 그룹일때, near_info 벡터에는 1 2개와, 2 1개의 값이 들어가 있다.
						*/
					}
				}

				//참고 : http://blog.naver.com/PostView.nhn?blogId=withham1&logNo=221102099316
				//중복된 정보는 제거 (1번 그룹 2번, 2번 그룹 1번 들어가 있는데, 사이즈는 1번씩만 체크해야 하므로!)
				//near_info 벡터 안의 정보를 1번 그룹 2번, 2번 그룹 1번 -> 1번 그룹 1번, 2번 그룹 1번 으로 변경하기!

				/*
				e.g.) near_info 벡터가 1 3 2 1 1 3 이 있을 때,

				정렬하면 : 1 1 1 2 3 3 이 되고, 

				unique를 쓰면 중복되는 수를 맨 뒤로 보냄 : 1 2 3 ? ? ? (앞에 1 2 3 은 중복 안된 값, 뒤에 ? ? ? 은 중복된 값(1 두개와 3 1개))

				이떄 unique는 중복되지 않는 부분의 end() 주소 (== ? 들의 시작 위치 주소)를 반환한다.

				erase(a,b)는 [a,b)를 지워주는 함수이므로, 3번째 인덱스 부터 5번째 인덱스까지 지우고 싶다면 .erase(3,6)을 쓰면 된다.

				아까전에 unique에서 중복되는 부분의 첫 부분을 반환한다고 했으므로,
				벡터의 중복 부분을 삭제하고 싶으면 erase 함수의 '첫 부분'은 unique 함수가 반환한 값, '마지막 부분'은 벡터의 end()를 넣어주면 된다.

				near_info.erase(    unique(near_info.begin(), near_info.end())  ,  near_info.end()   ); 
				-> 1 2 3 ? ? ? 에서 ? ? ? 부분 삭제 => 1 2 3 만 남는다.

				*/
				sort(near_info.begin(), near_info.end()); //정렬하고,
				near_info.erase(unique(near_info.begin(), near_info.end()), near_info.end()); //벡터의 중복 제거방법 (unique)

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
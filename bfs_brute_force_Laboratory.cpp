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

int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs(vector< vector<int> >& copy, vector<pi>& virus) //안전 영역 구하기
{
	
	queue<pi> q;

	for (int i = 0; i < virus.size(); i++)
	{
		int x = virus[i].first;
		int y = virus[i].second;

		q.push(make_pair(x, y));
	}

	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (copy[nx][ny] == 0)
				{
					copy[nx][ny] = copy[x][y]; //2를 저장
					q.push(make_pair(nx, ny));

				}
			}

		}
	}

	int cnt = 0;
	
	//안전 영역 개수 구하기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (copy[i][j] == 0)
				cnt += 1;
		}
	}

	return cnt;
}

int main()
{
	F_I;

	//[백준] 14502번 : 연구소 (bfs, 브루트 포스)

	cin >> n >> m;
	vector<pi> b; //빈칸 정보 저장
	vector<pi> virus; //바이러스 정보 저장

	vector< vector<int> > arr(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 0)
				b.emplace_back(i, j);
			if (arr[i][j] == 2)
				virus.emplace_back(i, j);
		}
	}
	
	

	int size = b.size();
	int ans = -1;

	/*
	- 벽을 설치 할 수 있는 후보들, 다시 말해 모든 빈칸들 중에서 3개를 고르는 경우의 수 -> 최악의 경우 : 64C3 = 64! / (61! 3!) > 시간 내에 가능!
	빈칸들 중 벽을 설치할 세 곳을 임의로 정해서, 1 처리 해놓고, 그때마다 안전 영역의 크기를 구해 최대값을 최종적으로 출력한다.
	*/

	//빈칸들 중 벽을 설치할 세 곳을 브루트 포스로 정하기
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			for (int k = j + 1; k < size; k++)
			{
				vector< vector<int> > copy(arr);

				//벽 설치한다고 가정
				copy[b[i].first][b[i].second] = 1;
				copy[b[j].first][b[j].second] = 1;
				copy[b[k].first][b[k].second] = 1;

				//그때의 안전 영역 구하기
				int safe = bfs(copy,virus);

				if (ans < safe)
					ans = safe;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
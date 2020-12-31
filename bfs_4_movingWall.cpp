#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수


bool visited[8][8][9]; // visited[x][y][t] : t초 뒤에 x행 y열을 방문했는지 여부를 판단
int dir[9][2] = { {0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1},{0,0} }; //{0,0} : 그 자리에 가만히 있는 경우

int main()
{
	
	F_I;
	 
	//16954번 백준 : 움직이는 미로 탈출 (c++)

	vector<string> matrix(8);

	for (int i = 0; i < 8; i++)
	{
		cin >> matrix[i];
	}

	queue< tuple<int, int, int> > q;

	visited[7][0][0] = true;
	q.push(make_tuple(7, 0, 0));

	bool ans = false;

	while (!q.empty())
	{
		int x, y, t;
		tie(x, y, t) = q.front();
		q.pop();

		if (x == 0 && y == 7)
		{
			ans = true; //0행 7열(최종 도착지)에 도달하면 true이다.
			break;
		}

		for (int i = 0; i < 9; i++)
		{

			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			int nt = (int)Min((ll)t + 1, (ll)8);

			if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
			{

				//현재 matrix[nx][ny]에 위치해 있을 때, t초 후에 그 자리가 벽인지 아닌지를 판단하려면 matrix[nx-t][ny]가 벽인지 아닌지를 보면 된다!
				//1초에 한 줄씩 벽이 내려오니까, t초 후에는 벽이 t만큼 내려오는 것! matrix[nx][ny]의 자리에 t초 후에 오게 될 원소는 matrix[nx-t][ny]이다.
				if (nx - t >= 0 && matrix[nx - t][ny] == '#')  //nx행 ny열에서(현재 위치에서), t초 뒤에 내려올 원소가 벽이라면 그쪽으로는 움직이면 안된다.
					continue;

				//nx행 ny열에서(현재 위치에서), t+1초 뒤에 내려올 원소가 벽이라면 그쪽으로는 움직이면 안된다.
				//욱제의 캐릭터가 먼저 움직이고 난 다음에 벽이 움직이는데, 만약 현 위치가 7행 0열이고, t는 1이고, 5행 0열이 벽이라면
				//1초 뒤에 내가 6행 0열로 움직이고 난 다음, 5행 0열에 있는 벽이 내려오니까... 그러면 움직일 수 없다! 즉, 이때도 역시 이동 못한다.
				if (nx - t - 1 >= 0 && matrix[nx - t - 1][ny] == '#')
					continue;

				if (visited[nx][ny][nt] == false)
				{
					visited[nx][ny][nt] = true;
					q.push(make_tuple(nx, ny, nt));
				}
			}
		}
	}

	if (ans == false)
		cout << 0 << '\n';
	else
		cout << 1 << '\n';

	return 0;
}
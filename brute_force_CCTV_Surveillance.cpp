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

/*
(회전 방향) 

오른쪽 : 0
아래 : 1
왼쪽 : 2 
위쪽 : 3 
- 회전 방향을 반시계방향으로 통일함. 

- 밑의 dx,dy에 이 사실을 반영하여 값을 저장함

*/

int dx[4] = { 0,1,0,-1 }; //우,하,좌,상
int dy[4] = { 1,0,-1,0 }; //우,하,좌,상

//x행 y열의 cctv에서, rotate[i] 방향에 있는 빈칸들을 모두 그 cctv가 감시할 수 있는 칸으로 작업해놓는 함수
void check(vector< vector<int> >& v, vector< vector<int> >& b, int sx, int sy, int dir) //dir : 회전 방향 (0,1,2,3)
{
	int n = v.size();
	int m = v[0].size();
	int x = sx;
	int y = sy;

	while (x >= 0 && x < n && y >= 0 && y < m) //범위 체크
	{
		if (v[x][y] == 6)
			break;
		// -1이 문제에서는 # 처리한 것과 같다. 해당 칸이 감시 영역에 들어갔다는 의미.
		b[x][y] = -1; 
		// b 배열을 굳이 만드는 이유 : 이렇게 사무실 배열의 임의의 칸의 값을 계속 변경해야 하기 때문에, a 배열 하나로는 무리이다! 
		// 한 경우에 대해 끝내고 다음 경우를 들어가기 전에, a 배열을 그때그때 복원시키는 건 너무 귀찮으니까!
		// 그러므로 4^c 의 경우를 하나하나 할때마다, 새로운 b 배열을 만들어서 그 귀찮음을 해결한다.

		x += dx[dir]; //dir 방향으로 계속 나아감
		y += dy[dir]; //dir 방향으로 계속 나아감
	}
}

int find(vector< vector<int> >& v, vector< tuple<int, int, int> >& cctv, int cctv_index, vector<int>& rotate)
{
	int n = v.size();
	int m = v[0].size();

	//모든 cctv를 다 탐색했을 때
	if (cctv.size() == cctv_index)
	{
		vector< vector<int> > b(v); //사무실 배열의 수정본

		for (int i = 0; i < cctv.size(); i++)
		{
			int cctv_what, x, y;
			tie(cctv_what, x, y) = cctv[i];

			if (cctv_what == 1) //i번째 cctv가 1번 cctv라면 
			{
				check(v, b, x, y, rotate[i]); //x행 y열의 cctv에서, rotate[i] 방향에 있는 빈칸들을 모두 그 cctv가 감시할 수 있는 칸으로 작업해놓는 함수
			}
			else if (cctv_what == 2) //i번째 cctv가 2번 cctv라면
			{
				check(v, b, x, y, rotate[i]);
				check(v, b, x, y, (rotate[i]+2)%4);
			}
			else if (cctv_what == 3) //i번째 cctv가 3번 cctv라면
			{
				check(v, b, x, y, rotate[i]);
				check(v, b, x, y, (rotate[i] + 1) % 4);
			}
			else if (cctv_what == 4) //i번째 cctv가 4번 cctv라면
			{
				check(v, b, x, y, rotate[i]);
				check(v, b, x, y, (rotate[i] + 1) % 4);
				check(v, b, x, y, (rotate[i] + 2) % 4);
			}
			else if (cctv_what == 5) //i번째 cctv가 5번 cctv라면
			{
				check(v, b, x, y, rotate[i]);
				check(v, b, x, y, (rotate[i] + 1) % 4);
				check(v, b, x, y, (rotate[i] + 2) % 4);
				check(v, b, x, y, (rotate[i] + 3) % 4);
			}
		}

		//main 함수에서 step2 에 해당하는 코드 : 사각지대 개수 세기
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (b[i][j] == 0) //빈칸이면(cctv의 감시 영역에 닿지 않는 부분)
					cnt += 1;
			}
		}

		return cnt;
	}


	int ans = 65; //사각지대는 아무리 많아봐야 8*8= 64개이다.

	for (int i = 0; i < 4; i++)
	{
		rotate[cctv_index] = i; //cctv_index 번째 cctv는 i번째 회전 방향을 따른다.
		int tmp = find(v, cctv, cctv_index + 1, rotate); // 그 다음 cctv
		if (ans > tmp)
			ans = tmp; //최소값
	}

	return ans;
}

int main()
{
	F_I;

	/*
	15683번 : 감시 (브루트 포스)

	- 접근 방법 

	cctv 1번  : 회전하면 4가지 방향 감시 가능
	cctv 2번  : 회전하면 2가지 방향 감시 가능
	cctv 3번  : 회전하면 3가지 방향 감시 가능
	cctv 4번  : 회전하면 3가지 방향 감시 가능
	cctv 5번  : 회전하면 1가지 방향 감시 가능

	그렇기 때문에, cctv가 c개라면, 
	step 1 : cctv가 감시할 수 있는 방향의 경우의 수 (cctv의 경우의 수) : 최대 O(4^c) 가지이다. 
	물론 엄연히 봤을 때는 cctv 번호에 따라 1~4가지이지만, 그냥 모든 cctv가 4가지 방향이 감시 가능하다라고 생각하고 처리해도 시간복잡도에서 큰 차이가 나지 않기 때문에,
	간결하게 일반화 해서 문제를 처리하기 위해 모두 회전하면 4가지 방향이 감시 가능하다고 가정하고 문제를 풀이 할 것이다.
	
	step 2: 4^c 가지가 나오고, 한번 cctv c개의 감시 방향이 모두 설정이 되면, 그때 나오는 사각지대의 개수를 세려면 O(n*m)의 시간복잡도가 소요된다.

	즉, 전체적으로 O((4^c) *(n*m)) 이고, c,n,m <= 8 이므로, 제한시간 내에 가능하다.
	*/

	int n, m;
	cin >> n >> m;

	vector< vector<int> > v(n, vector<int>(m)); //사무실 정보 입력
	vector< tuple<int, int, int> > cctv; //cctv의 정보 저장(1~5번, x,y)
	vector<int> rotate; //cctv가 회전을 한 횟수(최대 4회)

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			if (v[i][j] != 0 && v[i][j] != 6) //cctv라면
			{
				//emplace_back과 push_back의 차이점 : push_back은 make_tuple을 사용해서 객체화 시켜서 push 해야 함. 
				//emplace_back은 알아서 객체화 시켜줌.그러므로 인자들만 넣으면 됨.
				//(몇번 cctv인지, 그 cctv의 x행, y열) 을 순서대로 저장
				cctv.emplace_back(v[i][j],i,j); 
				//cctv.push_back(make_tuple(v[i][j], i, j)); 
				rotate.push_back(0); //최초 입력받았을 때는 한번도 회전을 안한 상태이므로 0 저장
			}
		}
	}
	
	int cctv_index = 0; //0번째 cctv부터 차례대로!

	cout << find(v, cctv, cctv_index, rotate) << '\n';

	return 0;
}
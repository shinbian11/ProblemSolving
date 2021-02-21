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

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
	F_I;

	//[백준] 1525번 : 퍼즐 (bfs)

	/*
	* <bfs 문제의 조건>
	* 1. 최소횟수 구하는 문제
	* 2. 모든 움직임 (move)의 가중치가 1이고
	* 3. 정점과 간선의 개수가 작다


	입력 받은 3 x 3 퍼즐을 하나의 정수로 바꾸고,
	그 정수를 문자열화 한다음, 그 이후 빈칸의 인접한 숫자들과 swap을 하여 빈칸으로 숫자를 이동시키는 효과를 준 이후,
	그 결과를 다시 정수화 시키고, 그 경우의 최소 횟수를 갱신하는 과정을 반복한다.
	*/

	int n = 3;
	int num = 0;

	//입력 받은 3 x 3 퍼즐을 하나의 정수로 바꾸기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			if (a == 0)
				a = 9;
			num = num * 10 + a;
		}
	}

	map<int, int> d; //map 형식으로 공간 줄이기. 배열로 하면 메모리 초과됨.

	d[num] = 0; //num이라는 숫자를 만드는데에는 0초의 시간이 걸린다. 왜냐하면 num에서 시작하는 거니까

	queue<int> q;
	q.push(num);

	while (!q.empty())
	{
		int now = q.front(); q.pop();
		
		string now_str = to_string(now);
		int blank_idx = now_str.find('9'); // 빈칸의 인덱스 를 찾아라!
		int x = blank_idx / 3;
		int y = blank_idx % 3;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) //빈칸의 인접한 숫자들과 자리를 바꿀 수 있다.
			{
				string next_str = now_str;
				swap(next_str[x * 3 + y], next_str[nx * 3 + ny]); //swap 하고,
				int next = stoi(next_str); //그 결과를 다시 정수화 한다!

				//map에서, next 라는 key를 가지는 d의 value가 0이라면,
				//(value는 초기화 시에 0으로 초기화 되므로, value가 0이라는 의미는 한번도 갱신된 적 없다는 의미 -> visited[i] == false와 같은 맥락의 의미!)  
				if (d.count(next) == 0) //next_now 문자열을 한번도 만든 적이 없다면,
				{
					d[next] = d[now] + 1; //최소 횟수 + 1 해준다.
					q.push(next);
				}
			}
		}
	}

	//key : 123456789에 해당하는 수가 답이다.
	if (d.count(123456789) == 0)  // 한번도 갱신 된 적 없다면, 정리된 상태를 더 이상 만들 수 없다는 의미이므로 -1 출력
		cout << -1 << '\n';
	else
		cout << d[123456789] << '\n';

	return 0;
}
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

int prime[10001];
int visited[10001];
int d[10001];

int changeDigit(int x, int i, int j)// 숫자 x의 i번째 인덱스를 j로 바꾼 수가 소수인지를 판단하는 함수
{
	if (i == 0 && j == 0) //0번째 인덱스를 0으로 바꾸면 세자리수가 되니까, 이 경우는 안돼!!
		return -100;

	string now = to_string(x);
	now[i] = j + '0'; //ascii값
	int a = stoi(now);
	if (prime[a]) //바꾼 수가 소수면 그 수를 반환
		return a;
	else
		return -100;
}

int main()
{
	F_I;

	//백준 1963번 소수 경로 : n에서 m으로 최종 도착을 하는데, 한 자리씩 바꾸면서 , 최소 횟수(최단 경로)를 구하는 문제이므로, bfs로 가능!
	// 언뜻 보면 길찾기 문제가 아니라서 bfs로 풀 수 없다고 생각 할 수도 있는데, bfs로 풀 수 있는 문제의 조건을 잘 생각하면 bfs로 풀 수 있다!


	//2부터 10000까지의 수 중 소수를 구하는 방법(에라토스테네스의 체)
	for (int i = 2; i <= 10000; i++)
	{
		for (int j = i * i; j <= 10000; j += i)
		{
			if (prime[j] == false)
				prime[j] = true;
		}

	}
	for (int i = 2; i <= 10000; i++)
	{
		prime[i] = !prime[i]; //소수인것만 1로 표시!
	}



	int tc;
	cin >> tc;
	while (tc--)
	{
		int s, e;
		cin >> s >> e;
		memset(visited, 0, sizeof(visited));
		memset(d, 0, sizeof(d));

		queue<int> q;
		q.push(s);

		d[s] = 0;
		visited[s] = 1;

		while (!q.empty())
		{
			int x = q.front();

			q.pop();
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j <= 9; j++)
				{
					int nextNumber = changeDigit(x, i, j);
					if (nextNumber != -100 && visited[nextNumber] == 0) //숫자 x의 i번째 인덱스를 j로 바꾼 결과물 (nextNumber)도 소수이며, 아직 방문하지 않은 수일때! (최종 통과)
					{
						d[nextNumber] = d[x] + 1;
						visited[nextNumber] = 1;
						q.push(nextNumber);
					}
				}
			}
		}
		cout << d[e] << '\n';
	}

	return 0;
}
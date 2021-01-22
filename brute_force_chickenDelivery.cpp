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


int main()
{
	F_I;

	/*
	[백준] 15686번 : 치킨 배달 (브루트 포스)

	- 각각의 치킨 집에 대해서 bfs 와 같은 기법 사용할 필요 없다. 
	- 그저 제외시키지 않을 치킨집을 고르고, 그 치킨집들과 집들 사이의 거리를 구하면 된다.
	- 치킨 집은 최대 13개 이므로, 시간복잡도는 최대 O(2^13)이다.  
	*/

	int n, m;
	cin >> n >> m;
	vector< vector<int> > a(n, vector<int>(n));
	vector<pi> house; //집 정보
	vector<pi> chicken; //치킨집 정보

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1) //집 정보 
				house.emplace_back(i, j);
			if (a[i][j] == 2) //치킨 집 정보
				chicken.emplace_back(i, j);
		}
	}

	vector<int> select(chicken.size(), 0);
	
	/*
	치킨 집 들 중에서 최대 m 개 까지 폐업 시키지 않을 경우를 만들기 위하여 select 함수 구현.
	e.g.) 치킨집이 4개고, m이 2라면, 폐업을 0개/1개/2개 시키는 경우가 가능하고, 
	1을 m개 만큼 넣어두고 select 함수에 대해서 조합을 돌리면 된다.
	
	select[0]=select[1]= 1,	select[2]=select[3]= 0인 상태이다.
	이 경우는 0,1번째 치킨집은 운영/ 2,3번쨰 치킨집은 폐업했다는 의미이다.

	그 다음 permutation은 1010 이다. (1100 다음의 prev_permutation의 값)
	1010 > 0,2번째 치킨집 운영/ 1,3번째 치킨집 폐업

	... 반복!!

	*/
	for (int i = 0; i < m; i++) 
		select[i] = 1;

	int ans = 1e9;

	do
	{
		int sum = 0; 
		for (int i = 0; i < house.size(); i++)
		{
			vector<int> dist; //집에서부터 치킨집들까지의 모든 거리 정보 저장하기

			for (int j = 0; j < select.size(); j++)
			{
				if (select[j] == 0) continue; //폐업 한 치킨집은 거리 계산에서 제외!

				int x = chicken[j].first - house[i].first;
				int y = chicken[j].second - house[i].second;
				dist.push_back(abs(x) + abs(y));
			}
			sort(dist.begin(), dist.end()); //dist의 최소값 
			sum += dist[0];
		}
		
		if (ans > sum)
			ans = sum;

	} while (prev_permutation(select.begin(), select.end()));

	cout << ans << '\n';

	return 0;
}
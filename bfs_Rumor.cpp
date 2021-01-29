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
	//[백준] 19538번 : 루머 (bfs)
	//일반적인 bfs 의 틀에서, 연결된 사람들의 절반 이상이 루머를 믿고 난 다음에서야 비로소 본인도 루머를 믿는다는 처리만 추가적으로 해주면 되는 bfs 문제이다.

	int n;
	cin >> n;
	vector< vector<int> > v(n+1);
	for (int i = 1; i <= n; i++)
	{
		while (true)
		{
			int num;
			cin >> num;
			if (num == 0)
				break;
			v[i].push_back(num);
			v[num].push_back(i);
		}
	}

	int m;
	cin >> m;
	vector<int> r(m); //초기 루머 유포자
	vector<bool> visited(n + 1, false); // visited[i] = true : i번째 사람이 rumor 를 믿고 있다.
	vector<int> rumor(n + 1, 0); //절반 이상의 사람이 루머를 믿는다 >> 이 처리를 할 때 필요한 벡터 
	vector<int> d(n+1,-1); //처음 루머를 믿는 시간을 담고 있다.

	queue<int> q;

	for (int i = 0; i < m; i++)
	{
		cin >> r[i];

		//최초 유포자들에 대한 처리
		q.push(r[i]);
		visited[r[i]] = true; 
		d[r[i]] = 0; //0초에 바로 믿는다.
	}

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto k : v[x])
		{
			if (visited[k] == false)
			{
				rumor[k] += 1; //주변인들의 수 1 증가

				if (rumor[k] >= (v[k].size() + 1) / 2) //절반 이상이 루머를 믿으면
				{
					//본인도 루머를 믿는다.
					visited[k] = true;
					d[k] = d[x] + 1;
					q.push(k);
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		cout << d[i] << ' ';
	cout << '\n';
	
	return 0;
}
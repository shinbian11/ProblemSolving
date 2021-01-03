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


int cmp(tuple<int,int,bool>& a, tuple<int, int, bool>& b)
{
	return get<0>(a) > get<0>(b);
}

int main()
{
	F_I;

	/*
	- 백준 2109번 : 순회 강연 (c++, 그리디 알고리즘). 
	현재 시간의 범위를 10000부터 1까지 잡고, 현재 시간보다 큰 시간들은 모두 선택될 수 있는 후보자이다.
	왜냐하면, d일 안에만 하면 된다는 의미는, 딱 그 day가 되었을 때 하는 의미도 있지만, 그 day가 되기 전에 해도 된다는 의미이다.

	c.f)

	n = 3

	p  d
	1  1

	10 2

	10 2 

	> 이런 경우에는, 1+10 해서 11원이 아니라, 10+10 = 20원이 답이다. 
	굳이 1일에 1원짜리 강의를 해서 하루를 소비하는 것 보다는(이렇게 되면 10원 짜리 강의는 1개밖에 못함)
	2일 동안 10원 짜리 강의를 두개 하는게 훨씬 낫다. 
	(강의 1개당 1일이 소요되는 건 마찬가지이다.)
	
	*/

	int n;
	cin >> n;
	vector< tuple<int,int,bool> > v; //p원, d일, 방문처리

	for (int i = 0; i < n; i++)
	{
		int p, d;
		cin >> p >> d;
		v.push_back(make_tuple(d, p, false));
	}

	sort(v.begin(), v.end(), cmp); //d일을 기준으로 내림차순(큰 값부터) 정렬을 함.

	int ans = 0;
	
	//정렬된 부분에서, 현재시간보다 입력된 시간이 더 크면, 현재 더할 수 있는 후보들이 되므로, 그 후보들 중에서 가장 돈을 많이 주는 강의를 택하면 된다.
	for (int i = 10000; i >= 1; i--)
	{
		int m = -1;
		int m_idx = -1;
		for (int j = 0; j < n; j++)
		{
			if (i <= get<0>(v[j]) && get<2>(v[j]) == false) //현재시간(i)보다 입력된 시간(get<0>(v[j]))가 더 크고, 이미 선택한 강의가 아니라면,
			{
				if (m < get<1>(v[j])) //그것들은 모두 후보가 되고, 그 후보들 중에서 가장 돈을 많이 주는 강의(get<1>(v[j]) 중에서의 최댓값)를 누적한 것이 답이다.
				{
					m = get<1>(v[j]);
					m_idx = j;
				}
			}
		}
		if (m != -1 && m_idx != -1)
		{
			ans += m;
			get<2>(v[m_idx]) = true; //선택한 강의는 방문했다고 처리를 해야, 나중에 또 이중선택되는 일이 없다!
		}

	}

	cout << ans << '\n'; //누적 값 출력

	return 0;
}

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

bool visited[1000005];

int main()
{
	F_I;

	//백준 9935번 : 문자열 폭발

	//step 1. 문자열을 a, 폭발 문자열을 b라고 했을 때, a의 문자들을 하나씩 살펴가며, 이 문자가 폭발 문자열에 속하는지 아닌지를 판단한다. (메인 idea)
	//step 2. 만약 a[i]의 문자가 폭발 문자열의 첫번째 문자와 같다면, 그 문자는 폭발 문자열이 시작점이 될 '가능성' 이 존재하는 문자이므로,
	//			stack에 넣어놓는다. ( i와 0(폭발 문자열의 첫번째 문자)을). 
	//step 3. 만약 a[i]가 폭발 문자열의 첫번째 문자와 같지 않다면,
	//			그 a[i] 문자가 폭발 문자열의 첫번째 문자는 아니지만, 폭발 문자열에 속해있는 다음 문자일수도 있다. 
	//			그러므로 기존에 있었던 스택의 가장 위쪽 문자를 꺼내서, 그 문자의 다음 문자와 a[i]가 같은지 비교한다.
	//			만약 같다면, 폭발 문자열의 연속되는 정보이므로 그 경우도 stack에 이어서 넣는다 (i와 stack의 맨 위에서 꺼낸 문자열의 위치+1 을)
	//step 4 . 그렇게 하다가, 폭발 문자열의 맨 마지막에 위치한 문자가 stack에 넣어지는 순간, 그 문자열에 해당하는 만큼은 터져야 하므로,
	//			그만큼 stack에서 pop해서 꺼내고, visited[거기에 해당되는 문자열 a의 index]는 true로 바뀐다.
	//step 5 . 나중에, visited 배열에서 false인 부분만 출력하면 된다.


	/*
	e.g.) => 직접 그림을 그려가면서 보면 이해가 쉽다!

			a = abaabcbcd  
			
			b = abc 일때

		 => a[0]==b[0]이므로, (0,0)을 스택에 push => a[1]!=b[0] 이고, 스택에 있는 (0,0)을 꺼내서 a[1] == b[0 +1]이므로, (1,0+1)을 스택에 push
		 => a[2]==b[0]이므로, (2,0)을 스택에 push => a[3]==b[0]이므로, (3,0)을 스택에 push => 
		 => a[4]!=b[0] 이고, 스택에 있는 (3,0)을 꺼내서 a[4] == b[0 +1]이므로, (4,0 +1)을 스택에 push
		 => a[5]!=b[0] 이고, 스택에 있는 (4, 0+1)을 꺼내서 a[5] == b[0+1 +1]이므로, (5, 0+1 +1)을 스택에 push
		 => 이때 0+1 +1 == m-1이므로, 스택에 들어있는 최근 정보 m개를 꺼낸다.  
		 ...
		 ( 이 과정 계속 반복 )
		 ...
	*/

	string a, b;
	cin >> a >> b;
	int n = a.length();
	int m = b.length();

	if (m == 1) //폭발 문자열의 길이가 1인 경우 -> 문자열에서 그 폭발 문자열에 해당하는 문자만 빼고 출력 하면 됨!
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] == b[0])
				visited[i] = true;
		}
	}
	else
	{
		stack<pi> v;
		for (int i = 0; i < n; i++)
		{
			if (b[0] == a[i]) //step 2
			{
				v.push(make_pair(i, 0));
			}
			else //step 3
			{
				if (!v.empty())
				{
					int x = v.top().second;
					if (a[i] == b[x + 1])
					{
						v.push(make_pair(i, x + 1));
						if (x + 1 == m - 1)//step 4
						{
							for (int i = 0; i < m; i++)
							{
								visited[v.top().first] = true;
								v.pop();
							}
						}
					}
					else
					{
						while (!v.empty())
							v.pop();
					}
				}
				
			}
		}
	}
	bool flag = false;

	for (int i = 0; i < n; i++) //step 5. 
	{
		if (!visited[i])
		{
			cout << a[i];
			flag = true;
		}
	}

	/*flag = false라는 것은, 모든 i에 대해서 visited[i]가 항상 true였다는 의미이므로, 입력받은 문자열 a 은 모두 폭발했다는 의미이므로, 
	남아있는 문자가 없는 경우이다.*/
	if (!flag)
		cout << "FRULA" << '\n';

	return 0;

}
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


int check[101][101];

int main()
{
	F_I;

	int n, m;
	cin >> n >> m;
	vector<string> s(n);

	for (int i = 0; i < n; i++)
		cin >> s[i];

	vector< tuple<int, int, int> > ans;
	/*
	
	* 16924번 : 십자가 찾기 (브루트 포스)

	각 점이 모두 십자가의 중심이라고 생각하고, 각 점에서 십자가를 만들 수 있을 때까지 최대로 만들어보고, 길이 1 이상의 십자가를 만들 수 있으면,
	그 정보를 ans 벡터에 담는다.
	같은 중심에서 길이가 3인 십자가를 만들 수 있다는 의미는, 길이가 1,2인 십자가는 자동으로 만들 수 있다는 의미이다. 예를 들어,

	....*...
	...**...
	..*****.
	...**...
	....*...
	........

	-> 이런 경우에는
	3 4 1
	3 5 2
	3 5 1 도 답이 될 수 있지만,

	3 4 1
	3 5 2 도 답이 될 수 있다.

	즉, 가능한 답 중 아무거나 출력 해도 된다는 언급이 있으므로, 십자가를 만들 수 있는 경우엔 그 십자가의 길이가 최대가 될 때까지 계속 만들어 가면 된다.

	만약 가능한 십자가를 모두 출력해야 한다면, //***2번 이라고 표시된 부분들을 수정해주면 된다.
	*/

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//***2번 (밑 줄 주석)
			//int length = 0;
			if (s[i][j] == '*')
			{
				int length = 0;
				for (int k = 1;; k++)
				{
					if (i - k >= 0 && i + k < n && j - k >= 0 && j + k < m) // 범위 내에 있어야 가능.
					{
						if (s[i - k][j] == '*' && s[i + k][j] == '*' && s[i][j - k] == '*' && s[i][j + k] == '*')
						{

							//***2번 (밑 줄 주석)
							//length = k; //십자가의 길이 갱신

							//***2번 (밑 부분 추가)

							length += 1;
							ans.push_back(make_tuple(i + 1, j + 1, length)); //문제에서 제일 위쪽 행을 1행, 제일 왼쪽 열을 1열 이라고 했으므로

							check[i][j] = true;
							check[i - k][j] = true;
							check[i + k][j] = true;
							check[i][j - k] = true;
							check[i][j + k] = true;

							//***2번 (여기까지)
						}
						else
							break;
					}
					else
						break;
				}
				/*  //***2번 (밑 부분 주석)

				if (length > 0)
				{
					ans.push_back(make_tuple(i + 1, j + 1, length));

					for (int k = 0; k <= length; k++) //만든 십자가 부분은 모두 true처리!
					{
						check[i - k][j] = true;
						check[i + k][j] = true;
						check[i][j - k] = true;
						check[i][j + k] = true;
					}
				}
				*/

			}

		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '*' && check[i][j] == false) //아직까지도 *자리에 false가 있다는건, 그 자리에 해당하는 *은 십자가의 일원으로
				//포함될 수 없다는 의미이므로, 그런 경우는 만들 수 없으므로 -1 처리한다.
			{
				cout << -1 << '\n';
				return 0;
			}
		}
	}

	//출력부분

	cout << ans.size() << '\n';

	for (int i = 0; i < ans.size(); i++)
	{
		cout << get<0>(ans[i]) << ' ' << get<1>(ans[i]) << ' ' << get<2>(ans[i]) << '\n';
	}

	return 0;
}
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
struct Info
{
	int num;
	int op; // 0: 연산자, 1: + , 2: - ,3: *
};
int main()
{
	F_I;

	//[백준] 16637번 : 괄호 추가하기 (브루트 포스 + 계산)

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<Info> v(n);
	//연산자와 피연산자의 정보들을 각각 저장
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) //연산자
		{
			v[i].num = s[i] - '0';
			v[i].op = 0;
		}
		else //피연산자
		{
			v[i].num = 0;
			if (s[i] == '+')
				v[i].op = 1;
			else if (s[i] == '-')
				v[i].op = 2;
			else if (s[i] == '*')
				v[i].op = 3;
		}

	}

	int mx = -2147483648; //최종 출력 값

	int m = (n - 1) / 2; //연산자의 개수

	for (int i = 0; i < (1 << m); i++)
	{
		//step1) 괄호 치는 경우의 수들에 대해 각각 따짐 (브루트 포스)
		bool flag = false;
		for (int j = 0; j < m - 1; j++)
		{
			//j번째 연산자와 j+1 번째 연산자가 연속적으로 괄호가 쳐지면 안된다.
			//연산자가 연속적을 괄호가 쳐진다 > e.g.) (1+(3*4)) , (1+3+2) >> 이런거 안된다는 의미! 문제 조건이 부합하지 않음.
			if ((i & (1 << j)) > 0 && (i & (1 << (j + 1))) > 0) 
			{
				flag = true;
			}
		}

		if (flag)
		{
			continue;
		}

		vector<Info> b(n);
		b = v;

		//step2) 괄호를 쳤으면, 계산하기 쉽게 식을 변형함
		for (int j = 0; j < m; j++) 
		{
			if ((i & (1 << j)) > 0) //j번째 원소
			{
				int idx = 2 * j + 1;
				if (b[idx].op == 1) //e.g.) 1+5 를 6+0 으로 바꿈 -> 그래야 연속되는 계산이 잘못된 값을 도출하지 않음.
				{
					b[idx - 1].num += b[idx + 1].num;
					b[idx + 1].num = 0;
				}
				else if (b[idx].op == 2) //e.g.) 1-5 를 -4+0 으로 바꿈 -> 그래야 연속되는 계산이 잘못된 값을 도출하지 않음.
				{
					b[idx - 1].num -= b[idx + 1].num;
					b[idx].op = 1;
					b[idx + 1].num = 0;
				}
				else if (b[idx].op == 3) // e.g.)  3*4 를 12*1 으로 바꿈 -> 그래야 연속되는 계산이 잘못된 값을 도출하지 않음.
				{
					b[idx - 1].num *= b[idx + 1].num;
					b[idx].op = 1;
					b[idx + 1].num = 0;
				}
			}
		}

		//step3 : 변형한 식을 계산해서 최대값 골라내기
		int ans = b[0].num;
		for (int j = 0; j < m; j++)
		{
			int idx = 2 * j + 1;
			if (b[idx].op == 1)
				ans += b[idx + 1].num;
			else if (b[idx].op == 2)
				ans -= b[idx + 1].num;
			else if (b[idx].op == 3)
				ans *= b[idx + 1].num;
		}

		if (mx < ans)
			mx = ans;
	}

	cout << mx << '\n';

	return 0;
}
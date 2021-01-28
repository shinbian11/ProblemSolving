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

typedef struct info
{
	int num;
	int op; 
	//op : 0 (수, 피연산자), op : 1 (+, 연산자), op : 2 (-, 연산자), op : 3 (*, 연산자)
	//op: -1 (이 부분은 계산하지 말고 건너뛸 것!)

} Info;

int main()
{
	//[백준] 16638번 : 괄호 추가하기 2

	//기존의 16637번 : 괄호 추가하기 문제와 매우 흡사하지만, 괄호를 친 부분은 먼저 계산하되, 그 부분의 연산자를 -1 처리함으로써, 
	//나중에 최종 계산 할때는 스킵하고, * 부분을 만날때마다 바로바로 계산해서 ans 배열에 넣는다는 차이점이 존재한다.

	int n;
	cin >> n;
	vector<Info> arr(n);

	string st;
	cin >> st;

	//Info 배열에 입력받은 내용 저장!
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			arr[i].num = st[i]-'0';
			arr[i].op = 0;
		}
		else
		{
			arr[i].num = 0;
			if (st[i] == '+')
				arr[i].op = 1;
			else if (st[i] == '-')
				arr[i].op = 2;
			else if (st[i] == '*')
				arr[i].op = 3;
		}
	}

	int real = -1;
	int m = (n - 1) / 2;

	for (int i = 0; i < (1 << m); i++) //괄호 칠 부분에 대한 모든 경우의 수
	{
		/*
		e.g.) i= 0101 일 때, (오른쪽에서 0번째 연산자와 2번째 연산자가 1이라는 의미는, 0번째 연산자가 가지고 있는 부분과 2번째 연산자가 가지고 있는 부분을
		괄호 치겠다는 의미이다.

		i = 0101 이고, 입력받은 수식이 2 + 3 * 4 - 5 + 2 라면, (2 + 3) * (4 - 5) + 2 로 하겠다는 의미이다!

		*/
		bool flag = false;
		for (int j = 0; j < m - 1; j++)
		{
			//j번째 연산자와 j+1 번째 연산자가 연속적으로 괄호가 쳐지면 안된다.
			//연산자가 연속적으로 괄호가 쳐진다 > e.g.) (1+(3*4)) , (1+3+2) >> 이런거 안된다는 의미! 문제 조건이 부합하지 않음.

			//제시된 i에 대해서, 한번이라도 연속이 되었다면 flag는 true로 바뀌고, 그 이후에 연속되는 것이 없다 하더라도, 이미 한번 연속이 되었다는 기록이 남아있으므로, 
			//if문에서 flag를 true로 바꾸고 break문을 적음으로써 바로 그 부분을 탈출 하는 코드는 필요가 없다.

			/*
			e.g.)
			i= 0011  일 때,  

			j=0 일때는, (1<<0) 과 (1<<1) 이 i와 & 연산을 했을 때 둘다 0 이 아닌 값이 나오므로, if문 안으로 들어가므로, flag가 true로 바뀌고,
			j=1 일때는 연속이 되지 않으므로, if문 안에 들어가지도 못하고,
			j=2 일때도 마찬가지이다. 

			- 즉, 한번이라도 i가 연속되는 부분이 존재한다면, flag는 true로 바뀌고, 그 이후에 연속되는 부분이 없다 하더라도 flag의 값이 다시 false로 바뀌지는 않는다.
			왜냐하면 연속되는 부분이 없는 경우에는 밑의 if문에 애초에 들어가지를 못하니까!
			*/
			if (  ((i & (1 << j)) != 0) && ((i & (1 << (j + 1))) != 0)) //연속이라면,
			{
				flag = true;
			}
		}

		if (flag == true)
			continue;

		vector<Info> copy(arr);

		for (int j = 0; j < m; j++)
		{
			if ((i & (1 << j)) != 0)
			{
				int k = 2 * j + 1;
				if (copy[k].op == 1) // +
				{
					copy[k - 1].num += copy[k + 1].num;
					copy[k].op = -1; // op: -1면 계산하지 말고 건너뛰라는 의미.
					copy[k + 1].num = 0;
				}
				else if (copy[k].op == 2) // -
				{
					copy[k - 1].num -= copy[k + 1].num;
					copy[k].op = -1;
					copy[k + 1].num = 0;
				}
				else if (copy[k].op == 3) // *
				{
					copy[k - 1].num *= copy[k + 1].num;
					copy[k].op = -1;
					copy[k + 1].num = 0;
				}
			}
		}

		vector<Info> ans;
	
		for (int j = 0; j < n; j++)
		{
			/*
			e.g.)

			copy 배열에서의 -1을 ?라 한다면,

			- copy  : 3 + 4 ? 0 * 2 + 1 일때,
			- ans 배열의 step!

			 step1) copy의 idx 0을 탐색 중일때 > 3이니까 투입
			 현재 ans 상황 : 3 

			 step2) copy의 idx 1,2를 순서대로 탐색 중일때 > 각각 +, 4 니까 각각 순서대로 투입
			 현재 ans 상황 : 3 + 4 

			 step3) copy의 idx 3을 탐색 중일때 > ? 니까 idx+=1 하기, idx가 4인 상황에서 for 반복문에 의해 자연스럽게 idx가 또 1 증가! idx는 5가 됨!
			 현재 ans 상황 : 3 + 4 

			 step4) copy의 idx 5을 탐색 중일때 > * 니까 ans 의 가장 최근 원소인 4를 꺼내기, 그것과 2를 곱해서 4가 있던 자리에 넣고, idx+=1 하기,
			 idx가 6인 상황에서 for 반복문에 의해 자연스럽게 idx가 또 1 증가! idx는 7이 됨!
			 현재 ans 상황 : 3 + 8 

			 step5) copy의 idx 7,8을 순서대로 탐색 중일때 > 각각 +, 1 이니까 각각 순서대로 투입
			 현재 ans 상황 : 3 + 8 + 1

			*/
			if (copy[j].op == 0) //숫자면은 
			{
				ans.push_back(copy[j]);
			}
			if (copy[j].op == -1) //-1이면 ans 배열에 넣지 말고 그냥 skip
			{
				j += 1;
			}
			if (copy[j].op == 1) // + 면은
			{
				ans.push_back(copy[j]);
			}
			if (copy[j].op == 2) // - 면은
			{
				ans.push_back(copy[j]);
			}
			if (copy[j].op == 3) // * 면은
			{
				int aa = ans.back().num;
				aa *= copy[j + 1].num;
				ans.pop_back();
				ans.push_back({ aa, 0 });
				j += 1;
			}
		}

		int res = ans[0].num;
	
		int m2 = (ans.size() - 1) / 2;

		for (int j = 0; j < m2; j++)
		{
			int k = 2 * j + 1;
			if (ans[k].op == 1)
				res += ans[k + 1].num;
			if (ans[k].op == 2)
				res -= ans[k + 1].num;
		}

		if (real == -1 || real < res)
		{
			real = res;
		}
	}

	cout << real << '\n';

	return 0;
}
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

//	[백준] 1406번 : 에디터 (자료구조 - 스택)
//	커서를 기준으로 왼쪽 스택과 오른쪽 스택으로 따로따로 관리한다.

stack<char> LS; //왼쪽 스택
stack<char> RS; //오른쪽 스택

int main()
{
	F_I;
	
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		LS.push(s[i]); //맨 처음 입력 받은 문자열은 왼쪽 스택(LS)에 넣는다.
	int n;
	char c, ob;
	cin >> n;
	while (n--)
	{
		cin >> c;
		if (c == 'P') //왼쪽 스택(LS)에 넣는다.
		{
			cin >> ob;
			LS.push(ob);
		}
		else if (c == 'L') //커서를 왼쪽으로 한칸 옮김 -> LS에 있는 맨 위의 원소를 RS로 옮긴다.
		{
			if (!LS.empty())
			{
				c = LS.top();
				LS.pop();
				RS.push(c);
			}
		}
		else if (c == 'D') //커서를 오른쪽으로 한칸 옮김 -> RS에 있는 맨 위의 원소를 LS로 옮긴다.
		{
			if (!RS.empty())
			{
				c = RS.top();
				RS.pop();
				LS.push(c);
			}
		}
		else if (c == 'B') //커서 왼쪽에 있는 문자를 삭제함 -> LS에 있는 맨 위의 원소를 그냥 삭제한다 (pop)
		{
			if (!LS.empty())
			{
				LS.pop();
			}
		}
	}

	vector<char> LV;
	while (!LS.empty()) //LS는 스택에 들어있는 원소 순서를 거꾸로 출력
	{
		LV.push_back(LS.top());
		LS.pop();
	}
	reverse(LV.begin(), LV.end());
	for (int i = 0; i < LV.size(); i++)
		cout << LV[i];
	while (!RS.empty()) //RS는 스택에 들어있는 원소 순서 그대로 출력
	{
		cout << RS.top();
		RS.pop();
	}

	return 0;
}
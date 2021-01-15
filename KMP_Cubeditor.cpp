#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

vector<int> getFailFunction(string& a) //문자열 a에 대한 fail함수 구하는 방법
{
	int num = a.length();
	vector<int> failfunc(num);
	int j = 0;
	failfunc[0] = 0;
	for (int i = 1; i < num; i++)
	{
		while (j > 0 && a[i] != a[j])
			j = failfunc[j - 1];
		if (a[i] == a[j])
		{
			failfunc[i] = j + 1;
			j += 1;
		}
		else
			failfunc[i] = 0;
	}
	
	return failfunc;
}

int main()
{
	F_I;
	/*
	
	<KMP 알고리즘>

	- KMP 알고리즘은, S가 전체 문자열, P가 찾고자 하는 패턴일 때, S 안에 P가 포함되어 있는지를 판단하는 알고리즘이다.
	- KMP 의 시간복잡도 :  O(ㅣSㅣ + ㅣPㅣ)

	---------------------------------------------------------------
	백준 1701번 : Cubeditor (KMP)

	- 2번 이상 나오는 부분문자열 들 중에서의 최대 길이를 구하는 문제. 
	- fail 함수의 최대값을 구하면 되는 단순한 문제이다. 
	왜냐하면 fail 함수의 개념 자체가, 최대길이 값을 저장하는 함수이고, 또한 2번 이상 나오지 않는다면 fail 함수에 특정 값이 저장되지 못하기 때문이다.
	
	e.g.)
	pattern   a b c d a b a b c a a
	fail      0 0 0 0 1 2 1 2 3 1 1
	
	- 이때, fail 함수의 최대값인 3은 그 자리에서 일치되는 접두사/접미사의 최대 길이 값이고(3), 0 이 아닌 값이므로, 이미 한번 나온 문자열이라는 뜻이다.

	- 다시 말해, 입력받은 문자열의 fail 함수를 구해, 그 fail 함수 값 중에 최대값을 구하면 된다!


	
	- 그런데, 이 fail 함수는 접두사/접미사 일때에만 해당되는 함수이다.
	- 이 문제는 반복되는 문자열이 꼭 접두사/접미사 위치에 있지 않아도 된다.
	
	e.g.)
	pattern   d a b c d a b a b c a a
	fail      0 0 0 0 1 2 0 0 0 0 0 0 
	
	- 이렇게 나오는데, 그렇다고 답이 2는 아니다! 여전히 답은 3이다. (abc)
	- 아 abc는 접미사/접두사가 아니라, 문자열 중간에 끼여있다.

	- 즉, 나올 수 있는 모든 문자열에 대해 fail 함수를 각각 구하고, 그 fail 함수에 있는 모든 값들 중 최대값을 구하면 된다.

	d일때
	d a b일때
	d a b c일때
	d a b c d일때
	d a b c d a일때
	d a b c d a b일때
	d a b c d a b a일때
	d a b c d a b a b일때
	d a b c d a b a b c일때 
	d a b c d a b a b c a일때
	d a b c d a b a b c a a일때
	
	- 각각 fail 함수를 구해야 한다.
	*/

	int ans = -1;
	string s;
	cin >> s;
	int n = s.length();

	//나올 수 있는 모든 문자열에 대해 fail 함수를 각각 구해서 fail 함수값의 최대값을 구하는 과정
	for (int i = 0; i < n; i++)
	{
		string a = s.substr(i, n - i); //i번째 idx부터 n-i개만 추출해서 fail 함수 구하기
		vector<int> failfunc = getFailFunction(a);
		for (int j = 0; j < n - i; j++)
		{
			if (ans < failfunc[j])
				ans = failfunc[j];
		}
	}

	cout << ans << '\n'; //모든 fail 함수들 중에서의 최댓값 출력

	return 0;
}
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

void change(vector<int>& a, int idx)
{
	for (int i = idx - 1; i <= idx + 1; i++)
	{
		if (i >= 0 && i < a.size())
		{
			a[i] = 1 - a[i]; //a[i] = !a[i];
		}
	}
	return;
}

/* 
vector<int> &a 라고 하면 안됨. &를 사용하면 주소에 의한 반환이므로, a의 원본 값 자체를 변경하므로, 
p1에서 했던 결과값이 p2의 결과값이 그대로 영향을 준다. 근데 p1과 p2를 각각 구할때의 a와 b는 입력받았을 때의 값을 그대로 유지해야 하므로
check함수의 첫번째 매개변수를 &를 사용하면 안된다.
*/

pair<bool, int> check(vector<int> a, vector<int>& b) 
{
	int ans = 0;
	int size = a.size();
	for (int i = 0; i < size-1; i++)
	{
		if (a[i] != b[i])
		{
			change(a, i+1);
			ans += 1;
		}
	}
	if (a[size-1] == b[size-1])
		return make_pair(true, ans);
	else
		return make_pair(false, ans);
}

int main()
{
	//F_I;

	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; i++)
		scanf("%1d",&a[i]);

	for (int i = 0; i < n; i++)
		scanf("%1d", &b[i]);
	
	/*
	* 백준 2138번 : 전구와 스위치 (그리디 알고리즘 + 함수 매개변수의 값/주소에 의한 변경)
	
	각각의 원소들 중에서 이 원소의 값을 변경시킬 수 있는 능력을 가진 스위치의 개수가 1개일 때의 상황이 필요하다.
	즉 a 배열의 0번째 스위치를 눌렀을 때와 누르지 않았을 때로 나누어서 생각한다.
	0번째 스위치를 누르거나 누르지 않았을때, 0번째 원소의 값을 변경시킬 수 있는 능력을 가진 스위치의 개수는 1개(1번재 인덱스의 스위치)가 되니까! 
	(그전에는 2개였다. 0, 1번째 인덱스의 스위치)
	*/

	pair<bool, int> a1 = check(a, b); //a 배열의 0번째 스위치를 안 눌렀을 때

	change(a, 0); //a배열의 0 번째 인덱스의 스위치 누름
	pair<bool, int> a2 = check(a, b); //a 배열의 0번째 스위치를 눌렀을 때

	if (a2.first)
		a2.second += 1; //change(a,0)을 통해서 이미 스위치 한번 눌렀으니까. 나온 횟수에 + 1 해주어야 한다.

	
	if (!a1.first && !a2.first) //0번째 스위치를 안 눌렀을 때도 false이고, 눌렀을 때도 false일때
		cout << -1 << '\n'; //어떻게 해도 a를 b로 바꿀 수 없으므로 -1 출력
	else if (a1.first && !a2.first) //0번째 스위치를 안 눌렀을 때는 true이고, 눌렀을 때는 false일때
		cout << a1.second << '\n'; //0번째 스위치를 안 눌렀을 때의 값을 출력
	else if (!a1.first && a2.first) //0번째 스위치를 안 눌렀을 때는 false이고, 눌렀을 때는 true일때
		cout << a2.second << '\n'; //0번째 스위치를 눌렀을 때의 값을 출력
	else //0번째 스위치를 누르든 안 누르든 둘다 true일때
		cout << Min(a1.second, a2.second) << '\n'; //둘 중의 최소 횟수(최소값)을 출력
	
	return 0;
}
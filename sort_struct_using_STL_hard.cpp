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
	string name;
	int kor, eng, math;

} Info;


bool cmp(Info& a, Info& b)
{
	//정렬 우선순위
	/*
	-국어 점수가 감소하는 순서로
	-국어 점수가 같으면 영어 점수가 증가하는 순서로
	-국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
	-모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
	*/

	if (a.kor > b.kor) //국어
		return true;
	else if (a.kor < b.kor)
		return false;
	else
	{
		if (a.eng < b.eng)//영어
			return true;
		else if (a.eng > b.eng)
			return false;
		else
		{
			if (a.math > b.math)//수학
				return true;
			else if (a.math < b.math)
				return false;
			else
			{
				if (a.name < b.name)//이름
					return true;
				else
					return false;
			}
		}
	}
}

int main()
{
	F_I;

	//백준 10825번 국영수 : 정렬 해야하는 field 가 여러개이고, 각각의 field 에 대해 정렬 기준이 모두 다를때! cmp 사용자 정의 함수 이용!
	int n;
	cin >> n;
	vector<Info> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << v[i].name << '\n';

	return 0;
}
#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

bool IsInside(int x, int y)
{
	if (x >= -5 && x <= 5 && y >= -5 && y <= 5) return true;
	else return false;
}

int solution(string dirs)
{
	// 길 개수 체크하는 기준. (출발점)과 (도착점)이 모두 방문한 적이 있는 경우만 체크에서 제외해야 한다. (이를 깨닫는 것이 중요!!)
	// 근데 두 점 모두 각각의 정보가 두 개씩(x,y)이므로, 두 점을 모두 체크하려면 4개의 정보를 일일히 체크해야 하는데, 이는 매우 불편하다.
	// 좀 더 편하게 비교하기 위해서, (출발점)의 (x,y)정보와 (도착점)의 (x,y)정보를 하나의 숫자로 만들어버리자. (편리성을 위해!!)
	// 여기서는 x에 100을 곱해서 y를 더한 방법을 택했다. 이렇게 하나의 해쉬값(?) 표기값(?) 을 만드는 건 본인의 자유이다.
	// set에 출발점의 값과 도착점의 값이 이미 저장되어 있는 경우가 아니라면 set에 넣어준다.
	// 마지막으로 set의 크기가 개수와 동일하므로, set의 size를 반환한다.
	// 배열을 선언해서 지나간 길을 true 로 표기하는 방법도 있지만, 굳이 배열을 선언할 필요도 없이, 이런 방법을 사용하면 된다.
	

	//시작점 정보
	int x = 0;
	int y = 0;

	int nx = x;
	int ny = y;

	set<pi> v;
	for (int i = 0; i < dirs.length(); i++)
	{
		
		if (dirs[i] == 'U')
		{
			nx = x - 1;
			ny = y;
		}
		else if (dirs[i] == 'D')
		{
			nx = x + 1;
			ny = y;
		}
		else if (dirs[i] == 'R')
		{
			nx = x;
			ny = y + 1;
		}
		else if (dirs[i] == 'L')
		{
			nx = x;
			ny = y - 1;
		}

		if (!IsInside(nx, ny)) continue; //범위 체크
		
		int a = x * 100 + y;
		int b = nx * 100 + ny;

		//이동을 시켜야 함.
		x = nx;
		y = ny;

		//set의 중복 체크
		if (v.find({ a,b }) == v.end() && v.find({ b,a }) == v.end())
			v.insert({ a,b });
	}
	
	return v.size();
}

int main()
{
	F_I;

    string dirs = "LULLLLLLU";
    cout<< solution(dirs);
	
	return 0;
}

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

int arr[1004];
int d[1004][1004];

int n, m;

/*
index번째 글자를 쓸 것이고, 그 줄에 이미 count개의 칸을 사용한 상황에서,
현재 줄에 index번째 글자를 쓸 것이라면 >> d[index+1][count+arr[index]+1] : 마지막 +1 은 띄어쓰기의 1칸을 반영한 것이다.
다음 줄에 index번째 글자를 쓸 것이라면 >> d[index+1][arr[index]+1] + (m - count + 1) * (m - count + 1)이다.
이때, (m - count + 1)는 줄의 끝에 사용하지 않고 남게 되는 칸의 수 이다. 이때의 +1도 띄어쓰기의 1칸을 반영한 것이다.
이해가 안된다면 그림을 직접 그려보기!!
*/

int go(int index, int count) //d[index][count] : index번째 글자를 쓸 것이고, 그 줄에 이미 count개의 칸을 사용했을 때!
{

	if (index >= n) //범위 체크
		return 0;

	//memoization
	int& ans = d[index][count];
	if (ans != -1)
		return ans;

	//다음 줄에 글자를 쓸 것이라면
	ans = go(index + 1, arr[index] + 1) + (m - count + 1) * (m - count + 1);

	//현재 줄에 글자를 쓸 것이라면
	if (count + arr[index] <= m) //범위 체크
	{
		int tmp = go(index + 1, count + arr[index] + 1);

		if (ans > tmp) //최소를 return
			ans = tmp;
	}

	return ans;
}

int main()
{
	//[백준] 2281번 : 데스노트 (dp,TOP down)
	F_I;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	memset(d, -1, sizeof(d)); //memoization을 위한 초기화!

	cout << go(1, arr[0] + 1); //index 1 번째 글자를 쓸 것이고, 현재 arr[0]+1 만큼의 칸을 쓴 이후의 상태일때! 

	return 0;
}
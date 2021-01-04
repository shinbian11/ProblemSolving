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


int main()
{
	F_I;

	int n;
	cin >> n;
	//12015번 : 가장 긴 증가하는 부분 수열 2 (lower_bound, upper_bound) 
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		
		auto it = lower_bound(a.begin(), a.end(), num);
		
		if (it == a.end()) { //num이 기존의 a배열에 있는 모든 원소들 보다 크거나, 아님 원소들의 최대값과 같은 크기면
			a.push_back(num); //a벡터의 끝에 추가
		}
		else {//num이 a 벡터의 최댓값 보다 작으면 -> 그 num을 날리는 게 아니다!

			/*
			* 3 1 2 >> 이렇게 입력 받앗을때, else 문이 없으면, a벡터에는 최종적으로 3만 남게 된다. 근데 a벡터에는 1과 2가 있어야 한다.
			* 그러므로 num이 a벡터의 최대값보다 작다고 해서 그 num을 날려버리면 안된다.
			* a벡터에 있는 원소들 중에서, num보다 작은 값이 있고 num보다 큰값이 있을텐데, 딱 그 경계점을 가르키고 있는 부분을 num으로 갱신 해야한다.
			* 3 1 2 에서 num=3 이면 a 벡터에는 3이 들어가 있고, 그다음 num=1 일때는 lower_bound에 의해서 it가 3을 가르키고 있는데, 그 3을 1로 갱신한다.
			* 그다음 num=2면 a에 push_back해서, 결론적으로는 1 2 가 남는다.
			* 
			* 2 4 1 5 3 6 >> 이렇게 입력받았을때는 else가 없어도 될것같이 생각이 되었으나, 3 1 2 >> 이렇게 입력받았을때 비로소 else 문이 필요하다는 것을 깨닫게 되었다.
			
			*/
			*it = num; 
		}
	}
	cout << a.size() << '\n';

	return 0;
}
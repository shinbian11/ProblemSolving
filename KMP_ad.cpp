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

int main()
{
	F_I;
	/*
	백준 1305번 : 광고 (KMP 알고리즘)
	*/

	int n;
	cin >> n;
	vector<int> fail(n);
	fail[0] = 0;
	string ad;
	cin >> ad;

	int idx, j = 0;
	/*
	idx    0 1 2 3 4 5 6 7 8 9

	ad     a b a c a b a b a c
	fail   0 0 1 0 1 2 3 2 3 4

	- fail[idx]의 의미 : 만약 fail[5]=2 면, 처음 접두사부분의 2글자, 마지막 접미사부분의 2글자가 같다는 의미.

	(중요)
	- idx가 7일때, (j는 3이고, idx는 7인 상황) > ad[7] != ad[3] 이므로 fail[7]에 0을 넣어야 하나?? 아니다.
	  비록 ad[7]과 ad[3]은 같지 않지먼, 앞부분까지는 같았으므로 이 정보를 이용 해야 한다. 
	  j를 1 감소시켜 j가 6일때를 보자. fail[6]=3 이라는 의미는, 접두사/접미사 부분 3글자씩은 일치했다는 의미이다('aba' c 'aba')
	  이때 일치하는 부분의 길이가 3이므로, 실제 일치하는 부분의 마지막 인덱스는 2일것이다. (인덱스는 0부터 시작이므로, 앞 aba에서 마지막 a는 idx가 2이다)
	  그 부분으로 돌아가서 그때의 fail함수를 보자! 즉 j에 fail[j-1]값을 주고, 그때의 fail[j]를 참고하자는 의미이다. 
	  fail[3-1] = 1이다. j에 1을 주고 , fail[1] 과 fail[7] (=fail[i])가 같은지 본다. 같으므로 fail[7] = j+1 = 1+1 = 2가 들어간다.
	*/
	for (idx = 1; idx < n; idx++)
	{
		while (j > 0 && ad[idx] != ad[j])
			j = fail[j - 1];

		if (ad[idx] == ad[j]) //i번째 문자와 j번째 문자가 같다면, fail 함수 값을 1 증가시켜, 공통된 접두사와 접미사의 길이를 +1 시킨다.
		{
			fail[idx] = j + 1;
			j += 1;
		}
		else
			fail[idx] = 0;
	}
	
	cout << n - fail[n - 1] << '\n';
	return 0;
}
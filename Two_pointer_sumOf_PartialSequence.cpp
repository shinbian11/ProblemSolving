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

	//[백준] 1208번 : 부분수열의 합 2 (중간에서 만나기 + 투 포인터)

	/*
	- 수열의 원소 개수가 최대 40개이고, 그러므로 이 수열의 부분 수열의 개수는 최대 2^40개까지도 가능하다.
	하지만 2^40은 시간초과가 발생할 정도의 큰 수이므로, 이 방법으로는 풀 수 없다
	- 수열을 두 덩어리로 쪼개어서 (반반씩) , 각각에 대해 2^20, 2^20가지의 부분 수열을 만들어서 더하는 식으로 하는 방법은 어떨까?
	이렇게 되면 2^20 + 2^20 이라서 충분히 가능하다!
	- 이것이 중간에서 만나기(meet in the middle) + 투 포인터 방법이다!!
	- 앞부분 배열이 만들 수 있는 부분 수열을 만들고, 뒷부분 배열이 만들 수 있는 부분 수열을 만들어서 각각 더하면서 탐색해보자!
	*/

	int n, s;
	cin >> n >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int m = n / 2;
	n = n - m;

	vector<int> first(1<<n); //앞부분 수열 (2^n 개)
	vector<int> second(1<<m); //뒷부분 수열 (2^m 개)

	//각각의 부분 수열 만들어주기
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
				first[i] += v[j];
		}
		
	}
	for (int i = 0; i < (1 << m); i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i & (1 << j))
				second[i] += v[j+n];
		}
	}

	//first는 오름차순, second는 내림차순으로 정렬!
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	reverse(second.begin(), second.end());

	n = (1 << n);
	m = (1 << m);
	int up= 0, down = 0;
	ll ans = 0;

	while (up < n && down < m)
	{
		if (first[up] + second[down] == s) //s 값이 first[up] + second[down]과 같으면 >> (first[up]과 같은 값의 개수 X second[down]과 같은 값의 개수)를 구한다.
		{
			ll up_cnt = 1, down_cnt = 1;
			up += 1;
			down += 1;

			while (up < n && first[up] == first[up - 1])
			{
				up_cnt += 1;
				up += 1;
			}
			while (down < m && second[down] == second[down - 1])
			{
				down_cnt += 1;
				down += 1;
			}

			ans += (up_cnt * down_cnt);
		}
		else if (first[up] + second[down] < s) //s 값이 first[up] + second[down]보다 크면 >> up을 1 증가시켜서, first에서 더 큰 값을 찾는다. first는 오름차순이니까.
		{
			up += 1;
		}
		else if (first[up] + second[down] > s) //s 값이 first[up] + second[down]보다 작으면 >> down을 1 증가시켜서, second에서 더 작은 값을 찾는다. second는 내림차순이니까.
		{
			down += 1;	
		}
		
	}
	/* 
	s가 0이고, 벡터 v가 1 2 3 4 면, 
	first는  0 1 2 3 
	second는 7 4 3 0 인데,
	이렇게 되면 부분수열의 합으로 찾고자 하는 s는 찾을 수가 없으므로 0이 답이어야 하지만,
	부분 수열에는 항상 0이 포함되므로, 위에 구현된 알고리즘에 의해서는 first[0] + second[3] = 0 + 0 = 0으로, ans가 1이 된다.
	즉, s=0 일떈, ans를 1 감소시켜야 한다.
	*/
	if (s == 0) ans -= 1;

	cout << ans << '\n';
	
	return 0;
}



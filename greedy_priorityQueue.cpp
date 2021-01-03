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

	/*
	백준 1202번 : 보석 도둑 (그리디 + cmp비교함수 정의 새로운 방법)

	- 이 문제는 시간복잡도를 잘 봐야 한다. 제한시간과 n, k의 최대범위를 따졌을때, O(n*k)의 시간복잡도가 나오면 시간초과가 뜬다.
	 즉, vector하나에다가 보석과 가방의 정보를 다 저장해야 한다. 무게 순으로 정렬하고, 보석과 가방을 구분할 수 있는 bool 변수를 하나 추가한다.
	 그래서 시간복잡도를 O(n+k)로 줄이는 것이 관건이다.

	- sort를 할 때 cmp 비교함수를 한줄에 정의하는 법에 대해 배움. 따로 함수 생성하지 않고!

	-우선순위에 대해서 배움. 최대 힙이 default인데, 최소 힙으로 구현하고 싶으면 priority_queue<int> q 가 아니라,
	priority_queue<int, vector<int>, greater<int> > q; 라고 하면 됨. (자료형이 int가 아니면 다른 자료형으로 통일하면 된다)
	가운데 vector<int>는 그냥 써주면 되고, greater<int> 를 이용하면 된다.
	참고로, less<int> q는 최대 힙인데 어짜피 default값 자체가 최대 힙이니까 굳이 쓸 필요는 없다!

	 */

	int n, k;
	cin >> n >> k;

	vector< tuple<int, int, bool> > v(n + k); //무게, 가치, checking(false > 보석, true > 가방)
	for (int i = 0; i < n; i++)
	{
		cin >> get<0>(v[i]) >> get<1>(v[i]); //보석의 무게와 가치 입력받고, 
		get<2>(v[i]) = false; //보석이니까 false
	}
	for (int i = n; i < n + k; i++)
	{
		cin >> get<0>(v[i]); //가방의 무게를 입력받고, 
		get<1>(v[i]) = 0; //가방의 가치는 여기서 따지지 않으니까 그냥 0으로 초기화
		get<2>(v[i]) = true; //가방이니까 true
	}

	//cmp 비교함수 따로 만들지 않고, 한번에 정의하는 법! [] (매개변수 자료형과 이름) { 조건문; }
	sort(v.begin(), v.end(), [](tuple<int, int, bool> a, tuple<int, int, bool> b) {
		return get<0>(a) < get<0>(b) || (get<0>(a) == get<0>(b) && get<2>(a) < get<2>(b));  //무게를 1순위로, 보석/가방 판단 변수를 2순위로 정렬.
		});
	//이렇게 정렬을 하면, 가방의 무게보다 가벼운 보석들은 모두 그 가방보다 먼저 정렬되어 나오기 때문에, 
	//다시 말해, 현재 상황에서 더해줄 보석들의 후보들을 판별하기가 쉬워진다.(가방보다 먼저 정렬된 보석들 중에서 제일 큰 가치를 가진 보석을 더하면 되니까)
	//그 최대값 (가장 큰 가치)을 가지는 보석은 우선순위 큐로 찾기!


	priority_queue<int> q; //최소 힙으로 구현 하고 싶으면 : priority_queue<int, vector<int>, greater<int> > q;
	ll max_value = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (get<2>(v[i]) == 0) //보석일때
			q.push(get<1>(v[i])); //보석의 가치만 우선순위 큐에 넣는다. (최대 힙)
		else //가방을 만났을 때
		{
			if (!q.empty()) //while이 아니라 if이다! 주의! 우선순위 큐가 비어있지만 않으면 된다!
			{
				max_value += (ll)q.top(); //가장 top에 있는 값 (이때까지 들어간 보석의 가치들 중 최대값이 알아서 top에 있다. 우선순위 큐니까)
				q.pop();
			}
		}
	}

	cout << max_value << '\n';
	return 0;
}

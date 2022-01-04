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

int main()
{
	F_I;

	int n;
	cin >> n;
	deque<pi> dq;
	vector<int> ans;

	for (int i = 1; i <= n; i++) {
		int cur_tower_height; //tower의 높이
		cin >> cur_tower_height;
		if (i == 1) // 첫 번째 탑이 보낸 레이저 신호는 어떤 탑에서도 수신을 하지 못함
		{
			dq.push_back({ cur_tower_height, i }); // {현재 타워의 높이, 현재 타워의 번호}
			ans.push_back(0); // 어떤 탑에서도 수신 못하므로 정답 배열에는 0 입력
			continue;
		}
		while (true) { //자신의 바로 직전 탑부터 왼쪽으로 이동하면서 탐색

			if (dq.empty()) { // 현재 탑보다 높은 탑이 이전에 하나도 없었으면
				dq.push_back({ cur_tower_height, i });
				ans.push_back(0); // 어떤 탑에서도 수신 못하므로 정답 배열에는 0 입력
				break;
			}

			//현재 탑 이전에 있는 탑의 높이 (바로 직전의 탑이 아닐 수도 있음)
			int prev_tower_height = dq.back().first;
			//현재 탑 이전에 있는 탑의 인덱스 (바로 직전의 탑이 아닐 수도 있음)
			int prev_tower_idx = dq.back().second;

			if (prev_tower_height < cur_tower_height) {
				/*
				prev_tower_height가 cur_tower_height보다 작으면, prev_tower_height 값은 이제 쓸모가 없어지므로 pop 시키기
				이유 : 현재 이후에 나올 탑들의 레이저 신호는 감지가 되더라도 cur_tower_height 에 감지가 될 가능성이 있는 거지, prev_tower_height에 걸릴 가능성은 없다.
				(cur_tower_height 가 더 크니까!)
				*/
				dq.pop_back(); // 이거 안하면 시간초과 걸림
			}
			else { // else if (dq.back().first > tower) {
				ans.push_back(prev_tower_idx);
				dq.push_back({ cur_tower_height, i });
				break;
			}
		}
	}

	for (int a : ans)
		cout << a << ' ';
	return 0;
}
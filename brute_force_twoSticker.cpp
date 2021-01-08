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

typedef struct sticker //스티커 만들어놓기 (최대 100개)
{
	int x, y;
} Sticker;

Sticker sticker[101];

int main()
{
	F_I;
	 /*
	 백준 16937번 : 두 스티커
	 - 시간복잡도는 nC2(n개중에 스티커 2개 고름)* 2*2(스티커 한개당 90도 회전이 가능하므로 경우의 수 두가지 가능)* 2 (가로/세로 로 이어붙이는 경우)
	 - 시간복잡도가 오래 걸리지 않으므로, 브루트 포스를 이용하여 모든 스티커에서 2개씩 고르면서 되는 경우 다 따져도 된다!
	 */

	int paper_x, paper_y; //모눈종이의 크기 입력
	cin >> paper_x >> paper_y;

	int n; //스티커의 개수
	cin >> n;

	for (int i = 0; i < n; i++) //스티커의 크기 입력
		cin >> sticker[i].x >> sticker[i].y;

	int r1, w1;//1번째 스티커
	int r2, w2;//2번째 스티커

	//실제 출력 값 : ans
	int ans = 0; //스티커 두 개를 붙일 수 없는 경우에는 ans값의 갱신이 없어야 하는데, 그때 0을 출력하라고 문제에서 언급했으므로 0으로 초기화

	//바깥쪽 for문 2개 : nC2
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++) 
		{
			r1 = sticker[i].x;
			w1 = sticker[i].y;

			r2 = sticker[j].x;
			w2 = sticker[j].y;
			
			//안쪽 for문 2개 : 2*2 (스티커 1개당 회전 0회 & 회전 1회)
			for (int rot1 = 0; rot1 < 2; rot1++)
			{
				for (int rot2 = 0; rot2 < 2; rot2++)
				{
					//if문 두개 : 가로로 이어붙이거나 세로로 이어붙이거나

					if (Max(r1, r2) <= paper_x && w1 + w2 <= paper_y) //가로로 이어붙이는 경우
					{
						if (ans < r1 * w1 + r2 * w2)
							ans = r1 * w1 + r2 * w2;
					}

					//else if 도 가능????
					if (Max(w1, w2) <= paper_y && r1 + r2 <= paper_x) //세로로 이어붙이는 경우
					{
						if (ans < r1 * w1 + r2 * w2)
							ans = r1 * w1 + r2 * w2;
					}

					swap(r1, w1); //첫번째 스티커를 90도 회전
				}
				swap(r2, w2); //두번째 스티커를 90도 회전
			}
		
		}
	}

	cout << ans << '\n'; 

	return 0;
}
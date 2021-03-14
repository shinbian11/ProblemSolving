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

int d[100004]; //d[i] : i까지 가는 최단 시간
int cnt[100004]; //cnt[i]: i까지 가는 최단 시간(최단 경로)의 개수
bool visited[100004];

int main()
{
    F_I;

    //[백준] 12851번 : 숨바꼭질 2 (BFS)

    int n, m;
    cin >> n >> m;

    d[n] = 0;
    cnt[n] = 1;

    visited[n] = true;

    queue<int> q;

    q.push(n);

    while (!q.empty())
    {
        //now ----> next 로 이동
        int now = q.front();
        q.pop();

        for (int next : {now - 1, now + 1, 2 * now})
        {
            if (next >= 0 && next <= 100000) //범위 넘어가면 안된다.
            {
                if (!visited[next]) //next를 처음 방문
                {
                    visited[next] = true;
                    d[next] = d[now] + 1;
                    cnt[next] += cnt[now];
                    q.push(next);
                }
                else if (d[now] + 1 == d[next]) //next를 이미 방문 && d[now]+1 == d[next] 인 경우
                {
                    cnt[next] += cnt[now];
                }
            }
        }
    }

    cout << d[m] << '\n';
    cout << cnt[m] << '\n';

    return 0;
}
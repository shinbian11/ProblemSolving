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

vector<pi> v[1004];
vector<int> ans;
int d[1004];
int from[1004];
bool visited[1004];
int INF = 987654321;
int cnt;

void printPath(int x)
{

    if (from[x] != -1)
        printPath(from[x]);

    cnt += 1;
    ans.push_back(x);
}

int main()
{
    F_I;

    //[백준] 11779번 : 최소비용 구하기 2 (우선순위 큐를 이용한 다익스트라 + 경로 출력까지!)

    int n;
    cin >> n;

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e, cost;
        cin >> s >> e >> cost;
        v[s].push_back({ e,cost });
    }

    for (int i = 1; i <= n; i++)
        d[i] = INF;

    int start, end;
    cin >> start >> end;

    d[start] = 0;
    from[start] = -1;

    priority_queue< pi, vector<pi>, greater<pi> > q; //{cost, node} 순서로 저장

    // 우리가 우선순위 큐를 이용하는 이유는, 가장 작은 'cost' 부터 정렬되어서 나오도록 하기 위해서인데,
    // {cost,node} 순서가 아니라, {node,cost} 순서로 큐에 push를 하면, 원하는 대로 결과값이 나오지 않는다. 가장 작은 node 부터 나오도록 정렬이 되기 때문이다.
    // 결론적으로, 우선순위 큐를 이 문제에서 사용하게 된 이유를 잘 파악해야 한다!

    q.push({ 0,start });

    while (!q.empty())
    {
        auto t = q.top();
        q.pop();
        int x = t.second;

        if (visited[x])
            continue;

        visited[x] = true;

        for (auto t : v[x])
        {
            int y = t.first;
            int cost = t.second;

            if (d[y] > d[x] + cost)
            {
                d[y] = d[x] + cost;
                from[y] = x;

                q.push({ d[y],y });
            }
        }
    }

    cout << d[end] << '\n';

    printPath(end);

    cout << cnt << '\n';

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';

    return 0;
}
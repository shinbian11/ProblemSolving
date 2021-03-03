#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

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

    //[����] 11779�� : �ּҺ�� ���ϱ� 2 (�켱���� ť�� �̿��� ���ͽ�Ʈ�� + ��� ��±���!)

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

    priority_queue< pi, vector<pi>, greater<pi> > q; //{cost, node} ������ ����

    // �츮�� �켱���� ť�� �̿��ϴ� ������, ���� ���� 'cost' ���� ���ĵǾ �������� �ϱ� ���ؼ��ε�,
    // {cost,node} ������ �ƴ϶�, {node,cost} ������ ť�� push�� �ϸ�, ���ϴ� ��� ������� ������ �ʴ´�. ���� ���� node ���� �������� ������ �Ǳ� �����̴�.
    // ���������, �켱���� ť�� �� �������� ����ϰ� �� ������ �� �ľ��ؾ� �Ѵ�!

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
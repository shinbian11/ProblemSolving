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

int root[100004];

typedef struct edge
{
    int from, to, cost;
} Edge;

bool cmp(const edge& a, const edge& b)
{
    return a.cost < b.cost;
}

int Find(int x)
{
    if (x == root[x]) return x;
    else return root[x] = Find(root[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x != y)
        root[x] = y;

    return;
}

int main()
{
    F_I;

    //[����] 1647�� : ���� ���� ��ȹ �з� (ũ�罺Į)

    //�������� �� ����� �����ϸ鼭, �ּ� ����ġ�� ������ �����鸸 �����ϴ� ����
    //ũ�罺Į �˰����� n-1���� �ƴ�, n-2�� �ݺ��ϸ� �����ȴ�!

    int n, m;
    cin >> n >> m;

    vector<Edge> v(m);

    for (int i = 1; i <= n; i++)
        root[i] = i;

    for (int i = 0; i < m; i++)
    {
        cin >> v[i].from >> v[i].to >> v[i].cost;
    }

    sort(v.begin(), v.end(), cmp);
    
    int connect_cnt = 0;
    int connect_sum = 0;

    for (int i = 0; i < m; i++)
    {
        Edge e = v[i];
        int u = Find(e.from);
        int v = Find(e.to);
        int cost = e.cost;
        if (u != v)
        {
            Union(u, v);
            connect_cnt += 1;
            connect_sum += cost;
        }

        if (connect_cnt == n - 2)
            break;
    }

    cout << connect_sum << '\n';

    return 0;
}
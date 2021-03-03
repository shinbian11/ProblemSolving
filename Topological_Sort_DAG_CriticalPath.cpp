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

vector<pi> a[10004];
vector<pi> b[10004];
int ind[10004];
int ind2[10004];

int d[10004];
bool c[10004]; //c[i] : i��° ������ �Ӱ��ο� ���ԵǾ� �ִ� �����̴�.

int main()
{
    F_I;

    /*
    [����] 1948�� : �Ӱ��� (DAG, ��������)
    
    - ���������� �̿��Ͽ�, ������������ ���� ���ϴ� ���� �Ϲ����� �������İ� ����!
    - ������ �� ������ �Ѱ��� �� ����ؾ� �ϴ� ���� �ִµ�, 1�е� ���� �ʰ� �޷��� �ϴ� ������ �����̴�.
    - Ư�� ��η� ���� �� �̵��� ������ ����(�ִ�) �ð�(ù��° ����ؾ� �ϴ� ��)�� �ش��ϴ� ��ζ��, �� ��δ� �Ӱ����̰�,
    �� ��ε鿡 �����ִ� ������ ������ ���ϴ� ���̴�.

    - e.g) ���� 1��° �׽�Ʈ ���̽� ����
    1 2 4 : (1->2 ���µ� cost�� 4 �ʿ��ϴ�)
    1 3 2
    1 4 3
    2 6 3
    2 7 5
    3 5 1
    4 6 4
    5 6 2
    6 7 5

    ��� : 1 , ���� : 7 �϶�, 
    1->2->6->7�� �Ӱ����̰�, 1->4->6->7�� �Ӱ�������, ���� ��� 1->3->5->7�� �Ӱ��ΰ� �ƴϴ�.
   
   --------------------------------------------------------------------------

    - �ι�° ����ؾ� �ϴ� ���� ���ϴ� ����� �̷��ϴ�.

    �Է¹��� ���� ������ ȭ��ǥ ������ �Ųٷ� �Է� �޴´�.(b ����) / �翬�� �Է� ������ �Ųٷ� �Է¹޴´�. (ind2 �迭)
     x ---> y �� �� ��, d[x]�� d[y]�� ���̰� ������ cost(x�� y������ cost)�� ������, �Ӱ� ��ο� ���ԵǴ� ��ζ�� �Ǵ��Ѵ�.
     (���� �̶� x�� �̹� �Ӱ��ο� ���ԵǾ� �ִ� �����̾�� �Ѵ�.) => 136��° �� ����!!

    (- ���� ���� �׽�Ʈ ���̽� 1�� ��츦 �׸����� �׷����鼭 ���� ���ذ� �� �ȴ�!)

    */

    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e, cost;
        cin >> s >> e >> cost;
        a[s].push_back({ e,cost });
        ind[e] += 1;
        
        //�ι�° ��� �� ���ϱ� ���� �ݴ� �������ε� �����ϱ�.
        b[e].push_back({ s,cost });
        ind2[s] += 1;
    }

    int start, end;
    cin >> start >> end;

    //-------ù��° ��� �� ���ϴ� �κ� (�Ϲ����� ��������)-------
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
        }
    }
   
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        
        for (auto t : a[x])
        {
            int y = t.first;
            int cost = t.second;
           
            if (d[y] < d[x] + cost)
            {
                d[y] = d[x] + cost;
            }

            ind[y] -= 1;

            if (ind[y] == 0)
                q.push(y);
        }
    }

    cout << d[end] << '\n';

    //-------�ι�° ��� �� ���ϴ� �ڵ�-------

    int ans = 0;
    c[end] = true; //c[i] : i��° ������ �Ӱ��ο� ���ԵǾ� �ִ� �����̴�. �� ������ �������� �׻� �Ӱ��ο� ���ԵǾ� �ִ� ���̹Ƿ� true�� �ʱ�ȭ ���ش�.

    for (int i = 1; i <= n; i++)
    {
        if (ind2[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto t : b[x])
        {
            int y = t.first;
            int cost = t.second;

            //���� ���� �κп��� ����� �κ�. 
            if (c[x] == true && d[x] - d[y] == cost) 
            {
                c[y] = true;
                ans += 1;
            }

            ind2[y] -= 1;

            if (ind2[y] == 0)
                q.push(y);
        }
    }

    cout << ans << '\n';

    return 0;
}
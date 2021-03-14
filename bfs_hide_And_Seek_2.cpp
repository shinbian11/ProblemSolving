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

int d[100004]; //d[i] : i���� ���� �ִ� �ð�
int cnt[100004]; //cnt[i]: i���� ���� �ִ� �ð�(�ִ� ���)�� ����
bool visited[100004];

int main()
{
    F_I;

    //[����] 12851�� : ���ٲ��� 2 (BFS)

    int n, m;
    cin >> n >> m;

    d[n] = 0;
    cnt[n] = 1;

    visited[n] = true;

    queue<int> q;

    q.push(n);

    while (!q.empty())
    {
        //now ----> next �� �̵�
        int now = q.front();
        q.pop();

        for (int next : {now - 1, now + 1, 2 * now})
        {
            if (next >= 0 && next <= 100000) //���� �Ѿ�� �ȵȴ�.
            {
                if (!visited[next]) //next�� ó�� �湮
                {
                    visited[next] = true;
                    d[next] = d[now] + 1;
                    cnt[next] += cnt[now];
                    q.push(next);
                }
                else if (d[now] + 1 == d[next]) //next�� �̹� �湮 && d[now]+1 == d[next] �� ���
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
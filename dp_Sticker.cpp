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

int arr[2][100004];
int d[2][100004];

void solve()
{
    /*
    e.g.)

    50 10 100
    30 50 70

    ����, ���� ����� ���� 4������ �ִ�.

    1.  50 50 100
    2.  30 100
    3.  30 10 70
    4.  50 70

     - 100(arr[0][2]) ���ؿ��� ���� �ϴ°� 50(arr[1][1]) �ƴϸ� 30(arr[1][0])�̰�,
     - 70(arr[1][2]) ���ؿ��� ���� �ϴ°� 50(arr[0][0]) �ƴϸ� 10(arr[0][1])�̴�.

     ��, arr[0][i] ���ؿ��� ���� �ϴ°� arr[1][i-1]�� arr[1][i-2] �߿��� �ִ밪�̰�,
     ��, arr[1][i] ���ؿ��� ���� �ϴ°� arr[0][i-1]�� arr[0][i-2] �߿��� �ִ밪�̴�.

     */

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[0][i];
    for (int i = 0; i < n; i++)
        cin >> arr[1][i];

    d[0][0] = arr[0][0];
    d[0][1] = arr[0][1] + arr[1][0];
    d[1][0] = arr[1][0];
    d[1][1] = arr[1][1] + arr[0][0];

    //https://jdselectron.tistory.com/75 ���� �� ������ ĭ�� �ִ� 100�� 70�������� ���� �����!

    for (int i = 2; i < n; i++)
    {
        d[0][i] = arr[0][i] + max(d[1][i - 1] , d[1][i - 2]);
        d[1][i] = arr[1][i] + max(d[0][i - 1] , d[0][i - 2]);
    }

    cout << max(d[0][n - 1], d[1][n - 1]) << '\n';

    return;
}
int main()
{
    F_I;
    int tc;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
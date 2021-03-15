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

int arr[2][100004];
int d[2][100004];

void solve()
{
    /*
    e.g.)

    50 10 100
    30 50 70

    에서, 고르는 경우의 수는 4가지가 있다.

    1.  50 50 100
    2.  30 100
    3.  30 10 70
    4.  50 70

     - 100(arr[0][2]) 기준에서 골라야 하는건 50(arr[1][1]) 아니면 30(arr[1][0])이고,
     - 70(arr[1][2]) 기준에서 골라야 하는건 50(arr[0][0]) 아니면 10(arr[0][1])이다.

     즉, arr[0][i] 기준에서 골라야 하는건 arr[1][i-1]과 arr[1][i-2] 중에서 최대값이고,
     즉, arr[1][i] 기준에서 골라야 하는건 arr[0][i-1]과 arr[0][i-2] 중에서 최대값이다.

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

    //https://jdselectron.tistory.com/75 에서 맨 오른쪽 칸에 있는 100과 70기준으로 식을 세우기!

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
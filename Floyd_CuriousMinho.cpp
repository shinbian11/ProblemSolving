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

int arr[21][21];
int unused[21][21];

int main()
{
    F_I;
   
    //[백준] 1507번 : 궁금한 민호 (플로이드)

    /*
    - 모든 도시 사이의 최소 이동 시간이 주어졌다는 것은, 입력으로 이미 최단 시간이 주어졋다는 의미이다.
    - i     j
         k
     만약 i--->j로 가는 cost와 i-->k + k-->j의 cost의 합이 같다면, i--->j의 경로는 쓸모가 없어지는 것이다.
     모든 k에 대해 탐색하면서, 이렇게 쓸모없는 경로들을 제거하는 방식으로 가야한다.
    */

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (k == i) continue; //k와 i는 같으면 안됨
            for (int j = 1; j <= n; j++)
            {
                if (k == j) continue; //k와 j는 같으면 안됨
                if (i == j) continue; //i와 j는 같으면 안됨

                if (arr[i][j] > arr[i][k] + arr[k][j])
                {
                    cout << -1 << '\n';
                    return 0;
                }

                if (arr[i][j] == arr[i][k] + arr[k][j]) //값이 같으면, i-->j의 경로는 쓸모없는 경로가 된다.
                    unused[i][j] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (unused[i][j] == false) //쓸모있는 경로의 cost만 값에 더한다.
                ans += arr[i][j];
        }
    }

    cout << ans / 2 << '\n'; // i-->j 와 j-->i의 값을 둘 다 더했으니, 하나는 빼주어야 한다.

    return 0;
}
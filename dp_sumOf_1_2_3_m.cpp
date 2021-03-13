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

ll d[1004][1004];

int main()
{
    F_I;

   //[백준] 15992번 : 1,2,3 더하기 문제 7
   //1,2,3 더하기 문제와 매우 비슷하다!
   //d[i][j] : j개의 수를 이용하여 i를 만드는 경우의 수
    /*
    
    다 더해서 i가 나오려면 , d[i][j] =
     ______________+ 1 = i : d[i-1][j-1]
     ______________+ 2 = i : d[i-2][j-1]
     ______________+ 3 = i : d[i-3][j-1]
     의 합이다.
    
    */

    int tc;
    ll mod = 1000000009LL;
    
    d[0][0] = 1;

    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i - 1 >= 0)
                d[i][j] += d[i - 1][j - 1];
            if (i - 2 >= 0)
                d[i][j] += d[i - 2][j - 1];
            if (i - 3 >= 0)
                d[i][j] += d[i - 3][j - 1];
            d[i][j] %= mod;
        }
    }
    
    cin >> tc;

    while (tc--) 
    {
        int n, m;
        cin >> n >> m;
        cout << d[n][m] << '\n';
    }
    
    
    return 0;
}
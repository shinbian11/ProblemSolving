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

ll d[1004][1004];

int main()
{
    F_I;

   //[����] 15992�� : 1,2,3 ���ϱ� ���� 7
   //1,2,3 ���ϱ� ������ �ſ� ����ϴ�!
   //d[i][j] : j���� ���� �̿��Ͽ� i�� ����� ����� ��
    /*
    
    �� ���ؼ� i�� �������� , d[i][j] =
     ______________+ 1 = i : d[i-1][j-1]
     ______________+ 2 = i : d[i-2][j-1]
     ______________+ 3 = i : d[i-3][j-1]
     �� ���̴�.
    
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
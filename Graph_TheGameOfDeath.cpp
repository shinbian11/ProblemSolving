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

vector< vector<bool> > operator * (const vector< vector<bool> >& a, const vector< vector<bool> >& b) //행렬끼리의 곱셈 ( * 연산자 오버로딩)
{

    int size = a.size();
    
    vector< vector<bool> > ans(size, vector<bool>(size, false));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                if (a[i][k] && b[k][j])
                    ans[i][j] = true;
            }
        }
    }

    return ans;
}

//행렬의 거듭제곱 (수의 거듭제곱하는 방법 -> https://travelbeeee.tistory.com/117 참고)
vector< vector<bool> > pow(vector< vector<bool> > v, int k) 
{
    int size = v.size();

    vector< vector<bool> > ans(size, vector<bool>(size));

    for (int i = 0; i < size; i++) ans[i][i] = true;

    while (k)
    {
        if (k & 1)
        {
            ans = ans * v;
        } 

        v = v * v;
        k /= 2;
    }

    return ans;
}

int main()
{
    F_I;

    //[백준] 2099번 : The game of death

    //v[i][j] : i --> j 로 경로 1개만에 갈 수 있는 방법이 있다.
    //v의 k제곱의 [i][j] : i --> j 로 경로 k개만에 갈 수 있는 방법이 있다.
    
    //v의 K제곱의 [a][b]이 존재하는지 여부를 판단하면 되는 문제이다! a에서 b로 가는데 k개의 경로를 거치는 방법의 수가 존재하면 death, 아니면 life

    int n, k, m;
    cin >> n >> k >> m;
    vector< vector<bool> > v(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[i][a-1] = true;
        v[i][b-1] = true;
    }
    
    vector< vector<bool> > ans = pow(v, k); //matrix v를 k번 거듭제곱한 결과
  

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        if (ans[a-1][b-1] == true)
            cout << "death" << '\n';
        else
            cout << "life" << '\n';
    }

    return 0;
}
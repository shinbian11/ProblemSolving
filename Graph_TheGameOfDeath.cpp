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

vector< vector<bool> > operator * (const vector< vector<bool> >& a, const vector< vector<bool> >& b) //��ĳ����� ���� ( * ������ �����ε�)
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

//����� �ŵ����� (���� �ŵ������ϴ� ��� -> https://travelbeeee.tistory.com/117 ����)
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

    //[����] 2099�� : The game of death

    //v[i][j] : i --> j �� ��� 1������ �� �� �ִ� ����� �ִ�.
    //v�� k������ [i][j] : i --> j �� ��� k������ �� �� �ִ� ����� �ִ�.
    
    //v�� K������ [a][b]�� �����ϴ��� ���θ� �Ǵ��ϸ� �Ǵ� �����̴�! a���� b�� ���µ� k���� ��θ� ��ġ�� ����� ���� �����ϸ� death, �ƴϸ� life

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
    
    vector< vector<bool> > ans = pow(v, k); //matrix v�� k�� �ŵ������� ���
  

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
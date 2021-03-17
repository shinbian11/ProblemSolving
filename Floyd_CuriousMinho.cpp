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

int arr[21][21];
int unused[21][21];

int main()
{
    F_I;
   
    //[����] 1507�� : �ñ��� ��ȣ (�÷��̵�)

    /*
    - ��� ���� ������ �ּ� �̵� �ð��� �־����ٴ� ����, �Է����� �̹� �ִ� �ð��� �־�ٴ� �ǹ��̴�.
    - i     j
         k
     ���� i--->j�� ���� cost�� i-->k + k-->j�� cost�� ���� ���ٸ�, i--->j�� ��δ� ���� �������� ���̴�.
     ��� k�� ���� Ž���ϸ鼭, �̷��� ������� ��ε��� �����ϴ� ������� �����Ѵ�.
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
            if (k == i) continue; //k�� i�� ������ �ȵ�
            for (int j = 1; j <= n; j++)
            {
                if (k == j) continue; //k�� j�� ������ �ȵ�
                if (i == j) continue; //i�� j�� ������ �ȵ�

                if (arr[i][j] > arr[i][k] + arr[k][j])
                {
                    cout << -1 << '\n';
                    return 0;
                }

                if (arr[i][j] == arr[i][k] + arr[k][j]) //���� ������, i-->j�� ��δ� ������� ��ΰ� �ȴ�.
                    unused[i][j] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (unused[i][j] == false) //�����ִ� ����� cost�� ���� ���Ѵ�.
                ans += arr[i][j];
        }
    }

    cout << ans / 2 << '\n'; // i-->j �� j-->i�� ���� �� �� ��������, �ϳ��� ���־�� �Ѵ�.

    return 0;
}
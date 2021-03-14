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

int arr[54][54];
int d[54][54];

int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };
int copyarr[54][54];

int n, m, t;
int ux = -1, uy = -1, dx = -1, dy = -1; //����û������ ��ġ

void diffusion()
{
    memset(copyarr, 0, sizeof(copyarr));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            copyarr[i][j] = arr[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == ux && j == uy) continue; //����û���Ⱑ �ִ� ��ġ�� �̼����� Ȯ�� X
            if (i == dx && j == dy) continue; //����û���Ⱑ �ִ� ��ġ�� �̼����� Ȯ�� X

            int spread = copyarr[i][j] / 5;
            int cnt = 0;

            for (int k = 0; k < 4; k++)
            {
                int nx = i + mx[k];
                int ny = j + my[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    if (nx == ux && ny == uy) continue;
                    if (nx == dx && ny == dy) continue;

                    arr[nx][ny] += spread;
                    cnt += 1;
                }
            }
            arr[i][j] -= spread * cnt;
        }
    }


}

void AirCleaner()
{

    //���� û���� ���� �κ� (�ݽð����)
    for (int i = ux - 2; i >= 0; i--)
        arr[i + 1][0] = arr[i][0];
    for (int j = 1; j <= uy + m - 1; j++)
        arr[0][j - 1] = arr[0][j];
    for (int i = 1; i <= ux; i++)
        arr[i - 1][uy + m - 1] = arr[i][uy + m - 1];
    for (int j = uy + m - 2; j >= 1; j--)
        arr[ux][j + 1] = arr[ux][j];
    arr[ux][1] = 0; //����û���⿡�� ��� ���� ĭ�� 0�̴�. (������ ����)


     //���� û���� �Ʒ��� �κ� (�ð����)
    for (int i = dx + 2; i <= n - 1; i++)
        arr[i - 1][0] = arr[i][0];
    for (int j = 1; j <= m - 1; j++)
        arr[n - 1][j - 1] = arr[n - 1][j];
    for (int i = n - 2; i >= dx; i--)
        arr[i + 1][m - 1] = arr[i][m - 1];
    for (int j = dy + m - 2; j >= 1; j--)
        arr[dx][j + 1] = arr[dx][j];
    arr[dx][1] = 0; //����û���⿡�� ��� ���� ĭ�� 0�̴�. (������ ����)
}

int SumOfDirt() //��� �̼����� �� �ջ�
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            sum += arr[i][j];
    }

    return sum; //-1 ¥�� ����û���� 2 ���� �������ϱ�.
}

int main()
{
    F_I;

    //[����] 17144�� : �̼����� �ȳ�! (BFS)

    cin >> n >> m >> t;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == -1) //����û������ ��ġ ������ ��ϸ� �صΰ�, �� ���Ŀ����� ����û���⵵ �׳� 0���� ���!
            {
                if (ux == -1)
                {
                    ux = i;
                    uy = j;
                }
                else
                {
                    dx = i;
                    dy = j;
                }
                arr[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= t; i++) //Ȯ��� ����û���� ������ t�� �ݺ�!
    {
        diffusion(); //�̼����� Ȯ��
        AirCleaner(); //����û���� ����
    }

    cout << SumOfDirt() << '\n'; //t�� �ݺ� ���Ŀ� �����ִ� ��� �̼����� �� �ջ�

    return 0;
}
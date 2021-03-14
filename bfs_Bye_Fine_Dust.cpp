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

int arr[54][54];
int d[54][54];

int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };
int copyarr[54][54];

int n, m, t;
int ux = -1, uy = -1, dx = -1, dy = -1; //공기청정기의 위치

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
            if (i == ux && j == uy) continue; //공기청정기가 있는 위치는 미세먼지 확산 X
            if (i == dx && j == dy) continue; //공기청정기가 있는 위치는 미세먼지 확산 X

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

    //공기 청정기 위쪽 부분 (반시계방향)
    for (int i = ux - 2; i >= 0; i--)
        arr[i + 1][0] = arr[i][0];
    for (int j = 1; j <= uy + m - 1; j++)
        arr[0][j - 1] = arr[0][j];
    for (int i = 1; i <= ux; i++)
        arr[i - 1][uy + m - 1] = arr[i][uy + m - 1];
    for (int j = uy + m - 2; j >= 1; j--)
        arr[ux][j + 1] = arr[ux][j];
    arr[ux][1] = 0; //공기청정기에서 방금 나온 칸은 0이다. (깨끗한 공기)


     //공기 청정기 아래쪽 부분 (시계방향)
    for (int i = dx + 2; i <= n - 1; i++)
        arr[i - 1][0] = arr[i][0];
    for (int j = 1; j <= m - 1; j++)
        arr[n - 1][j - 1] = arr[n - 1][j];
    for (int i = n - 2; i >= dx; i--)
        arr[i + 1][m - 1] = arr[i][m - 1];
    for (int j = dy + m - 2; j >= 1; j--)
        arr[dx][j + 1] = arr[dx][j];
    arr[dx][1] = 0; //공기청정기에서 방금 나온 칸은 0이다. (깨끗한 공기)
}

int SumOfDirt() //모든 미세먼지 양 합산
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            sum += arr[i][j];
    }

    return sum; //-1 짜리 공기청정기 2 개도 더했으니까.
}

int main()
{
    F_I;

    //[백준] 17144번 : 미세먼지 안녕! (BFS)

    cin >> n >> m >> t;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == -1) //공기청정기의 위치 정보는 기록만 해두고, 그 이후에서는 공기청정기도 그냥 0으로 취급!
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

    for (int i = 1; i <= t; i++) //확산과 공기청정기 가동을 t번 반복!
    {
        diffusion(); //미세먼지 확산
        AirCleaner(); //공기청정기 가동
    }

    cout << SumOfDirt() << '\n'; //t번 반복 이후에 남아있는 모든 미세먼지 양 합산

    return 0;
}
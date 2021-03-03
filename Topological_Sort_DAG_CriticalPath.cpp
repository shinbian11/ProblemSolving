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

vector<pi> a[10004];
vector<pi> b[10004];
int ind[10004];
int ind2[10004];

int d[10004];
bool c[10004]; //c[i] : i번째 정점은 임계경로에 포함되어 있는 정점이다.

int main()
{
    F_I;

    /*
    [백준] 1948번 : 임계경로 (DAG, 위상정렬)
    
    - 위상정렬을 이용하여, 도착점에서의 값을 구하는 것은 일반적인 위상정렬과 같다!
    - 하지만 이 문제는 한가지 더 출력해야 하는 값이 있는데, 1분도 쉬지 않고 달려야 하는 도로의 개수이다.
    - 특정 경로로 갔을 때 이들이 만나는 최종(최대) 시간(첫번째 출력해야 하는 답)에 해당하는 경로라면, 그 경로는 임계경로이고,
    그 경로들에 속해있는 도로의 개수를 구하는 것이다.

    - e.g) 백준 1번째 테스트 케이스 참고
    1 2 4 : (1->2 가는데 cost가 4 필요하다)
    1 3 2
    1 4 3
    2 6 3
    2 7 5
    3 5 1
    4 6 4
    5 6 2
    6 7 5

    출발 : 1 , 도착 : 7 일때, 
    1->2->6->7은 임계경로이고, 1->4->6->7도 임계경로지만, 예를 들어 1->3->5->7은 임계경로가 아니다.
   
   --------------------------------------------------------------------------

    - 두번째 출력해야 하는 답을 구하는 방법은 이러하다.

    입력받은 연결 관계의 화살표 방향을 거꾸로 입력 받는다.(b 벡터) / 당연히 입력 차수도 거꾸로 입력받는다. (ind2 배열)
     x ---> y 로 갈 때, d[x]와 d[y]의 차이가 실제의 cost(x와 y사이의 cost)와 같으면, 임계 경로에 포함되는 경로라고 판단한다.
     (물론 이때 x는 이미 임계경로에 포함되어 있는 정점이어야 한다.) => 136번째 줄 참고!!

    (- 직접 백준 테스트 케이스 1의 경우를 그림으로 그려가면서 보면 이해가 잘 된다!)

    */

    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e, cost;
        cin >> s >> e >> cost;
        a[s].push_back({ e,cost });
        ind[e] += 1;
        
        //두번째 출력 값 구하기 위해 반대 방향으로도 설정하기.
        b[e].push_back({ s,cost });
        ind2[s] += 1;
    }

    int start, end;
    cin >> start >> end;

    //-------첫번째 출력 값 구하는 부분 (일반적인 위상정렬)-------
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
        }
    }
   
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        
        for (auto t : a[x])
        {
            int y = t.first;
            int cost = t.second;
           
            if (d[y] < d[x] + cost)
            {
                d[y] = d[x] + cost;
            }

            ind[y] -= 1;

            if (ind[y] == 0)
                q.push(y);
        }
    }

    cout << d[end] << '\n';

    //-------두번째 출력 값 구하는 코드-------

    int ans = 0;
    c[end] = true; //c[i] : i번째 정점은 임계경로에 포함되어 있는 정점이다. 맨 마지막 도착점은 항상 임계경로에 포함되어 있는 점이므로 true로 초기화 해준다.

    for (int i = 1; i <= n; i++)
    {
        if (ind2[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto t : b[x])
        {
            int y = t.first;
            int cost = t.second;

            //위에 설명 부분에서 언급한 부분. 
            if (c[x] == true && d[x] - d[y] == cost) 
            {
                c[y] = true;
                ans += 1;
            }

            ind2[y] -= 1;

            if (ind2[y] == 0)
                q.push(y);
        }
    }

    cout << ans << '\n';

    return 0;
}
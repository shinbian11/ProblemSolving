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


//(r,c)를 중심으로 하고, 그 중심을 기준으로 껍질(?)이 최대 size 바퀴까지 가능한 정사각형 함수를 rotate하는 함수이다.
/*
e.g.) r=3,c=3 이고, size=2이면, 
  
   (1,1) (1,2) (1,3) (1,4) (1,5)
   (2,1) (2,2) (2,3) (2,4) (2,5)
   (3,1) (3,2) (3,3) (3,4) (3,5)
   (4,1) (4,2) (4,3) (4,4) (4,5)
   (5,1) (5,2) (5,3) (5,4) (5,5)   에서,  


(2,2) (2,3) (2,4)
(3,2)       (3,4)
(4,2) (4,3) (4,4)   가 size = 1 인 껍질 

(1,1) (1,2) (1,3) (1,4) (1,5)
(2,1)			(2,5)
(3,1)			(3,5)
(4,1)			(4,5)
(5,1) (5,2) (5,3) (5,4) (5,5)   가 size = 2 인 껍질이다.

-----------------------------------------------------------

(r-s,c-s) ........... (r-s,c+s)
   ...                   ...
   ...                   ...
   ...                   ...
   ...                   ...
(r+s,c-s) ........... (r+s,c+s)  에서, 

좌측 상단 (r-s, c-s)부터 오른쪽으로 순서대로 -> (r-s,c+s) 직전까지  
우측 상단 (r-s, c+s)부터 아래쪽으로 순서대로 -> (r+s,c+s) 직전까지   
우측 하단 (r+s, c+s)부터 왼쪽으로 순서대로 -> (r+s,c-s) 직전까지   
좌측 하단 (r+s,c-s)부터 위쪽으로 순서대로 -> (r-s,c-s) 직전까지   

>> 이 방향으로 값들을 info 벡터에 저장해둔다.

-----------------------------------------------------------

(rotate 함수 사용법 - 참고) : https://unluckyjung.github.io/cpp/2020/04/10/Rotate/

rotate(a,b,c) > (a,b-1)를 c로 옮긴다.

e.g) 12345 에서 rotate(begin, begin + 1, end) 하면 >> 23451
e.g) 12345 에서 rotate(rbegin, rbegin + 1, rend) 하면 >> 51234

지금 현재 123456...n 의 값을 n12345...(n-1) 로 옮겨야 하므로 (시계방향으로 회전) 

 rotate(rbegin, rbegin + 1, rend) 사용해야 한다!


 > 그 이후 다시 배열에 값 갱신해서 저장하기!
*/
void spin(vector< vector<int> >& arr, tuple<int, int, int> rot)
{
	int r, c, size;
	tie(r, c, size) = rot;

	vector< vector<int> > information;
	int i, j;

	for (int s = 1; s <= size; s++)
	{
		vector<int> info;
		for (i = r - s, j = c - s; j < c + s; j++)
		{
			info.push_back(arr[i][j]);
		}
		for (i = r - s, j = c + s; i < r + s; i++)
		{
			info.push_back(arr[i][j]);
		}
		for (i = r + s, j = c + s; j > c - s; j--)
		{
			info.push_back(arr[i][j]);
		}
		for (i = r + s, j = c - s; i > r - s; i--)
		{
			info.push_back(arr[i][j]);
		}

		information.push_back(info);
	}

	for (int s = 1; s <= size; s++)
	{
		//rotate (시계방향으로 한칸 씩 회전)
		rotate(information[s-1].rbegin(), information[s-1].rbegin() + 1, information[s-1].rend());

		int idx = 0;

		//rotate 한 내용을 다시 옮겨담기
		for (i = r - s, j = c - s; j < c + s; j++)
		{
			arr[i][j] = information[s-1][idx++];
		}
		for (i = r - s, j = c + s; i < r + s; i++)
		{
			arr[i][j] = information[s-1][idx++];
		}
		for (i = r + s, j = c + s; j > c - s; j--)
		{
			arr[i][j] = information[s-1][idx++];
		}
		for (i = r + s, j = c - s; i > r - s; i--)
		{
			arr[i][j] = information[s-1][idx++];
		}
	}

	return;

}

int main()
{
	/*
	[백준] 17406번 : 배열 돌리기 4 (브루트 포스)

	- 주어진 회전 연산 횟수는 k(k<=6)번이고, 이를 일일히 next_permutation 하면서, 배열을 일일히 회전시키고, 그 이후에 최소값을 구하는 행위를 해도 된다.
	브루트 포스 가능.
	-spin 함수 내용 중요!
	*/
	
	int n, m, k;
	cin >> n >> m >> k;

	vector< vector<int> > arr(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	vector< tuple<int, int, int> > rot;

	for (int i = 0; i < k; i++)
	{
		int r, c, s;
		cin >> r >> c >> s;
		rot.emplace_back(r - 1, c - 1, s); // arr 입력받을 때 시작 인덱스는 0이니까.
	}

	sort(rot.begin(), rot.end()); //next_permutation 해야 하니까 내림차순 정렬

	int ans = -1;

	do
	{
		vector< vector<int> > copy = arr; //복사본

		for (int i = 0; i < k; i++) // 각각의 회전 연산 정보에 대해서 copy 함수를 회전시킨다.
		{
			spin(copy, rot[i]);
		}

		for (int i = 0; i < n; i++) //회전시킨 copy 함수에 대해서 최소값 구한다.
		{
			int sum = 0;

			for (int j = 0; j < m; j++)
			{
				sum += copy[i][j];
			}

			if (ans == -1 || ans > sum)
				ans = sum;
		}

	} while (next_permutation(rot.begin(), rot.end()));

	cout << ans << '\n';

	return 0;
}
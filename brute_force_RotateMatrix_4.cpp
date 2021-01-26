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


//(r,c)�� �߽����� �ϰ�, �� �߽��� �������� ����(?)�� �ִ� size �������� ������ ���簢�� �Լ��� rotate�ϴ� �Լ��̴�.
/*
e.g.) r=3,c=3 �̰�, size=2�̸�, 
  
   (1,1) (1,2) (1,3) (1,4) (1,5)
   (2,1) (2,2) (2,3) (2,4) (2,5)
   (3,1) (3,2) (3,3) (3,4) (3,5)
   (4,1) (4,2) (4,3) (4,4) (4,5)
   (5,1) (5,2) (5,3) (5,4) (5,5)   ����,  


(2,2) (2,3) (2,4)
(3,2)       (3,4)
(4,2) (4,3) (4,4)   �� size = 1 �� ���� 

(1,1) (1,2) (1,3) (1,4) (1,5)
(2,1)			(2,5)
(3,1)			(3,5)
(4,1)			(4,5)
(5,1) (5,2) (5,3) (5,4) (5,5)   �� size = 2 �� �����̴�.

-----------------------------------------------------------

(r-s,c-s) ........... (r-s,c+s)
   ...                   ...
   ...                   ...
   ...                   ...
   ...                   ...
(r+s,c-s) ........... (r+s,c+s)  ����, 

���� ��� (r-s, c-s)���� ���������� ������� -> (r-s,c+s) ��������  
���� ��� (r-s, c+s)���� �Ʒ������� ������� -> (r+s,c+s) ��������   
���� �ϴ� (r+s, c+s)���� �������� ������� -> (r+s,c-s) ��������   
���� �ϴ� (r+s,c-s)���� �������� ������� -> (r-s,c-s) ��������   

>> �� �������� ������ info ���Ϳ� �����صд�.

-----------------------------------------------------------

(rotate �Լ� ���� - ����) : https://unluckyjung.github.io/cpp/2020/04/10/Rotate/

rotate(a,b,c) > (a,b-1)�� c�� �ű��.

e.g) 12345 ���� rotate(begin, begin + 1, end) �ϸ� >> 23451
e.g) 12345 ���� rotate(rbegin, rbegin + 1, rend) �ϸ� >> 51234

���� ���� 123456...n �� ���� n12345...(n-1) �� �Űܾ� �ϹǷ� (�ð�������� ȸ��) 

 rotate(rbegin, rbegin + 1, rend) ����ؾ� �Ѵ�!


 > �� ���� �ٽ� �迭�� �� �����ؼ� �����ϱ�!
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
		//rotate (�ð�������� ��ĭ �� ȸ��)
		rotate(information[s-1].rbegin(), information[s-1].rbegin() + 1, information[s-1].rend());

		int idx = 0;

		//rotate �� ������ �ٽ� �Űܴ��
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
	[����] 17406�� : �迭 ������ 4 (���Ʈ ����)

	- �־��� ȸ�� ���� Ƚ���� k(k<=6)���̰�, �̸� ������ next_permutation �ϸ鼭, �迭�� ������ ȸ����Ű��, �� ���Ŀ� �ּҰ��� ���ϴ� ������ �ص� �ȴ�.
	���Ʈ ���� ����.
	-spin �Լ� ���� �߿�!
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
		rot.emplace_back(r - 1, c - 1, s); // arr �Է¹��� �� ���� �ε����� 0�̴ϱ�.
	}

	sort(rot.begin(), rot.end()); //next_permutation �ؾ� �ϴϱ� �������� ����

	int ans = -1;

	do
	{
		vector< vector<int> > copy = arr; //���纻

		for (int i = 0; i < k; i++) // ������ ȸ�� ���� ������ ���ؼ� copy �Լ��� ȸ����Ų��.
		{
			spin(copy, rot[i]);
		}

		for (int i = 0; i < n; i++) //ȸ����Ų copy �Լ��� ���ؼ� �ּҰ� ���Ѵ�.
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
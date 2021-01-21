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

/*
(ȸ�� ����) 

������ : 0
�Ʒ� : 1
���� : 2 
���� : 3 
- ȸ�� ������ �ݽð�������� ������. 

- ���� dx,dy�� �� ����� �ݿ��Ͽ� ���� ������

*/

int dx[4] = { 0,1,0,-1 }; //��,��,��,��
int dy[4] = { 1,0,-1,0 }; //��,��,��,��

//x�� y���� cctv����, rotate[i] ���⿡ �ִ� ��ĭ���� ��� �� cctv�� ������ �� �ִ� ĭ���� �۾��س��� �Լ�
void check(vector< vector<int> >& v, vector< vector<int> >& b, int sx, int sy, int dir) //dir : ȸ�� ���� (0,1,2,3)
{
	int n = v.size();
	int m = v[0].size();
	int x = sx;
	int y = sy;

	while (x >= 0 && x < n && y >= 0 && y < m) //���� üũ
	{
		if (v[x][y] == 6)
			break;
		// -1�� ���������� # ó���� �Ͱ� ����. �ش� ĭ�� ���� ������ ���ٴ� �ǹ�.
		b[x][y] = -1; 
		// b �迭�� ���� ����� ���� : �̷��� �繫�� �迭�� ������ ĭ�� ���� ��� �����ؾ� �ϱ� ������, a �迭 �ϳ��δ� �����̴�! 
		// �� ��쿡 ���� ������ ���� ��츦 ���� ����, a �迭�� �׶��׶� ������Ű�� �� �ʹ� �������ϱ�!
		// �׷��Ƿ� 4^c �� ��츦 �ϳ��ϳ� �Ҷ�����, ���ο� b �迭�� ���� �� �������� �ذ��Ѵ�.

		x += dx[dir]; //dir �������� ��� ���ư�
		y += dy[dir]; //dir �������� ��� ���ư�
	}
}

int find(vector< vector<int> >& v, vector< tuple<int, int, int> >& cctv, int cctv_index, vector<int>& rotate)
{
	int n = v.size();
	int m = v[0].size();

	//��� cctv�� �� Ž������ ��
	if (cctv.size() == cctv_index)
	{
		vector< vector<int> > b(v); //�繫�� �迭�� ������

		for (int i = 0; i < cctv.size(); i++)
		{
			int cctv_what, x, y;
			tie(cctv_what, x, y) = cctv[i];

			if (cctv_what == 1) //i��° cctv�� 1�� cctv��� 
			{
				check(v, b, x, y, rotate[i]); //x�� y���� cctv����, rotate[i] ���⿡ �ִ� ��ĭ���� ��� �� cctv�� ������ �� �ִ� ĭ���� �۾��س��� �Լ�
			}
			else if (cctv_what == 2) //i��° cctv�� 2�� cctv���
			{
				check(v, b, x, y, rotate[i]);
				check(v, b, x, y, (rotate[i]+2)%4);
			}
			else if (cctv_what == 3) //i��° cctv�� 3�� cctv���
			{
				check(v, b, x, y, rotate[i]);
				check(v, b, x, y, (rotate[i] + 1) % 4);
			}
			else if (cctv_what == 4) //i��° cctv�� 4�� cctv���
			{
				check(v, b, x, y, rotate[i]);
				check(v, b, x, y, (rotate[i] + 1) % 4);
				check(v, b, x, y, (rotate[i] + 2) % 4);
			}
			else if (cctv_what == 5) //i��° cctv�� 5�� cctv���
			{
				check(v, b, x, y, rotate[i]);
				check(v, b, x, y, (rotate[i] + 1) % 4);
				check(v, b, x, y, (rotate[i] + 2) % 4);
				check(v, b, x, y, (rotate[i] + 3) % 4);
			}
		}

		//main �Լ����� step2 �� �ش��ϴ� �ڵ� : �簢���� ���� ����
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (b[i][j] == 0) //��ĭ�̸�(cctv�� ���� ������ ���� �ʴ� �κ�)
					cnt += 1;
			}
		}

		return cnt;
	}


	int ans = 65; //�簢����� �ƹ��� ���ƺ��� 8*8= 64���̴�.

	for (int i = 0; i < 4; i++)
	{
		rotate[cctv_index] = i; //cctv_index ��° cctv�� i��° ȸ�� ������ ������.
		int tmp = find(v, cctv, cctv_index + 1, rotate); // �� ���� cctv
		if (ans > tmp)
			ans = tmp; //�ּҰ�
	}

	return ans;
}

int main()
{
	F_I;

	/*
	15683�� : ���� (���Ʈ ����)

	- ���� ��� 

	cctv 1��  : ȸ���ϸ� 4���� ���� ���� ����
	cctv 2��  : ȸ���ϸ� 2���� ���� ���� ����
	cctv 3��  : ȸ���ϸ� 3���� ���� ���� ����
	cctv 4��  : ȸ���ϸ� 3���� ���� ���� ����
	cctv 5��  : ȸ���ϸ� 1���� ���� ���� ����

	�׷��� ������, cctv�� c�����, 
	step 1 : cctv�� ������ �� �ִ� ������ ����� �� (cctv�� ����� ��) : �ִ� O(4^c) �����̴�. 
	���� ������ ���� ���� cctv ��ȣ�� ���� 1~4����������, �׳� ��� cctv�� 4���� ������ ���� �����ϴٶ�� �����ϰ� ó���ص� �ð����⵵���� ū ���̰� ���� �ʱ� ������,
	�����ϰ� �Ϲ�ȭ �ؼ� ������ ó���ϱ� ���� ��� ȸ���ϸ� 4���� ������ ���� �����ϴٰ� �����ϰ� ������ Ǯ�� �� ���̴�.
	
	step 2: 4^c ������ ������, �ѹ� cctv c���� ���� ������ ��� ������ �Ǹ�, �׶� ������ �簢������ ������ ������ O(n*m)�� �ð����⵵�� �ҿ�ȴ�.

	��, ��ü������ O((4^c) *(n*m)) �̰�, c,n,m <= 8 �̹Ƿ�, ���ѽð� ���� �����ϴ�.
	*/

	int n, m;
	cin >> n >> m;

	vector< vector<int> > v(n, vector<int>(m)); //�繫�� ���� �Է�
	vector< tuple<int, int, int> > cctv; //cctv�� ���� ����(1~5��, x,y)
	vector<int> rotate; //cctv�� ȸ���� �� Ƚ��(�ִ� 4ȸ)

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			if (v[i][j] != 0 && v[i][j] != 6) //cctv���
			{
				//emplace_back�� push_back�� ������ : push_back�� make_tuple�� ����ؼ� ��üȭ ���Ѽ� push �ؾ� ��. 
				//emplace_back�� �˾Ƽ� ��üȭ ������.�׷��Ƿ� ���ڵ鸸 ������ ��.
				//(��� cctv����, �� cctv�� x��, y��) �� ������� ����
				cctv.emplace_back(v[i][j],i,j); 
				//cctv.push_back(make_tuple(v[i][j], i, j)); 
				rotate.push_back(0); //���� �Է¹޾��� ���� �ѹ��� ȸ���� ���� �����̹Ƿ� 0 ����
			}
		}
	}
	
	int cctv_index = 0; //0��° cctv���� ���ʴ��!

	cout << find(v, cctv, cctv_index, rotate) << '\n';

	return 0;
}
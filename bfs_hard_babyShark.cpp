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

int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int n;

int isinside(int nx, int ny)
{
	if (nx >= 0 && nx < n && ny >= 0 && ny < n)
		return 1;
	else
		return 0;
}

tuple<int, int, int> bfs(int current_x, int current_y, vector< vector<int> > v, int current_size)
{
	//current_x��, current_y��(������ġ) ����, �������� ������ ������ ��, ������ �̵��� ������ ������ ��ġ�� ã�� �Լ��̴�.

	int n = v.size();
	queue< pair<int, int> > q;
	vector< vector<int> > d(n, vector<int>(n, -1)); //n * n ���. ��� ���Ҵ� -1�� �ʱ�ȭ��Ų��. �Ÿ��� ���� �����ϴ� �迭
	vector< tuple<int, int, int> > eating;

	q.push(make_pair(current_x, current_y));
	d[current_x][current_y] = 0;

	while (!q.empty()) //n*n �迭���� Ž�� ������ ��� ���� �� ���ƴٴϱ�!
	{
		int x, y;
		tie(x, y) = q.front();

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			//int nx = x + dir[i][0];
			//int ny = y + dir[i][1];

			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			// nx�� ny�� ���Ұ� �迭 �ȿ� �ְ�, �ѹ��� �湮���� �ʾ��� ��(visited �迭 ���, d[nx][ny] == -1 ���� �湮ó���� �����)
			// d�迭�� ó���� -1�� �ʱ�ȭ�����Ƿ�, d[nx][ny] == -1 �̶�°� ���� �� ���� �ѹ��� �� �� ���ٴ� �ǹ��̴�.
			if (isinside(nx, ny) && d[nx][ny] == -1)
			{
				bool eat = false;
				bool move = false;

				// ������ �ϴ� �ڸ��� ��ĭ�̸�(0) , �׳� �̵��� ���� (����Ⱑ ������ ���� �� ����)
				if (v[nx][ny] == 0) //���� : �� ������ �������� ���� �ȵǴ� ����???
					move = true;

				//�Ʊ����� ũ��� ������ �ϴ� �ڸ��� ������� ũ�Ⱑ ������, ���� �� ����, �̵��� ����.
				else if (v[nx][ny] == current_size)
					move = true;
				//�� ������ ������ �ϴ� �ĺ� �ڸ�(nx�� ny��)�� ������� ũ�Ⱑ v[nx][ny]�ε�, ���� �Ʊ����� ũ��(current_size)�� �� ũ�� ���� �� �ְ�, �̵��� �����ϴ�.
				else if (v[nx][ny] < current_size)
					move = eat = true;


				if (move)// �̵� �����ϸ�
				{
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
					if (eat) //�̵� �����ϰ�, ���� ���� ������,
					{
						eating.push_back(make_tuple(d[nx][ny], nx, ny)); //������ ���� �� ���(�� �����̴� ����)�� ������ �����صд�)
					}
				}

			}
		}
	}
	// eating ���Ͱ� ����ٴ� �ǹ̴�, �� �ڸ����� �� �� �ִ� ��� ���� bfs�� Ž���ߴµ��� �ұ��ϰ�, ���� �� �ִ� ����Ⱑ ���ٴ� �ǹ��̹Ƿ�,
	// �̶��� ���� �۾��� ������ ���� ���� ���� �Ѵٴ� �ǹ��̹Ƿ�, �� �ǹ̸� �������־�� ��!
	if (eating.empty())
	{
		return make_tuple(-1, -1, -1);
	}
	else
	{
		/*
		���� ���� �� �ִ� ����Ⱑ ���� �����϶�, �켱������ ������ �ϴµ�,
		������ ���� 1������ �Ÿ�(�ּ�), 2������ ��(����), 3������ ��(����)�̴�.
		������ �ϸ�, �Ÿ��� �������� ���������� �ǰ�, �Ÿ��� ������ ���� ��������(���� �ִ� ������ϼ���), �൵ ������ ���� ��������(���ʿ� �ִ� ������ϼ���) > �� �������� ������ �ȴ�.
		�� eating[0]�� 3���� �켱������ ��� ������� ��, ���� �� �ִ� �������� �ĺ� �� �߿� ���� ������ ������̴�. �Ʊ���� �� ������ �̵��� �ؾ��Ѵ�.
		*/
		sort(eating.begin(), eating.end());
		/*
		- tuple ��¹� ���! v[2]�� 2��° ���� ��� �ϰ� ������ : get<2>(v[2]) ��� �ϸ� �ȴ�!
		for (int i = 0; i < eating.size(); i++)
			cout << get<0>(eating[i]) << ' ' << get<1>(eating[i]) << ' ' << get<2>(eating[i]) << ' ' << '\n';
			*/
		return eating[0];
	}
}
int main()
{
	/*
	�ϴ� n^2 * n^2 ��, ������ 2����� ������ �Ѵ�.
	���� ��ġ���� ���� ������ �� ã�� �κ�(bfs(shark_x, shark_y, v, shark_size) �Լ��� ���. �̰Ŵ� �ִ� n^2 �ð��� �ɸ�. �־��� ��� �迭�� ��� ���Ҹ� �� �������� �ϴ� ��쵵 �����ϱ�)
	�׸��� ��� ��ġ��ġ���� �� ��츦 ������ �ϴϱ�(main�Լ��� while������ ���), �װ͵� �־��� ��� n^2��ŭ �ɸ���.
	�� n^2 * n^2 = O(n^4)��ŭ�� �ð����⵵�� �ҿ�ȴ�!
	*/

	// ���� 16236�� : �Ʊ��� (bfs ��ȭ + vector< tuple<int, int, int> > �� ���� ��� ��� ����!!!)
	F_I;
	//int n;
	cin >> n;
	vector< vector<int> > v(n, vector<int>(n)); //�Է¹޴� �迭. 
	//vector<int> �ڷ����� ��� �ִ� ���� n���� �����ǵ�, �� ���ҵ��� ���� int���� n���� ���Ҹ� ������ �ִٴ� �ǹ�
	//�ٽ� ���� n * n 2���� �迭�� �����ϴ� �Ͱ� ���� �ǹ��̴�.

	int shark_x, shark_y; //����� ��ġ�� ���. 

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == 9) //�� ó�� ����� ��ġ�� �߰�������,
			{
				shark_x = i; //����ϱ� (x ��ǥ)
				shark_y = j; //����ϱ� (y ��ǥ)
				v[i][j] = 0; //����� ��ġ�� ��������� �׳� ��ĭ ��� �ص� �ȴ�.
			}
		}
	}


	int shark_size = 2; //ó�� �Ʊ� ����� ũ��� 2�̴�.
	int exp = 0; //����ġ. ����⸦ ���� ������ exp�� 1�� �����ϸ�, exp�� shark_size�� ��������, shark_size�� 1 �����ϰ�, exp�� 0���� �ʱ�ȭ
	int final_dist = 0; //���� ��. �� ������ ���

	while (true)
	{
		int local_dist, local_nx, local_ny;
		tie(local_dist, local_nx, local_ny) = bfs(shark_x, shark_y, v, shark_size); //bfs�� ���� �Ʊ����� ��ġ�� ����� ����, �� �������� �������� �ϴ� ������ ������ ��ȯ�ϴ� �Լ��̴�.

		if (local_dist == -1)//���� ��ġ���� Ž���� ���� ��, � ������ ������ �� �̻� ���� �� �ִ� ����Ⱑ ���� ��, tuple<-1,-1,-1>�� ��ȯ�ϹǷ�!
		{
			cout << final_dist << '\n';
			return 0;
		}
		v[local_nx][local_ny] = 0; //����⸦ ������, �� �ڸ��� ��ĭ�� �ȴٰ� �������� �����

		/*
		������ ��θ�ŭ �����ֱ�. ���� ��� ������ ���� ��ҷ� ������ 2��ŭ�� �ʿ��ϸ� local_dist���� 2�� ��ȯ��.
		�� 2�� final_dist �� �����ֱ�
		*/
		final_dist += local_dist;

		exp += 1; //����ġ + 1 ���ְ�(����� �Ծ����ϱ�)

		//����ġ�� �Ʊ��� ũ��� ���� ������ �Ʊ����� ũ�⸦ 1 ������Ų�ٰ� �������� ��������Ƿ�(����� 1���� ���������� �Ʊ����� ����� 1�� �����ϴ� �� �ƴϴ�.)
		if (exp == shark_size)
		{
			shark_size += 1;
			exp = 0;
		}
		shark_x = local_nx;
		shark_y = local_ny;
	}

	return 0;
}
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

bool visited[1000005];

int main()
{
	F_I;

	//���� 9935�� : ���ڿ� ����

	//step 1. ���ڿ��� a, ���� ���ڿ��� b��� ���� ��, a�� ���ڵ��� �ϳ��� ���찡��, �� ���ڰ� ���� ���ڿ��� ���ϴ��� �ƴ����� �Ǵ��Ѵ�. (���� idea)
	//step 2. ���� a[i]�� ���ڰ� ���� ���ڿ��� ù��° ���ڿ� ���ٸ�, �� ���ڴ� ���� ���ڿ��� �������� �� '���ɼ�' �� �����ϴ� �����̹Ƿ�,
	//			stack�� �־���´�. ( i�� 0(���� ���ڿ��� ù��° ����)��). 
	//step 3. ���� a[i]�� ���� ���ڿ��� ù��° ���ڿ� ���� �ʴٸ�,
	//			�� a[i] ���ڰ� ���� ���ڿ��� ù��° ���ڴ� �ƴ�����, ���� ���ڿ��� �����ִ� ���� �����ϼ��� �ִ�. 
	//			�׷��Ƿ� ������ �־��� ������ ���� ���� ���ڸ� ������, �� ������ ���� ���ڿ� a[i]�� ������ ���Ѵ�.
	//			���� ���ٸ�, ���� ���ڿ��� ���ӵǴ� �����̹Ƿ� �� ��쵵 stack�� �̾ �ִ´� (i�� stack�� �� ������ ���� ���ڿ��� ��ġ+1 ��)
	//step 4 . �׷��� �ϴٰ�, ���� ���ڿ��� �� �������� ��ġ�� ���ڰ� stack�� �־����� ����, �� ���ڿ��� �ش��ϴ� ��ŭ�� ������ �ϹǷ�,
	//			�׸�ŭ stack���� pop�ؼ� ������, visited[�ű⿡ �ش�Ǵ� ���ڿ� a�� index]�� true�� �ٲ��.
	//step 5 . ���߿�, visited �迭���� false�� �κи� ����ϸ� �ȴ�.


	/*
	e.g.) => ���� �׸��� �׷����鼭 ���� ���ذ� ����!

			a = abaabcbcd  
			
			b = abc �϶�

		 => a[0]==b[0]�̹Ƿ�, (0,0)�� ���ÿ� push => a[1]!=b[0] �̰�, ���ÿ� �ִ� (0,0)�� ������ a[1] == b[0 +1]�̹Ƿ�, (1,0+1)�� ���ÿ� push
		 => a[2]==b[0]�̹Ƿ�, (2,0)�� ���ÿ� push => a[3]==b[0]�̹Ƿ�, (3,0)�� ���ÿ� push => 
		 => a[4]!=b[0] �̰�, ���ÿ� �ִ� (3,0)�� ������ a[4] == b[0 +1]�̹Ƿ�, (4,0 +1)�� ���ÿ� push
		 => a[5]!=b[0] �̰�, ���ÿ� �ִ� (4, 0+1)�� ������ a[5] == b[0+1 +1]�̹Ƿ�, (5, 0+1 +1)�� ���ÿ� push
		 => �̶� 0+1 +1 == m-1�̹Ƿ�, ���ÿ� ����ִ� �ֱ� ���� m���� ������.  
		 ...
		 ( �� ���� ��� �ݺ� )
		 ...
	*/

	string a, b;
	cin >> a >> b;
	int n = a.length();
	int m = b.length();

	if (m == 1) //���� ���ڿ��� ���̰� 1�� ��� -> ���ڿ����� �� ���� ���ڿ��� �ش��ϴ� ���ڸ� ���� ��� �ϸ� ��!
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] == b[0])
				visited[i] = true;
		}
	}
	else
	{
		stack<pi> v;
		for (int i = 0; i < n; i++)
		{
			if (b[0] == a[i]) //step 2
			{
				v.push(make_pair(i, 0));
			}
			else //step 3
			{
				if (!v.empty())
				{
					int x = v.top().second;
					if (a[i] == b[x + 1])
					{
						v.push(make_pair(i, x + 1));
						if (x + 1 == m - 1)//step 4
						{
							for (int i = 0; i < m; i++)
							{
								visited[v.top().first] = true;
								v.pop();
							}
						}
					}
					else
					{
						while (!v.empty())
							v.pop();
					}
				}
				
			}
		}
	}
	bool flag = false;

	for (int i = 0; i < n; i++) //step 5. 
	{
		if (!visited[i])
		{
			cout << a[i];
			flag = true;
		}
	}

	/*flag = false��� ����, ��� i�� ���ؼ� visited[i]�� �׻� true���ٴ� �ǹ��̹Ƿ�, �Է¹��� ���ڿ� a �� ��� �����ߴٴ� �ǹ��̹Ƿ�, 
	�����ִ� ���ڰ� ���� ����̴�.*/
	if (!flag)
		cout << "FRULA" << '\n';

	return 0;

}
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

typedef struct info
{
	int num;
	int op; 
	//op : 0 (��, �ǿ�����), op : 1 (+, ������), op : 2 (-, ������), op : 3 (*, ������)
	//op: -1 (�� �κ��� ������� ���� �ǳʶ� ��!)

} Info;

int main()
{
	//[����] 16638�� : ��ȣ �߰��ϱ� 2

	//������ 16637�� : ��ȣ �߰��ϱ� ������ �ſ� ���������, ��ȣ�� ģ �κ��� ���� ����ϵ�, �� �κ��� �����ڸ� -1 ó�������ν�, 
	//���߿� ���� ��� �Ҷ��� ��ŵ�ϰ�, * �κ��� ���������� �ٷιٷ� ����ؼ� ans �迭�� �ִ´ٴ� �������� �����Ѵ�.

	int n;
	cin >> n;
	vector<Info> arr(n);

	string st;
	cin >> st;

	//Info �迭�� �Է¹��� ���� ����!
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			arr[i].num = st[i]-'0';
			arr[i].op = 0;
		}
		else
		{
			arr[i].num = 0;
			if (st[i] == '+')
				arr[i].op = 1;
			else if (st[i] == '-')
				arr[i].op = 2;
			else if (st[i] == '*')
				arr[i].op = 3;
		}
	}

	int real = -1;
	int m = (n - 1) / 2;

	for (int i = 0; i < (1 << m); i++) //��ȣ ĥ �κп� ���� ��� ����� ��
	{
		/*
		e.g.) i= 0101 �� ��, (�����ʿ��� 0��° �����ڿ� 2��° �����ڰ� 1�̶�� �ǹ̴�, 0��° �����ڰ� ������ �ִ� �κа� 2��° �����ڰ� ������ �ִ� �κ���
		��ȣ ġ�ڴٴ� �ǹ��̴�.

		i = 0101 �̰�, �Է¹��� ������ 2 + 3 * 4 - 5 + 2 ���, (2 + 3) * (4 - 5) + 2 �� �ϰڴٴ� �ǹ��̴�!

		*/
		bool flag = false;
		for (int j = 0; j < m - 1; j++)
		{
			//j��° �����ڿ� j+1 ��° �����ڰ� ���������� ��ȣ�� ������ �ȵȴ�.
			//�����ڰ� ���������� ��ȣ�� ������ > e.g.) (1+(3*4)) , (1+3+2) >> �̷��� �ȵȴٴ� �ǹ�! ���� ������ �������� ����.

			//���õ� i�� ���ؼ�, �ѹ��̶� ������ �Ǿ��ٸ� flag�� true�� �ٲ��, �� ���Ŀ� ���ӵǴ� ���� ���� �ϴ���, �̹� �ѹ� ������ �Ǿ��ٴ� ����� ���������Ƿ�, 
			//if������ flag�� true�� �ٲٰ� break���� �������ν� �ٷ� �� �κ��� Ż�� �ϴ� �ڵ�� �ʿ䰡 ����.

			/*
			e.g.)
			i= 0011  �� ��,  

			j=0 �϶���, (1<<0) �� (1<<1) �� i�� & ������ ���� �� �Ѵ� 0 �� �ƴ� ���� �����Ƿ�, if�� ������ ���Ƿ�, flag�� true�� �ٲ��,
			j=1 �϶��� ������ ���� �����Ƿ�, if�� �ȿ� ������ ���ϰ�,
			j=2 �϶��� ���������̴�. 

			- ��, �ѹ��̶� i�� ���ӵǴ� �κ��� �����Ѵٸ�, flag�� true�� �ٲ��, �� ���Ŀ� ���ӵǴ� �κ��� ���� �ϴ��� flag�� ���� �ٽ� false�� �ٲ����� �ʴ´�.
			�ֳ��ϸ� ���ӵǴ� �κ��� ���� ��쿡�� ���� if���� ���ʿ� ������ ���ϴϱ�!
			*/
			if (  ((i & (1 << j)) != 0) && ((i & (1 << (j + 1))) != 0)) //�����̶��,
			{
				flag = true;
			}
		}

		if (flag == true)
			continue;

		vector<Info> copy(arr);

		for (int j = 0; j < m; j++)
		{
			if ((i & (1 << j)) != 0)
			{
				int k = 2 * j + 1;
				if (copy[k].op == 1) // +
				{
					copy[k - 1].num += copy[k + 1].num;
					copy[k].op = -1; // op: -1�� ������� ���� �ǳʶٶ�� �ǹ�.
					copy[k + 1].num = 0;
				}
				else if (copy[k].op == 2) // -
				{
					copy[k - 1].num -= copy[k + 1].num;
					copy[k].op = -1;
					copy[k + 1].num = 0;
				}
				else if (copy[k].op == 3) // *
				{
					copy[k - 1].num *= copy[k + 1].num;
					copy[k].op = -1;
					copy[k + 1].num = 0;
				}
			}
		}

		vector<Info> ans;
	
		for (int j = 0; j < n; j++)
		{
			/*
			e.g.)

			copy �迭������ -1�� ?�� �Ѵٸ�,

			- copy  : 3 + 4 ? 0 * 2 + 1 �϶�,
			- ans �迭�� step!

			 step1) copy�� idx 0�� Ž�� ���϶� > 3�̴ϱ� ����
			 ���� ans ��Ȳ : 3 

			 step2) copy�� idx 1,2�� ������� Ž�� ���϶� > ���� +, 4 �ϱ� ���� ������� ����
			 ���� ans ��Ȳ : 3 + 4 

			 step3) copy�� idx 3�� Ž�� ���϶� > ? �ϱ� idx+=1 �ϱ�, idx�� 4�� ��Ȳ���� for �ݺ����� ���� �ڿ������� idx�� �� 1 ����! idx�� 5�� ��!
			 ���� ans ��Ȳ : 3 + 4 

			 step4) copy�� idx 5�� Ž�� ���϶� > * �ϱ� ans �� ���� �ֱ� ������ 4�� ������, �װͰ� 2�� ���ؼ� 4�� �ִ� �ڸ��� �ְ�, idx+=1 �ϱ�,
			 idx�� 6�� ��Ȳ���� for �ݺ����� ���� �ڿ������� idx�� �� 1 ����! idx�� 7�� ��!
			 ���� ans ��Ȳ : 3 + 8 

			 step5) copy�� idx 7,8�� ������� Ž�� ���϶� > ���� +, 1 �̴ϱ� ���� ������� ����
			 ���� ans ��Ȳ : 3 + 8 + 1

			*/
			if (copy[j].op == 0) //���ڸ��� 
			{
				ans.push_back(copy[j]);
			}
			if (copy[j].op == -1) //-1�̸� ans �迭�� ���� ���� �׳� skip
			{
				j += 1;
			}
			if (copy[j].op == 1) // + ����
			{
				ans.push_back(copy[j]);
			}
			if (copy[j].op == 2) // - ����
			{
				ans.push_back(copy[j]);
			}
			if (copy[j].op == 3) // * ����
			{
				int aa = ans.back().num;
				aa *= copy[j + 1].num;
				ans.pop_back();
				ans.push_back({ aa, 0 });
				j += 1;
			}
		}

		int res = ans[0].num;
	
		int m2 = (ans.size() - 1) / 2;

		for (int j = 0; j < m2; j++)
		{
			int k = 2 * j + 1;
			if (ans[k].op == 1)
				res += ans[k + 1].num;
			if (ans[k].op == 2)
				res -= ans[k + 1].num;
		}

		if (real == -1 || real < res)
		{
			real = res;
		}
	}

	cout << real << '\n';

	return 0;
}
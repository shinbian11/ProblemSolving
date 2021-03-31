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

//	[����] 1406�� : ������ (�ڷᱸ�� - ����)
//	Ŀ���� �������� ���� ���ð� ������ �������� ���ε��� �����Ѵ�.

stack<char> LS; //���� ����
stack<char> RS; //������ ����

int main()
{
	F_I;
	
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		LS.push(s[i]); //�� ó�� �Է� ���� ���ڿ��� ���� ����(LS)�� �ִ´�.
	int n;
	char c, ob;
	cin >> n;
	while (n--)
	{
		cin >> c;
		if (c == 'P') //���� ����(LS)�� �ִ´�.
		{
			cin >> ob;
			LS.push(ob);
		}
		else if (c == 'L') //Ŀ���� �������� ��ĭ �ű� -> LS�� �ִ� �� ���� ���Ҹ� RS�� �ű��.
		{
			if (!LS.empty())
			{
				c = LS.top();
				LS.pop();
				RS.push(c);
			}
		}
		else if (c == 'D') //Ŀ���� ���������� ��ĭ �ű� -> RS�� �ִ� �� ���� ���Ҹ� LS�� �ű��.
		{
			if (!RS.empty())
			{
				c = RS.top();
				RS.pop();
				LS.push(c);
			}
		}
		else if (c == 'B') //Ŀ�� ���ʿ� �ִ� ���ڸ� ������ -> LS�� �ִ� �� ���� ���Ҹ� �׳� �����Ѵ� (pop)
		{
			if (!LS.empty())
			{
				LS.pop();
			}
		}
	}

	vector<char> LV;
	while (!LS.empty()) //LS�� ���ÿ� ����ִ� ���� ������ �Ųٷ� ���
	{
		LV.push_back(LS.top());
		LS.pop();
	}
	reverse(LV.begin(), LV.end());
	for (int i = 0; i < LV.size(); i++)
		cout << LV[i];
	while (!RS.empty()) //RS�� ���ÿ� ����ִ� ���� ���� �״�� ���
	{
		cout << RS.top();
		RS.pop();
	}

	return 0;
}
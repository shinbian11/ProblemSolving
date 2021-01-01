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
	string name;
	int kor, eng, math;

} Info;


bool cmp(Info& a, Info& b)
{
	//���� �켱����
	/*
	-���� ������ �����ϴ� ������
	-���� ������ ������ ���� ������ �����ϴ� ������
	-���� ������ ���� ������ ������ ���� ������ �����ϴ� ������
	-��� ������ ������ �̸��� ���� ������ �����ϴ� ������ (��, �ƽ�Ű �ڵ忡�� �빮�ڴ� �ҹ��ں��� �����Ƿ� ���������� �տ� �´�.)
	*/

	if (a.kor > b.kor) //����
		return true;
	else if (a.kor < b.kor)
		return false;
	else
	{
		if (a.eng < b.eng)//����
			return true;
		else if (a.eng > b.eng)
			return false;
		else
		{
			if (a.math > b.math)//����
				return true;
			else if (a.math < b.math)
				return false;
			else
			{
				if (a.name < b.name)//�̸�
					return true;
				else
					return false;
			}
		}
	}
}

int main()
{
	F_I;

	//���� 10825�� ������ : ���� �ؾ��ϴ� field �� �������̰�, ������ field �� ���� ���� ������ ��� �ٸ���! cmp ����� ���� �Լ� �̿�!
	int n;
	cin >> n;
	vector<Info> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << v[i].name << '\n';

	return 0;
}
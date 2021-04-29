#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

bool IsInside(int x, int y)
{
	if (x >= -5 && x <= 5 && y >= -5 && y <= 5) return true;
	else return false;
}

int solution(string dirs)
{
	// �� ���� üũ�ϴ� ����. (�����)�� (������)�� ��� �湮�� ���� �ִ� ��츸 üũ���� �����ؾ� �Ѵ�. (�̸� ���ݴ� ���� �߿�!!)
	// �ٵ� �� �� ��� ������ ������ �� ����(x,y)�̹Ƿ�, �� ���� ��� üũ�Ϸ��� 4���� ������ ������ üũ�ؾ� �ϴµ�, �̴� �ſ� �����ϴ�.
	// �� �� ���ϰ� ���ϱ� ���ؼ�, (�����)�� (x,y)������ (������)�� (x,y)������ �ϳ��� ���ڷ� ����������. (������ ����!!)
	// ���⼭�� x�� 100�� ���ؼ� y�� ���� ����� ���ߴ�. �̷��� �ϳ��� �ؽ���(?) ǥ�Ⱚ(?) �� ����� �� ������ �����̴�.
	// set�� ������� ���� �������� ���� �̹� ����Ǿ� �ִ� ��찡 �ƴ϶�� set�� �־��ش�.
	// ���������� set�� ũ�Ⱑ ������ �����ϹǷ�, set�� size�� ��ȯ�Ѵ�.
	// �迭�� �����ؼ� ������ ���� true �� ǥ���ϴ� ����� ������, ���� �迭�� ������ �ʿ䵵 ����, �̷� ����� ����ϸ� �ȴ�.
	

	//������ ����
	int x = 0;
	int y = 0;

	int nx = x;
	int ny = y;

	set<pi> v;
	for (int i = 0; i < dirs.length(); i++)
	{
		
		if (dirs[i] == 'U')
		{
			nx = x - 1;
			ny = y;
		}
		else if (dirs[i] == 'D')
		{
			nx = x + 1;
			ny = y;
		}
		else if (dirs[i] == 'R')
		{
			nx = x;
			ny = y + 1;
		}
		else if (dirs[i] == 'L')
		{
			nx = x;
			ny = y - 1;
		}

		if (!IsInside(nx, ny)) continue; //���� üũ
		
		int a = x * 100 + y;
		int b = nx * 100 + ny;

		//�̵��� ���Ѿ� ��.
		x = nx;
		y = ny;

		//set�� �ߺ� üũ
		if (v.find({ a,b }) == v.end() && v.find({ b,a }) == v.end())
			v.insert({ a,b });
	}
	
	return v.size();
}

int main()
{
	F_I;

    string dirs = "LULLLLLLU";
    cout<< solution(dirs);
	
	return 0;
}

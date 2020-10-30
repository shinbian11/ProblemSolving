//c++

//qsort ���� : qsort(�����ҹ迭, ��Ұ���, ���ũ��, ���Լ�); / qsort(�����Ҹ޸��ּ�, ��Ұ���, ���ũ��, ���Լ�);
// void qsort(void* _Base, size_t _NumOfElements, size_t _SizeOfElements, int (*_PtFuncCompare)(void const*, void const*));
#include <bits/stdc++.h>
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

typedef struct point
{
	int x, y;
} point;

int cmp(void const* a, void const* b) //qsort �⺻ ���� ������ const�� �ݵ�� ��� ��!
{
	point* p1 = (point*)a;
	point* p2 = (point*)b;
	if (p1->x < p2->x)
		return -1;
	else if (p1->x > p2->x)
		return 1;
	else
	{
		if (p1->y < p2->y)
			return -1;
		else if (p1->y > p2->y)
			return 1;
	}
}

int main()
{
	F_I;
	int n;
	cin >> n;
	vector<point> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].x >> v[i].y;
	}
	qsort(&v[0], n, sizeof(v[0]), cmp);
	for (int i = 0; i < n; i++)
	{
		cout << v[i].x << " " << v[i].y << '\n';
	}
	return 0;
}
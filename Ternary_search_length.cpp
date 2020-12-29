#include <bits/stdc++.h>

// F_I ����ϸ� cin �� scanf �� ��� ���� �ȵȴ�!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //�ִ�����
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //�ּҰ����

double length(double x1, double y1, double z1, double x2, double y2, double z2)
{
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
}
int main()
{
	F_I;

	//���� 11664�� ���а� �� : ���Ž�� ���� or ������ ������ ���ؼ� ������ ����
	// �̺� Ž�� : yes/no �� ���� ��
	// ��� Ž��: �����Լ��� ��翡�� �ִ밪, �ּڰ� ã�� ��
	double a_x, a_y, a_z;
	double b_x, b_y, b_z;
	double c_x, c_y, c_z;
	cin >> a_x >> a_y >> a_z >> b_x >> b_y >> b_z >> c_x >> c_y >> c_z;
	double dx = b_x - a_x;
	double dy = b_y - a_y;
	double dz = b_z - a_z;
	double start = 0.0;
	double end = 1.0;
	//double mid = 0;
	//while(true)
	//{
	//	if (abs(end - start) < 1e-9)
	//	{
	//		mid = (start + end) / 2;
	//		break;
	//	}
	for (int i = 0; i < 10000; i++) //10000�� ���� �ݺ��ϸ� ���е� ���� �� ��ġ�Ѵ�.
	{

		double m1 = start + (end - start) / 3;
		double m2 = end - (end - start) / 3;

		double m1x = a_x + m1 * dx;
		double m1y = a_y + m1 * dy;
		double m1z = a_z + m1 * dz;

		double m2x = a_x + m2 * dx;
		double m2y = a_y + m2 * dy;
		double m2z = a_z + m2 * dz;
		if (length(m1x, m1y, m1z, c_x, c_y, c_z) > length(m2x, m2y, m2z, c_x, c_y, c_z))
			start = m1;
		else
			end = m2;
	}
	
	double mid = (start + end) / 2;

	double mx = a_x + mid * dx;
	double my = a_y + mid * dy;
	double mz = a_z + mid * dz;

	double ans = length(mx, my, mz, c_x, c_y, c_z);
	cout << fixed << setprecision(10) << ans << '\n';
	return 0;
}
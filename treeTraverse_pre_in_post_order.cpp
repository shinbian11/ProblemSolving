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

int inorder[100001];
int postorder[100001];
int pos[100001]; //pos[i] = i��° ������ inorder ������ ���° index�� �ִ����� ����!

//���� 2263�� Ʈ���� ��ȸ

void solve(int in_s, int in_e, int post_s, int post_e)
{
	if (in_s > in_e || post_s > post_e) //��������
		return;

	int root = postorder[post_e]; //postorder�� �� ������ ���Ұ� root �̴�.
	cout << root << ' ';
	
	int r_p = pos[root]; //postorder ������ root�� inorder ������ ��� ��ġ�� �ִ����� ���� index�� ��ȯ! �� r_p�� inorder ������ root ��ġ ��ȯ.
	int left = r_p - in_s; //inorder ���� root ���� ������ left, �������� right�̴�.
	
	solve(in_s, r_p - 1, post_s, post_s + left - 1); //left �� ���� ���
	solve(r_p + 1, in_e, post_s + left, post_e - 1);//right �� ���� ���
}
int main() 
{
	F_I;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> inorder[i];
	for (int i = 0; i < n; i++)
		cin >> postorder[i];
	for (int i = 0; i < n; i++) 
		pos[inorder[i]] = i;  //pos[i] = i��° ������ inorder ������ ���° index�� �ִ����� ����!

	solve(0, n - 1, 0, n - 1);

	return 0;

}
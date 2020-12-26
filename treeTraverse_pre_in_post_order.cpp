#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int inorder[100001];
int postorder[100001];
int pos[100001]; //pos[i] = i번째 정점이 inorder 에서는 몇번째 index에 있는지를 저장!

//백준 2263번 트리의 순회

void solve(int in_s, int in_e, int post_s, int post_e)
{
	if (in_s > in_e || post_s > post_e) //종료조건
		return;

	int root = postorder[post_e]; //postorder의 맨 마지막 원소가 root 이다.
	cout << root << ' ';
	
	int r_p = pos[root]; //postorder 에서의 root는 inorder 에서는 어디에 위치해 있는지에 대한 index를 반환! 즉 r_p는 inorder 에서의 root 위치 반환.
	int left = r_p - in_s; //inorder 에서 root 기준 왼쪽이 left, 오른쪽이 right이다.
	
	solve(in_s, r_p - 1, post_s, post_s + left - 1); //left 에 관한 재귀
	solve(r_p + 1, in_e, post_s + left, post_e - 1);//right 에 관한 재귀
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
		pos[inorder[i]] = i;  //pos[i] = i번째 정점이 inorder 에서는 몇번째 index에 있는지를 저장!

	solve(0, n - 1, 0, n - 1);

	return 0;

}
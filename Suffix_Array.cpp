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

int main()
{
	F_I;

	string str;
	cin >> str;
	vector<string> strArr;
	for (int i = 0; i < str.length(); i++) {
		strArr.push_back(str.substr(i)); //str.substr(i) : str�� i��° idx���� �������� ���ڿ��� slicing �ϰڴٴ� �ǹ�!
	}
	sort(strArr.begin(), strArr.end());
	for (int i = 0; i < str.length(); i++)
		cout << strArr[i] << '\n';

	return 0;
}
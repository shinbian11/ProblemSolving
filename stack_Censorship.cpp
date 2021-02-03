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

char l_st[300005];
char r_st[300005];

char word[35];
char reverse_word[35];

char text[300005];

int l_idx;
int r_idx;

int l_st_idx;
int r_st_idx;

int word_len, text_len;

bool check(bool flag) //���ÿ� ��� ������� word �� ��ġ�ϴ����� �Ǵ��ϴ� �Լ�
{
	char* st = l_st;
	int len = l_st_idx;
	char* w = reverse_word;

	if (flag == true)
	{
		st = r_st;
		len = r_st_idx;
		w = word;
	}

	if (len < word_len)
		return false;

	bool ff = true;
	for (int i = 0; i < word_len; i++)
	{
		if (st[len - i - 1] != w[i])
		{
			ff = false;
		}
	}

	if (ff == false)
		return false;
	else
	{
		if (flag == false)
			l_st_idx -= word_len;
		else
			r_st_idx -= word_len;
		return true;
	}
}

int main()
{
	//F_I;

	//[����] 3111�� : �˿� (����, ���ڿ�)

	scanf("%s", word);
	scanf("%s", text);

	word_len = strlen(word);
	text_len = strlen(text);

	for (int i = 0; i < word_len; i++)
	{
		reverse_word[i] = word[word_len - 1 - i];
	}

	//text������ �ε���
	l_idx = 0;
	r_idx = text_len - 1;

	//l,r_stack ������ �ε���
	l_st_idx = 0;
	r_st_idx = 0;

	bool flag = false; //flag�� false�̸� text�� ���ʺ��� �˻�, true�̸� �����ʺ��� �˻�

	while (l_idx <= r_idx)
	{
		if (flag == false)
		{
			l_st[l_st_idx++] = text[l_idx++];
		}
		else
		{
			r_st[r_st_idx++] = text[r_idx--];
		}
		if (check(flag)) //���ÿ��� �ش��ϴ� word�� ã���� ��, 
		{
			flag = !flag; //Ž�� ������ �ٲٱ� (��->�� or ��->��)
		}
	}

	/*
	text Ž���� ��� ���� ����(�˿��� ��� ���� ����), ���ÿ� �����ִ� ���ڿ��� ����ϱ� ����, 
	������ ���ÿ� �����ִ� ���빰�� ���� �������� ��� �ű��.
	�� ���� ���� ������ ������ ��� ����ϸ� ���� �ȴ�.
	*/
	
	for (int i = r_st_idx - 1; i >= 0; i--)
	{
		l_st[l_st_idx++] = r_st[i];
		check(false);
	}

	for (int i = 0; i < l_st_idx; i++)
		cout << l_st[i];

	cout << '\n';

	return 0;
}
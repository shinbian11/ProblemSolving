#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

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

bool check(bool flag) //스택에 담긴 내용들이 word 와 일치하는지를 판단하는 함수
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

	//[백준] 3111번 : 검열 (스택, 문자열)

	scanf("%s", word);
	scanf("%s", text);

	word_len = strlen(word);
	text_len = strlen(text);

	for (int i = 0; i < word_len; i++)
	{
		reverse_word[i] = word[word_len - 1 - i];
	}

	//text에서의 인덱스
	l_idx = 0;
	r_idx = text_len - 1;

	//l,r_stack 에서의 인덱스
	l_st_idx = 0;
	r_st_idx = 0;

	bool flag = false; //flag가 false이면 text의 왼쪽부터 검사, true이면 오른쪽부터 검사

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
		if (check(flag)) //스택에서 해당하는 word를 찾았을 때, 
		{
			flag = !flag; //탐색 방향을 바꾸기 (왼->오 or 오->왼)
		}
	}

	/*
	text 탐색을 모두 끝낸 이후(검열을 모두 끝낸 이후), 스택에 남아있는 문자열을 출력하기 위해, 
	오른쪽 스택에 남아있는 내용물을 왼쪽 스택으로 모두 옮긴다.
	그 이후 왼쪽 스택의 내용을 모두 출력하면 답이 된다.
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
#include <bits/stdc++.h>

// F_I 사용하면 cin 과 scanf 를 섞어서 쓰면 안된다!
#define F_I ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수


//프로그래머스 - 2021 KAKAO BLIND RECRUITMENT - 순위 검색

//데이터베이스를 관리하고 쿼리에 대해 응답하는 문제.
//꼭 반복해보기! 모르는 문제였다.
//참고 :  https://yjyoon-dev.github.io/kakao/2021/01/29/kakao-ranksearch/

vector<int> db[3][2][2][2];

vector<int> InfoSplit(string s) //Info 한 문장씩 받아와서 숫자로 변환하여 저장
{
	string tmp = "";
	vector<int> t;

	for (char c : s)
	{
		if (c == ' ')
		{
			if (tmp == "java" || tmp == "backend" || tmp == "junior" || tmp == "pizza")
				t.push_back(0);
			else if (tmp == "python" || tmp == "frontend" || tmp == "senior" || tmp == "chicken")
				t.push_back(1);
			else if (tmp == "cpp")
				t.push_back(2);
			tmp = "";
		}
		else
		{
			tmp += c;
		}
	}
	t.push_back(stoi(tmp)); //코테 점수

	return t;
}

vector<string> querySplit(string s)
{
	vector<string> ret;
	string tmp = "";

	for (char c : s)
	{		
		if (c == ' ')
		{
			ret.push_back(tmp);
			tmp = "";
		}
		else
			tmp += c;
	}
	ret.push_back(tmp);

	return ret;
}

vector<int> solution(vector<string> info, vector<string> query)
{
	vector<int> answer;

	//Info Split And Database
	for (string s : info)
	{
		vector<int> info = InfoSplit(s);
		
		//db[info[0]][info[1]][info[2]][info[3]] : (info[0],info[1],info[2],info[3])의 특성을 가진 벡터에 info[4]를 저장함(info[4]는 코테 점수)
		db[info[0]][info[1]][info[2]][info[3]].push_back(info[4]);
	}
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				for (int l = 0; l < 2; l++)
					sort(db[i][j][k][l].begin(), db[i][j][k][l].end()); //정렬 -> 코딩 테스트 점수에 대한 탐색이 필요하므로.
			}
		}
	}

	//querySplit
	for (string s : query)
	{
		vector<string> v = querySplit(s);
		int ai, bi, aj, bj, ak, bk, al, bl;
		
		//language classification
		if (v[0] == "java") ai = bi = 0;
		else if (v[0] == "python") ai = bi = 1;
		else if (v[0] == "cpp") ai = bi = 2;
		else { // '-'인 경우 >> 모든 범위에 대하여 okay!
			ai = 0;
			bi = 2;
		}

		//front/back clasification
		if (v[2] == "backend") aj = bj = 0;
		else if (v[2] == "frontend") aj = bj = 1;
		else { // '-'인 경우 >> 모든 범위에 대하여 okay!
			aj = 0;
			bj = 1;
		}

		//junior/senior clasification
		if (v[4] == "junior") ak = bk = 0;
		else if (v[4] == "senior") ak = bk = 1;
		else { // '-'인 경우 >> 모든 범위에 대하여 okay!
			ak = 0;
			bk= 1;
		}

		//food classification
		if (v[6] == "pizza") al = bl = 0;
		else if (v[6] == "chicken") al = bl = 1;
		else { // '-'인 경우 >> 모든 범위에 대하여 okay!
			al = 0;
			bl = 1;
		}

		int score = stoi(v[7]); //코테 점수

		int ans = 0;

		//설정한 범위들에 대하여, 그 조건에 해당하는 점수들 중 score 보다 큰 점수들의 개수만 모두 합하기!

		for (int a = ai; a <= bi; a++)
		{
			for (int b = aj; b <= bj; b++)
			{
				for (int c = ak; c <= bk; c++)
				{
					for (int d = al; d <= bl; d++)
					{
						int n = db[a][b][c][d].size();
						if (n == 0) continue; //조건에 해당하는 점수가 없다면 continue;

						auto it = lower_bound(db[a][b][c][d].begin(), db[a][b][c][d].end(), score); 
						if (it == db[a][b][c][d].end()) continue; //score와 같거나 큰 점수가 없으면 continue;
						
						ans += n - (it - db[a][b][c][d].begin()); //(a,b,c,d)의 조건을 만족하는 점수들 중에서 score보다 큰 점수의 개수

					}
				}
			}
		}
		answer.push_back(ans);
	}
	return answer;
}

int main()
{
	F_I;

	vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
	vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
	vector<int> answer = solution(info, query);
	for (int i : answer)
		cout << i << ' ';
	return 0;
}

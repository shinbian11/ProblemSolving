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

typedef struct sticker //��ƼĿ �������� (�ִ� 100��)
{
	int x, y;
} Sticker;

Sticker sticker[101];

int main()
{
	F_I;
	 /*
	 ���� 16937�� : �� ��ƼĿ
	 - �ð����⵵�� nC2(n���߿� ��ƼĿ 2�� ��)* 2*2(��ƼĿ �Ѱ��� 90�� ȸ���� �����ϹǷ� ����� �� �ΰ��� ����)* 2 (����/���� �� �̾���̴� ���)
	 - �ð����⵵�� ���� �ɸ��� �����Ƿ�, ���Ʈ ������ �̿��Ͽ� ��� ��ƼĿ���� 2���� ���鼭 �Ǵ� ��� �� ������ �ȴ�!
	 */

	int paper_x, paper_y; //�������� ũ�� �Է�
	cin >> paper_x >> paper_y;

	int n; //��ƼĿ�� ����
	cin >> n;

	for (int i = 0; i < n; i++) //��ƼĿ�� ũ�� �Է�
		cin >> sticker[i].x >> sticker[i].y;

	int r1, w1;//1��° ��ƼĿ
	int r2, w2;//2��° ��ƼĿ

	//���� ��� �� : ans
	int ans = 0; //��ƼĿ �� ���� ���� �� ���� ��쿡�� ans���� ������ ����� �ϴµ�, �׶� 0�� ����϶�� �������� ��������Ƿ� 0���� �ʱ�ȭ

	//�ٱ��� for�� 2�� : nC2
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++) 
		{
			r1 = sticker[i].x;
			w1 = sticker[i].y;

			r2 = sticker[j].x;
			w2 = sticker[j].y;
			
			//���� for�� 2�� : 2*2 (��ƼĿ 1���� ȸ�� 0ȸ & ȸ�� 1ȸ)
			for (int rot1 = 0; rot1 < 2; rot1++)
			{
				for (int rot2 = 0; rot2 < 2; rot2++)
				{
					//if�� �ΰ� : ���η� �̾���̰ų� ���η� �̾���̰ų�

					if (Max(r1, r2) <= paper_x && w1 + w2 <= paper_y) //���η� �̾���̴� ���
					{
						if (ans < r1 * w1 + r2 * w2)
							ans = r1 * w1 + r2 * w2;
					}

					//else if �� ����????
					if (Max(w1, w2) <= paper_y && r1 + r2 <= paper_x) //���η� �̾���̴� ���
					{
						if (ans < r1 * w1 + r2 * w2)
							ans = r1 * w1 + r2 * w2;
					}

					swap(r1, w1); //ù��° ��ƼĿ�� 90�� ȸ��
				}
				swap(r2, w2); //�ι�° ��ƼĿ�� 90�� ȸ��
			}
		
		}
	}

	cout << ans << '\n'; 

	return 0;
}
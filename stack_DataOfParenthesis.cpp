 #include <bits/stdc++.h>
// C
//#ifndef _GLIBCXX_NO_ASSERT
//#include <cassert>
//#endif
//#include <cctype>
//#include <cerrno>
//#include <cfloat>
//#include <ciso646>
//#include <climits>
//#include <clocale>
//#include <cmath>
//#include <csetjmp>
//#include <csignal>
//#include <cstdarg>
//#include <cstddef>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <ctime>
//
//#if __cplusplus >= 201103L
//#include <ccomplex>
//#include <cfenv>
//#include <cinttypes>
//#include <cstdalign>
//#include <cstdbool>
//#include <cstdint>
//#include <ctgmath>
//#include <cwchar>
//#include <cwctype>
//#endif
//
//// C++
//#include <algorithm>
//#include <bitset>
//#include <complex>
//#include <deque>
//#include <exception>
//#include <fstream>
//#include <functional>
//#include <iomanip>
//#include <ios>
//#include <iosfwd>
//#include <iostream>
//#include <istream>
//#include <iterator>
//#include <limits>
//#include <list>
//#include <locale>
//#include <map>
//#include <memory>
//#include <new>
//#include <numeric>
//#include <ostream>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <stdexcept>
//#include <streambuf>
//#include <string>
//#include <typeinfo>
//#include <utility>
//#include <valarray>
//#include <vector>
//
//#include <array>
//#include <atomic>
//#include <chrono>
//#include <condition_variable>
//#include <forward_list>
//#include <future>
//#include <initializer_list>
//#include <mutex>
//#include <random>
//#include <ratio>
//#include <regex>
//#include <scoped_allocator>
//#include <system_error>
//#include <thread>
//#include <tuple>
//#include <typeindex>
//#include <type_traits>
//#include <unordered_map>
//#include <unordered_set>

#define F_I ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); // F_I ��� �� ����) scanf�� printf ��� ����, ������ cin , cout �� ���!
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

    // F_I : ���� �� �ʼ�! ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); �ϱ��س���!
    F_I;

    // [����] 2504�� : ��ȣ�� �� (����, ��ȣ ����ġ��� ��ٷο�)

    // ������ url : https://jaimemin.tistory.com/820

    /*
    (()[[]])([]) => 2*(2+3*3) + 2*3

    �ݴ� ��ȣ�� ������ ��, �� ��ȣ�� �ٷ� ���� �ִ� ��ȣ�� �ݴ°���, �ƴ� �ָ� �ִ� ��ȣ�� �ݴ°��� �Ǵ��ؾ� �Ѵ�.
    () ����, ( ..... ) ���� �Ǵ��ؾ� �Ѵ�!

    ���� () ���, �̋����� ��ƿ� �� (���⼭�� energy�� ǥ��)��ŭ �����ְ�, 
    ���� ( ..... ) ���, �̹� ..... ��ŭ�� energy�� ���� �������� ���� ���� ����� �۾����� �������� ���̹Ƿ�, ���⼭�� ���ϴ� ������ �ʿ� ����.
    
    
    Example)

    (()[[]])([]) �� �������� ������ ��, ù���� �˸����� 2+3*3�� ��� ����ϰ�, 
    �� ���� �ٱ��ʿ� �ִ� �Ұ�ȣ�� �����鼭 ��ü �˸��̿��ٰ� 2�� ���ϴ� ������ �˰����� ¥�� ���� �ƴ϶�,

    2*2 �� ���ϰ�, 2*3*3�� ���ϰ�, 2*3�� ���ϰ� => �̷� ������ �����Ѵ�. (�й��Ģ ���ø��� ��)

    */
    string str;
    stack<char> s;
    int sum = 0;
    bool Wrong = false;
    cin >> str;
    int energy = 1;
    for (int i = 0; i < str.length(); i++) {
        
        if (str[i] == ')' && (s.empty() || s.top() != '(')) { // ����ó�� 1
            Wrong = true;
            break;
        }
        if (str[i] == ']' && (s.empty() || s.top() != '[')) { // ����ó�� 2
            Wrong = true;
            break;
        }

        if (str[i] == '(') {
            energy *= 2; // energy ������
            s.push('(');
        }
        if (str[i] == '[') {
            energy *= 3; // energy ������
            s.push('[');
        }
        if (str[i] == ')') {

            // �ٷ� ���� �ִ� ��ȣ�� �ݴ� ���� ��
            // i�� 0�϶��� ����ó���� �� �ʿ� ����. ��¥�� ����ó�� 1, 2���� �� �ɷ���
            if (str[i - 1] == '(') 
            {
                sum += energy;
            }

            // �ٷ� ���� �ִ� ��ȣ�� �ݴ� ���, �ָ� ������ ��ȣ�� �ݴ� ��� => ��� ���ÿ��� pop ��Ű�� energy �� ���ҽ�Ű�� �۾��� �����ϰ� �ʿ�!
            s.pop();
            energy /= 2;
        }
        if (str[i] == ']') {

            // �ٷ� ���� �ִ� ��ȣ�� �ݴ� ���� ��
            // i�� 0�϶��� ����ó���� �� �ʿ� ����. ��¥�� ����ó�� 1, 2���� �� �ɷ���
            if (str[i - 1] == '[') 
            {
                sum += energy;
            }

            // �ٷ� ���� �ִ� ��ȣ�� �ݴ� ���, �ָ� ������ ��ȣ�� �ݴ� ��� => ��� ���ÿ��� pop ��Ű�� energy �� ���ҽ�Ű�� �۾��� �����ϰ� �ʿ�!
            s.pop();
            energy /= 3;
        }
    }
    
    // ����ó�� 3 (��� �۾��� ������ �� stack�� ����־�� �Ѵ�! 
    // �� ó���� ���ٸ� (()[] �� 0�� �ƴ� �ٸ� ���� ���´�.
    int ans =  (Wrong || !s.empty()) ? 0 : sum;
    cout << ans << '\n';

    return 0;
}
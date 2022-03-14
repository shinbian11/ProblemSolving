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

#define F_I ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); // F_I 사용 시 주의) scanf와 printf 사용 금지, 오로지 cin , cout 만 사용!
#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;

ll Min(ll a, ll b) { return (a < b) ? a : b; }
ll Max(ll a, ll b) { return (a < b) ? b : a; }
ll gcd(ll m, ll n) { if (n == 0) return m; return gcd(n, m % n); } //최대공약수
ll lcm(ll m, ll n) { return m * n / gcd(m, n); } //최소공배수

int main()
{

    // F_I : 코테 때 필수! ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 암기해놓기!
    F_I;

    // [백준] 2504번 : 괄호의 값 (스택, 괄호 문제치고는 까다로움)

    // 참고한 url : https://jaimemin.tistory.com/820

    /*
    (()[[]])([]) => 2*(2+3*3) + 2*3

    닫는 괄호가 나왔을 때, 이 괄호가 바로 옆에 있는 괄호를 닫는건지, 아님 멀리 있는 괄호를 닫는건지 판단해야 한다.
    () 인지, ( ..... ) 인지 판단해야 한다!

    만약 () 라면, 이떄까지 모아온 값 (여기서는 energy라 표현)만큼 더해주고, 
    만약 ( ..... ) 라면, 이미 ..... 만큼의 energy는 위의 수식으로 인해 이전 어딘가의 작업에서 더해졌을 것이므로, 여기서는 더하는 연산이 필요 없다.
    
    
    Example)

    (()[[]])([]) 을 기준으로 보았을 때, 첫번쨰 알맹이인 2+3*3을 모두 계산하고, 
    그 이후 바깥쪽에 있는 소괄호를 닫으면서 전체 알맹이에다가 2를 곱하는 식으로 알고리즘을 짜는 것이 아니라,

    2*2 를 더하고, 2*3*3을 더하고, 2*3을 더하고 => 이런 식으로 전개한다. (분배법칙 떠올리면 됨)

    */
    string str;
    stack<char> s;
    int sum = 0;
    bool Wrong = false;
    cin >> str;
    int energy = 1;
    for (int i = 0; i < str.length(); i++) {
        
        if (str[i] == ')' && (s.empty() || s.top() != '(')) { // 예외처리 1
            Wrong = true;
            break;
        }
        if (str[i] == ']' && (s.empty() || s.top() != '[')) { // 예외처리 2
            Wrong = true;
            break;
        }

        if (str[i] == '(') {
            energy *= 2; // energy 모으기
            s.push('(');
        }
        if (str[i] == '[') {
            energy *= 3; // energy 모으기
            s.push('[');
        }
        if (str[i] == ')') {

            // 바로 옆에 있는 괄호를 닫는 것일 때
            // i가 0일때의 예외처리는 할 필요 없음. 어짜피 예외처리 1, 2에서 다 걸러짐
            if (str[i - 1] == '(') 
            {
                sum += energy;
            }

            // 바로 옆에 있는 괄호를 닫는 경우, 멀리 떨어진 괄호를 닫는 경우 => 모두 스택에서 pop 시키고 energy 를 감소시키는 작업은 동일하게 필요!
            s.pop();
            energy /= 2;
        }
        if (str[i] == ']') {

            // 바로 옆에 있는 괄호를 닫는 것일 때
            // i가 0일때의 예외처리는 할 필요 없음. 어짜피 예외처리 1, 2에서 다 걸러짐
            if (str[i - 1] == '[') 
            {
                sum += energy;
            }

            // 바로 옆에 있는 괄호를 닫는 경우, 멀리 떨어진 괄호를 닫는 경우 => 모두 스택에서 pop 시키고 energy 를 감소시키는 작업은 동일하게 필요!
            s.pop();
            energy /= 3;
        }
    }
    
    // 예외처리 3 (모든 작업이 끝났을 때 stack이 비어있어야 한다! 
    // 이 처리가 없다면 (()[] 도 0이 아닌 다른 값이 나온다.
    int ans =  (Wrong || !s.empty()) ? 0 : sum;
    cout << ans << '\n';

    return 0;
}
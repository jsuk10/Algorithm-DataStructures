#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstring>
#include <deque>
#include <stack>
#include <string>
#include <string_view>
#include <utility>

using namespace std;

// Runtime  : 0ms      100%
// Memory   : 10.6MB   25.28%

// 평가 함수 작성
string say(const string &s)
{
    string ans;
    for (int i = 0; i < (int)s.length(); i++)
    {
        int cnt = 1;
        for (int j = i + 1; j < (int)s.length(); j++, i++, cnt++)
        {
            if (s[i] != s[j])
                break;
        }
        ans += to_string(cnt) + s[i];
    }
    return ans;
}

// 템플릿 메타 프로그래밍 struct선언
template <int N>
struct CAS
{
    static const string string;
};

// 계산 로직
template <int N>
const string CAS<N>::string = say(CAS<N - 1>::string);

// 종료 로직 (끝점)
template <>
const string CAS<1>::string = "1";

class Solution
{
    static constexpr int MAX_N = 30;

    // 테이블 생성
    template <size_t... I>
    static const vector<const string *> &table_impl(index_sequence<I...>)
    {
        static const vector<const string *> t = {&CAS<int(I + 1)>::string...};
        return t;
    }

    string GetAnswer(int n)
    {
        return *table_impl(make_index_sequence<MAX_N>{})[n];
    }

public:
    string countAndSay(int n)
    {
        return GetAnswer(n - 1);
    }
};
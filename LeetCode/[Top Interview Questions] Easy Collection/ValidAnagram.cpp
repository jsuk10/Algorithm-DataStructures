#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0,};
        
        if (s.length() != t.length()) return false;

        for (auto a : s)
        {
            arr[a - 'a']++;
        }

        // ���ڿ� ���̰� �����Ƿ� �ٸ��� �ϳ��� ������ 0���� �����͵� ����
        for (auto a : t)
        {
            if (--arr[a - 'a'] < 0) return false;
        }

        return true;
    }
};
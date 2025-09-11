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
    bool isPalindrome(string s) {
        auto begin = s.begin();
        auto end = s.end();
        
        while (begin < end--)
        {
            while(begin <= end && !isalnum(*begin)) begin++; 
            while(begin <= end && !isalnum(*end)) end--;
            if (begin >= end) break;
            
            if (tolower(*begin++) != tolower(*end)) return false;
        }

        return true;
    }
};
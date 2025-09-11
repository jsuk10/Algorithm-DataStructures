#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        vector<int>& minvector = (nums1.size() >= nums2.size()) ? nums2 : nums1;
        vector<int>& maxvector = (nums1.size() < nums2.size()) ? nums2 : nums1;

        for (int i = 0 ; i < minvector.size() ; i++)
        {
            auto findValue = find(maxvector.begin(),maxvector.end(), minvector[i]);
            
            if (findValue != maxvector.end())
            {
                answer.push_back(*findValue);
                maxvector.erase(findValue);
            }
        }

        return answer;
    }
};
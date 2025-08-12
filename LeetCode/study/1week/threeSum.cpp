#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> answer;
		map<int, int> numset;

		// O(n)
		for (auto num : nums)
		{
			numset[num]++;
		}

		for (auto i = numset.begin(); i != numset.end(); ++i)
		{
			numset[i->first]--;
			auto j = i;

			// 해당 값이 하나 밖에 없을 경우 다음 원소를 찾고, 아닐 경우 j에서 시작
			if (numset[i->first] <= 0)
			{
				j++;
			}

			for (;  j != numset.end(); ++j)
			{
				numset[j->first]--;

				int targetvalue = -(i->first + j->first);
				// cout << "i: " << i->first << ", j: " << j->first << ", targetvalue: " << targetvalue << endl;
				auto k = numset.find(targetvalue);
				if (k != numset.end() && k->second > 0)
				{
					vector<int> temp = {j->first, i->first, targetvalue};
					sort(temp.begin(), temp.end());
					answer.insert(temp);
				}
				numset[j->first]++;
			}
			numset[i->first]++;
		}

		return vector<vector<int>>(answer.begin(), answer.end());;
    }
};
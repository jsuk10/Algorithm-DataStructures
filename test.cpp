#include <iostream>
#include <vector>
#include <string>

#include "LeetCode/1week/groupAnagrams.cpp"

using namespace std;

int main()
{
	Solution solution;
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> result = solution.groupAnagrams(strs);

	for (const auto &group : result)
	{
		for (const auto &word : group)
		{
			cout << word << " ";
		}
		cout << endl;
	}

	return 0;
}
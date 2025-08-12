#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs)
	{
		map<string, vector<string>> anagramsMap;
		vector<vector<string>> answer;
		for (string value : strs)
		{
			string sortedValue = value;
			sort(sortedValue.begin(), sortedValue.end());

			anagramsMap[sortedValue].push_back(value);
		}

		for (auto a : anagramsMap)
		{
			answer.push_back(a.second);
		}

		return answer;
	}
};
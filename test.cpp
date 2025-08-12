#include <iostream>
#include <vector>
#include <string>

#include "testclass.cpp"

using namespace std;

int main()
{
	vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	Solution solution;
	
	cout << solution.removeDuplicates(nums);
	cout << endl;

	for (auto a : nums)
	{
		cout << a;
	}
	cout << endl;
}
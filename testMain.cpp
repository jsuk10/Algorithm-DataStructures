#include <iostream>
#include <vector>
#include <string>

#include "testclass.cpp"

using namespace std;

int main()
{
	vector<int> nums = {9};
	Solution solution;
	auto an = solution.plusOne(nums);
	for (auto a : an)
	{
		cout << a ;
	}
	cout <<endl;
}
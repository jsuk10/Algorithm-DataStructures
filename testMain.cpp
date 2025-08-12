#include <iostream>
#include <vector>
#include <string>

#include "testclass.cpp"

using namespace std;

int main()
{
	vector<int> nums = {99,-1,-100,3};
	for (auto a : nums)
	{
		cout << a;
	}
	cout << endl;

	Solution solution;
	solution.rotate(nums, 2);

	for (auto a : nums)
	{
		cout << a;
	}
	cout << endl;

	vector<int> nums2 = {1,2,3,4,5,6,7};
	for (auto a : nums2)
	{
		cout << a;
	}
	cout << endl;

	solution.rotate(nums2, 3);

	for (auto a : nums2)
	{
		cout << a;
	}
	cout << endl;
}
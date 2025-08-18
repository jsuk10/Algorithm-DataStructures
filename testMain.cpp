#include <iostream>
#include <vector>
#include <string>

#include "testclass.cpp"

using namespace std;

int main()
{
	string s = "leetcode";
	Solution solution;
	cout << solution.firstUniqChar(s) << endl;
	
	return 0;
}
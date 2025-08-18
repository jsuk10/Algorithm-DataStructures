#include <iostream>
#include <vector>
#include <string>

#include "testclass.cpp"

using namespace std;

int main()
{
	string s = "rat";
	string t = "car";
	Solution solution;
	cout << solution.isAnagram(s,t) << endl;
	
	return 0;
}
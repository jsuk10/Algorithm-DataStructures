#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {

		// 맨뒤에 x좌표를 체크하기 위한 행을 추가
		matrix.push_back(vector<int>(matrix[0].size(), 0));
		
		for (int i = 0; i < matrix.size(); i++)
		{
			matrix[i].push_back(0); // 맨뒤에 y좌표를 체크하기 위한 열을 추가
		}


		// 추가된 열을 제외하고 순회 하여 x,y에 0이 있는지 체크
		for (int i = 0; i < matrix.size() - 1; i++)
		{
			for (int j = 0; j < matrix[i].size() - 1; j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][matrix[i].size() - 1] = 1; // 마지막 행에 x좌표를 체크
					matrix[matrix.size() - 1][j] = 1; // 마지막 열에 y좌표를 체크
				}
			}
		}

		// 행 체크
		for (int i = 0; i < matrix.size() - 1; i++)
		{
			if (matrix[i][matrix[i].size() - 1] == 1)
			{
				matrix[i].assign(matrix[i].size() - 1, 0); // 해당 열을 0으로 변경
			}
			else
			{
				matrix[i].pop_back();
			}
		}

		// 열 체크
		for (int j = 0 ; j < matrix[0].size(); j++)
		{
			if (matrix[matrix.size() - 1][j] == 1)
			{
				for (int i = 0 ; i < matrix.size() ; i++)
				{
					matrix[i][j] = 0;
				}
			}
		}
		
		matrix.pop_back();
	}
};
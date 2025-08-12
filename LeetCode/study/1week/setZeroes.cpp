#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {

		// �ǵڿ� x��ǥ�� üũ�ϱ� ���� ���� �߰�
		matrix.push_back(vector<int>(matrix[0].size(), 0));
		
		for (int i = 0; i < matrix.size(); i++)
		{
			matrix[i].push_back(0); // �ǵڿ� y��ǥ�� üũ�ϱ� ���� ���� �߰�
		}


		// �߰��� ���� �����ϰ� ��ȸ �Ͽ� x,y�� 0�� �ִ��� üũ
		for (int i = 0; i < matrix.size() - 1; i++)
		{
			for (int j = 0; j < matrix[i].size() - 1; j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][matrix[i].size() - 1] = 1; // ������ �࿡ x��ǥ�� üũ
					matrix[matrix.size() - 1][j] = 1; // ������ ���� y��ǥ�� üũ
				}
			}
		}

		// �� üũ
		for (int i = 0; i < matrix.size() - 1; i++)
		{
			if (matrix[i][matrix[i].size() - 1] == 1)
			{
				matrix[i].assign(matrix[i].size() - 1, 0); // �ش� ���� 0���� ����
			}
			else
			{
				matrix[i].pop_back();
			}
		}

		// �� üũ
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
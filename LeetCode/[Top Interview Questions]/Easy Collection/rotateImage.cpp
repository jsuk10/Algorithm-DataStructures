#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 좌우 반전
        for (auto& a : matrix)
        {
            reverse(a.begin(),a.end());
        }

        // 대각 반전
        int size = matrix.size() - 1;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                cout << i << j << endl;
                if ((i + j) >= matrix.size()) continue;
                int temp = matrix[i][j];
                matrix[i][j] = matrix[size - j][size - i];
                matrix[size - j][size - i] = temp;
            }
        }
    }
};
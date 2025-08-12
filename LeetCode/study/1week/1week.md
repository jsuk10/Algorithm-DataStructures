# 1주차

생성일: 2025년 8월 11일 오후 10:14
태그: Array and Strings

[노션 페이지](https://www.notion.so/1-24cbed59c3638042afd1da5f9152749b?source=copy_link)

# 3 Sum

[Explore - LeetCode](https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/776/)

<aside>
💡
Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

⇒ 3개의 숫자의 합이 0이 되는 쌍을 찾는 문제

</aside>

접근 방식

1. 3중 포문 순회 방법 (`O(n^3)`)
    - 무한히 많은 0, 수가 많을 경우 시간 초과
2. 2중 포문으로 변경 후에 x,y값이 정해지면 z는 find로 알고리즘 사용
    - std::find알고리즘이 알고보니 전체 순회였음 (`O(n^3)`)
3. find알고리즘 변경
    
    Find를 할 경우 `O(n)`이므로 바이너리 서치를 통해 `O(nlogn)`으로 감소
    
4. std::map 사용으로 변경 (`O(n^2*logn)`)
    - 2중 루프 `O(N^2)` + map의 find `O(log n)`
    - find알고리즘만 찾는 것 보다 전부를 hashmap같은 key, value에서 사용하는게 편할 것 같음
        
        ⇒ C++ stl의 map은 ordered_map 이므로 0을 넘어가는 순간 break걸어도 될듯
        

## 3중 for (시간 초과)

- `O(n^3)`
    
    ```cpp
    
    	vector<vector<int>> threeSum2(vector<int>& nums) {
            set<vector<int>> answer;
            //일단 정렬
    		// O(nlogn)
            sort(nums.begin(), nums.end());
    
    		// O(n^2 * find알고리즘)
    		for (int i = 0; i < nums.size(); ++i)
    		{
    		    // 중복쌍은 피한다.
    		    if (i > 0 && nums[i-1] == nums[i])
    		    {
    		        continue;
    		    }
    		    
    		    // 순차 정렬이 되어 있어서 첫 pair가 0보다 크면 더이상 검사하지 않아도 된다.
    		    if (nums[i] > 0)
    		    {
    		        break;
    		    }
    		    
    		    if (i + 2 < nums.size() && nums[i] == 0 && nums[i+1] == 0&& nums[i+2] == 0)
    		    {
    		        answer.insert({0,0,0});
    		        break;
    		    }
    		    
    		    int TempNum2 = 2147483647; // int_max
    		    
    			for (int j = i + 1; j < nums.size(); ++j)
    			{
    			    // 동일값 검사 할 필요 없음.
    			    if (i + 1 < j - 1 && nums[j] == nums[j-1])
    			    {
    			        continue;
    			    }
    				
    			    TempNum2 = nums[j];
    			    
    			    // 순차정렬 하여 0보다 크면 답이 없음.
    			    if (nums[i] + nums[j] > 0)
    			    {
    			        break;
    			    }
    			    
    			  
    			    int TargetNum = -(nums[i] + nums[j]);
    			    auto k = find(nums.begin() + j + 1, nums.end(), TargetNum);
    			    
    			    if (k != nums.end())
    			    {
    					answer.insert({nums[i], nums[j], *k});
    			    }
    			}
    		}
    
    		return vector<vector<int>>(answer.begin(), answer.end());;
        }
    ```
    

## map사용

`O(n^2 logn)`

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> answer;
		map<int, int> numset;

		// O(n)
		for (auto num : nums)
		{
			numset[num]++;
		}

		for (auto i = numset.begin(); i != numset.end(); ++i)
		{
			numset[i->first]--;
			auto j = i;

			// 해당 값이 하나 밖에 없을 경우 다음 원소를 찾고, 아닐 경우 j에서 시작
			if (numset[i->first] <= 0)
			{
				j++;
			}

			for (;  j != numset.end(); ++j)
			{
				numset[j->first]--;

				int targetvalue = -(i->first + j->first);
				// cout << "i: " << i->first << ", j: " << j->first << ", targetvalue: " << targetvalue << endl;
				auto k = numset.find(targetvalue);
				if (k != numset.end() && k->second > 0)
				{
					vector<int> temp = {j->first, i->first, targetvalue};
					sort(temp.begin(), temp.end());
					answer.insert(temp);
				}
				numset[j->first]++;
			}
			numset[i->first]++;
		}

		return vector<vector<int>>(answer.begin(), answer.end());;
    }
};
```

# **Set Matrix Zeroes**

[Explore - LeetCode](https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/777/)

<aside>
💡
Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`'s.

⇒ 배열에 0이 있으면 가로 세로를 0으로 바꿔주는 문제

</aside>

## Set사용

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

		set<int> rowIndex;
		set<int> colIndex;
		
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == 0)
				{
					rowIndex.insert(i);
					colIndex.insert(j);
				}
			}
		}
		for (auto i : rowIndex)
		{
			matrix[i].assign(matrix[i].size(), 0);
		}

		for (auto j : colIndex)
		{
			for (int i = 0; i < matrix.size(); i++)
			{
				matrix[i][j] = 0;
			}
		}
	}
};
```

접근 방식

1. 배열을 순환
2. 0을 찾아서 x,y좌표를 기록
3. 기록된 x,y좌표에 따라 배열을 0으로 초기화

알고리즘

1. 전채 배열을 순환하여 0을 기록
2. x,y좌표에서 찾아 0으로 초기화

## 힌트 확인 후 공간 적게 먹는 솔루션

```cpp
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
```

| 코드 | 시간 복잡도 | 공간 복잡도 | 특징 |
| --- | --- | --- | --- |
| **첫 번째** (set 사용) | `O(m * n * log(max(m, n)))`  | `O(m + n)` | 직관적, 구현 간단 |
| **두 번째** (matrix 재활용) | `O(m * n)` | `O(1)` | 공간 효율 최고, 구현 복잡 |

**첫 번째** (set 사용)

- unordered_set사용시 시간 줄이기 가능

# **Group Anagrams**

[Explore - LeetCode](https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/777/)

<aside>
💡
Given an array of strings `strs`, group the anagrams together. You can return the answer in **any order**.
⇒ 에너그램 그룹화 하기.

</aside>

접근 방식

1. 에너그램을 그룹화 해서 관리할 수 없을까? ⇒ map사용
2. 에너그램을 vector으로 변환해서 리턴

`O(n * k * (log k + log n))`

```cpp
class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs)
	{
		map<string, vector<string>> anagramsMap;
		vector<vector<string>> answer;
		for (string value : strs)
		{
			string sortedvalue = value;
			sort(sortedvalue.begin(), sortedvalue.end());

			anagramsMap[sortedvalue].push_back(value);
		}

		for (auto a : anagramsMap)
		{
			answer.push_back(a.second);
		}

		return answer;
	}
};
```
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(),citations.end());
    
    for(int i = citations[citations.size()-1] ; i>0 ;i--){
        //i보다 작거나 같은 것을 찾아서 위치를 반환
        //it(index) <= i;
        auto it = lower_bound(citations.begin(), citations.end(), i);
        
        //이것보다 더 많이 인용된 논문의 수.
        int index = citations.end() - it;
        
        //많이 인용된 수가 i보다 많을 경우 정답
        if(index >= i)
        {
            answer = i;
            break;
        }
    }
    
    return answer;
}
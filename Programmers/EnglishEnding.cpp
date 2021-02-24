#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int index = 0;
    int people = 0;
    
    vector<string> v;
    v.push_back(words[0]);
    for(int i = 1 ; i < words.size();i++){
        //단어 틀림
        if(words[i][0] != words[i-1][words[i-1].size()-1]){
                people = (i % n) + 1;
                index = (i / n) + 1;
                answer.push_back(people);
                answer.push_back(index);
                return answer;
        }
            
        for(int j = 0 ; j < v.size();j++){
            //단어 같을 경우
            if(v[j] == words[i]){
                people = (i % n) + 1;
                index = (i / n) + 1;
                answer.push_back(people);
                answer.push_back(index);
                return answer;
            }
        }
        v.push_back(words[i]);
    }

    answer.push_back(people);
    answer.push_back(index);
    return answer;
}
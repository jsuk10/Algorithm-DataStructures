#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct parm
{
    int index;
    vector<parm*> edges;
};

int parmcount, day = 0;
parm parms[100001];
int parmsEdgeVisitCount[100001] = {-1};

// 스타트 점에서 이어진 농장 카운트
// 그 이상번식시킨 뒤에 보냄
// 1,2번 반복

void EdgeCount(parm* node){
    //방문시 리턴
    
    int cow = 1;
    //방문 체크
    parmsEdgeVisitCount[node->index] = 1;
    
    //소 늘려주기
    int count = (node->index == 1) ? node->edges.size() : node->edges.size() -1;
    while (cow <= count)
    {
        day++;
        cow *= 2;
    }
    //하위 노드 가기
    for(int i = 0 ; i < node->edges.size() ; i++){
        if(parmsEdgeVisitCount[node->edges[i]->index] == 1)
            continue;
        day++;
        EdgeCount(node->edges[i]);
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    int one,two;
    parm temp;
    cin >> parmcount;

    for(int i = 0 ; i < parmcount - 1  ; i++){
        parms[i+1].index = i+1;
        cin >> one >> two;
        parms[one].edges.push_back(&parms[two]);
        parms[two].edges.push_back(&parms[one]);
    }
    parms[parmcount].index = parmcount;

    EdgeCount(&parms[1]);
    cout << day;
}
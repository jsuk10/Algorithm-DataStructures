#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
    vector<int> child;
};

int number, edgeNumber, startindex;
node nodes[1001];
int BFSvisitied[1001] = {0}, DFSvisitied[1001] = {0};
queue<int> BFSq;

void DFS(int index)
{
    DFSvisitied[index] = 1;
    cout << index << " ";
    sort(nodes[index].child.begin(), nodes[index].child.end());
    for (int i = 0; i < nodes[index].child.size(); i++)
    {
        if (DFSvisitied[nodes[index].child[i]] == 1)
            continue;
        DFS(nodes[index].child[i]);
    }
}

void BFS(int index)
{
    BFSq.push(index);

    while (!BFSq.empty())
    {
        index = BFSq.front();
        BFSq.pop();
        if (BFSvisitied[index] == 1)
            continue;
        BFSvisitied[index] = 1;
        cout << index << " ";
        sort(nodes[index].child.begin(), nodes[index].child.end());
        for (int i = 0; i < nodes[index].child.size(); i++)
        {
            BFSq.push(nodes[index].child[i]);
        }
    }
}

int main()
{
    cin >> number >> edgeNumber >> startindex;

    for (int i = 0; i < edgeNumber; i++)
    {
        int startIndex, endIndex;
        cin >> startIndex >> endIndex;
        nodes[startIndex].child.push_back(endIndex);
        nodes[endIndex].child.push_back(startIndex);
    }

    DFS(startindex);
    cout << "\n";
    BFS(startindex);
}
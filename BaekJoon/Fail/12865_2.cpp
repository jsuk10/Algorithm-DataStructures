#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Stuff
{
public:
    int weight;
    int value;
    float valuePerWeight;
    Stuff(int w, int v)
    {
        this->weight = w;
        this->value = v;
        this->valuePerWeight = (float)w / (float)v;
    }
};

bool StuffCompare(Stuff a, Stuff b)
{
    return a.valuePerWeight > b.valuePerWeight;
}

int maxWeight, caseNum, answers;
vector<Stuff> v, answer;

int Process(int vlaueSum, int weightSum, int index)
{
    if (weightSum == maxWeight)
    {
        return vlaueSum;
    }
    //넘어갈 경우 연산
    if (weightSum > maxWeight)
    {
        return 0;
    }

    if (index >= caseNum)
    {
        return vlaueSum;
    }

    return max(
        //선택한 경우
        Process(vlaueSum + v[index].value, weightSum + v[index].weight, index + 1),
        //선택하지 않은 경우
        Process(vlaueSum, weightSum, index + 1));
}

int main()
{
    freopen("input.txt", "r", stdin);
    int tempWeight, tempValue;
    cin >> caseNum >> maxWeight;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> tempWeight >> tempValue;
        Stuff tempStuff(tempWeight, tempValue);
        v.push_back(tempStuff);
    }
    sort(v.begin(), v.end(), StuffCompare);
    answers = max(
        Process(v[0].value, v[0].weight, 0),
        Process(0, 0, 0));
    //선택 한 경우
    //선택 하지 않은 경우
    cout << answers;
}
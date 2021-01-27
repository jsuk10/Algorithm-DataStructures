#include <iostream>
#include <vector>

using namespace std;

int num;
vector<int> weight, tall, ranking;

//랭킹을 먹여줌
void Ranking()
{
    for (int i = 0; i < num; i++)
    {
        int rankNum = 1;
        for (int j = 0; j < num; j++)
        {
            //자신보다 체격이 큰 사람이 있을 경우
            if (weight[i] < weight[j] && tall[i] < tall[j])
            {
                rankNum++;
            }
        }
        ranking.push_back(rankNum);
    }
}

int main()
{
    cin >> num;
    int weightTemp, tallTemp;
    for (int i = 0; i < num; i++)
    {
        cin >> weightTemp >> tallTemp;
        weight.push_back(weightTemp);
        tall.push_back(tallTemp);
    }
    Ranking();
    for (int i = 0; i < num; i++)
    {
        cout << ranking[i] << " ";
    }
}
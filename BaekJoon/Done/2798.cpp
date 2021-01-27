#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int numOfCard, targetNum, temp, sum, answer;
    vector<int> cards;

    cin >> numOfCard >> targetNum;
    for (int i = 0; i < numOfCard; i++)
    {
        cin >> temp;
        cards.push_back(temp);
    }
    answer = 0;
    for (int i = 0; i < cards.size(); i++)
    {
        for (int j = 0; j < cards.size(); j++)
        {
            for (int k = 0; k < cards.size(); k++)
            {
                if (i == j || i == k || j == k)
                    continue;
                sum = cards[i] + cards[j] + cards[k];
                if (sum > targetNum)
                    continue;
                answer = (sum > answer) ? sum : answer;
            }
        }
    }

    cout << answer;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[102][100002];
int maxWeight, caseNum;

class Stuff
{
public:
    int v;
    int w;

    Stuff(int w, int v)
    {
        this->v = v;
        this->w = w;
    }
};

vector<Stuff> v;

int main()
{
    int tempWeight, tempValue;
    cin >> caseNum >> maxWeight;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> tempWeight >> tempValue;
        v.push_back(Stuff(tempWeight, tempValue));
    }

    for (int j = v[0].w; j <= maxWeight; j++)
    {
        arr[0][j] = v[0].v;
    }
    
    for (int i = 1; i < caseNum; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            if (j - v[i].w < 0)
            {
                arr[i][j] = arr[i - 1][j];
                continue;
            }
            arr[i][j] = max(arr[i - 1][j], v[i].v + arr[i - 1][j - v[i].w]);
        }
    }
    cout << arr[caseNum - 1][maxWeight];
}
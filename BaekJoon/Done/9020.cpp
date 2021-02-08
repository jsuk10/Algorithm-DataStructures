#include <iostream>
#include <vector>

using namespace std;

#define Maxnum 10000

bool* PrimeArray = new bool[Maxnum + 1];
vector<int> intVector;
int caseNum, answer1, answer2,num;

void Eratos()
{
    PrimeArray[0] = false;
    PrimeArray[1] = false;

    for (int i = 2; i < Maxnum; i++) {
        PrimeArray[i] = true;
    }

    for (int i = 2; i * i <= Maxnum; i++) {
        if (PrimeArray[i])
            for (int j = i * i; j <= Maxnum; j += i) {
                PrimeArray[j] = false;
            }
    }

    for (int i = 0; i < Maxnum; i++) {
        if (PrimeArray[i])
            intVector.push_back(i);
    }
}

void Gold(int num) {
    for (int i = 0; i < num; i++)
    {
        if (intVector[i] > num / 2)
            break;

        if (PrimeArray[num - intVector[i]])
        {
            answer1 = intVector[i];
            answer2 = num - intVector[i];
        }
    }
    cout << answer1 << " " << answer2<<"\n";
}

int main() {
    Eratos();
    cin >> caseNum;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> num;
        Gold(num);
    }
}
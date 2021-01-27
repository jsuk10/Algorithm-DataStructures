#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> ve;
int caseNum;
int sum;

void Sum()
{
    for (int i = 0; i < ve.size(); i++)
        sum += ve[i];
}

int Arithmetic()
{
    float arith = sum / float(ve.size());
    return round(arith);

}

int Center()
{
    return ve[(ve.size()-1) / 2];
}

int Many()
{
    vector<int> many;
    int count = 1, manyNumCount = 1, manynum;

    many.push_back(ve[0]);

    for (int i = 1; i < ve.size(); i++) {

        if (ve[i] == ve[i - 1])
            count++;
        else
            count = 1;

        if (count == manyNumCount)
            many.push_back(ve[i]);
        else if (count > manyNumCount) {
            many.clear();
            many.push_back(ve[i]);
            manyNumCount = count;
        }
        
    }

    if (many.size() >= 2)
    {
        return many[1];
    }
    else
    {
        return many[0];
    }
}

int Range()
{
    return ve[ve.size() - 1] - ve[0];
}

int main()
{
    cin >> caseNum;
    int a;
    for (int i = 0; i < caseNum; i++)
    {
        cin >> a;
        ve.push_back(a);
    }
    sort(ve.begin(), ve.end());
    Sum();

    cout << Arithmetic() << "\n"
        << Center() << "\n"
        << Many() << "\n"
        << Range();
}
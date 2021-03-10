#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lowerBound(vector<int> v, int value)
{
    int low = 0;
    int high = v.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (value <= v[mid])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int upperBound(vector<int> v, int value)
{
    int low = 0;
    int high = v.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (value < v[mid])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> v = {0, 3, 5, 6, 9, 11, 13, 15};

    cout << "6 lowerBound index : " << lowerBound(v, 6) << "\n";
    cout << "6 upperBound index : " << upperBound(v, 6) << "\n";
}
#include <iostream>
#include <queue>
#include <map>

using namespace std;
queue<int> arr;
int size, rotation, temp;

int main()
{
    cin >> size >> rotation;
    for (int i = 0; i < size; i++)
    {
        cin >> temp;
        arr.push(temp);
    }
    for (int i = 0; i < rotation; i++)
    {
        arr.push(arr.front());
        arr.pop();
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr.front() << " ";
        arr.pop();
    }
}

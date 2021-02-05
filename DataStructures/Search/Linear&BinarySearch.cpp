#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void LinearSearch(int targetNum, vector<int> arr,int index, int count) {
    if (index >= arr.size()) {
        cout << count << "번 연산\n";
        cout << "존재하지 않습니다.\n";
        return;
    }
    else {
        if (targetNum == arr[index]) {
            cout << count << "번 연산\n";
            cout << index + 1 << " 번째에 있습니다.\n";
            return;
        }
        else
            LinearSearch(targetNum, arr, ++index, ++count);
    }
}

void BinarySearch(int targetNum, vector<int> arr, int first, int last, int count) {
    int mid = (first + last) / 2;
    if (first > last)
    {
        cout << count << "번 연산\n";
        cout << "존재하지 않습니다.\n";
        return;
    }

    if (arr[mid] == targetNum) {
        cout << count << "번 연산\n";
        cout << mid + 1 << " 번째에 있습니다.\n";
        return;
    }
    else if(arr[mid] > targetNum) {
        BinarySearch(targetNum, arr, first, mid-1, ++count);
    }else if(arr[mid] < targetNum)
        BinarySearch(targetNum, arr, mid+1, last, ++count);
}

int main() {
    vector<int> arr;
    cout << "숫자 입력 , 그만 입력하려면 -1\n";
    while (true)
    {
        int num;
        cin >> num;

        if (num == -1)
            break;
        else
            arr.push_back(num);
    }
    sort(arr.begin(),arr.end());
    cout << "찾을 숫자 입력\n";
    int targetNum;
    cin >> targetNum;

    cout << "선형 탐색";
    LinearSearch(targetNum, arr, 0, 1);

    cout << "이진 탐색";
    BinarySearch(targetNum, arr, 0, arr.size() - 1, 1);
}
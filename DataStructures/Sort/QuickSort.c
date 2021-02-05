#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
    int pivot = arr[left]; // 피벗의 위치는 가장 왼쪽!
    int low = left + 1;
    int high = right;

    while (low <= high) // 교차되지 않을 때까지 반복
    {
        //주석 처리된 경우로 짤 경우 무한 루프와 out of Range로 들어가게됨
        //예시로 아래 활성화 된{3, 3, 3}
        //while(pivot > arr[low])
        while (pivot >= arr[low] && low <= right)
            low++;

        //while(pivot < arr[high])
        while (pivot <= arr[high] && high >= (left + 1))
            high--;
        // 두 while문을 다 통과 할 경우중 low가 hight보다 낮을 경우 교환
        if (low <= high)
            Swap(arr, low, high);
    }
    // 피벗과 중간 교환
    Swap(arr, left, high);
    // 옮겨진 피벗의 위치 정보 반환
    return high;
}

void QuickSort(int arr[], int left, int right)
{
    if (left <= right)
    {
        // 피벗 중심으로 좌우로 나눈뒤 정렬 해줌.
        int pivot = Partition(arr, left, right);
        // 왼쪽 영역을 재귀
        QuickSort(arr, left, pivot - 1);
        // 오른쪽 영역을 재귀
        QuickSort(arr, pivot + 1, right);
    }
}

int main(void)
{
    // int arr[7] = {3, 2, 4, 1, 7, 6, 5};
    int arr[3] = {3, 3, 3};

    int len = sizeof(arr) / sizeof(int);
    int i;

    QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}
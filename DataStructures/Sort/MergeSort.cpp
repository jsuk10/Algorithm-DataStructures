#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
    int lIdx = left;
    int mIdx = mid + 1;
    int i;

    //결과를 담을 공간
    int *sortArr = (int *)malloc(sizeof(int) * (right + 1));
    int sIdx = left;

    while (lIdx <= mid && mIdx <= right)
    {
        //데이터를 비교하여 정렬 순서대로 담는다.
        if (arr[lIdx] <= arr[mIdx])
            sortArr[sIdx] = arr[lIdx++];
        else
            sortArr[sIdx] = arr[mIdx++];

        sIdx++;
    }

    //앞부분을 먼저 다 옮겼다면
    if (lIdx > mid)
    {
        //뒤의 데이터를 sortArr에 옮긴다.
        for (i = mIdx; i <= right; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }
    //뒷부분 먼저 옮겼으면
    else
    {
        //배열의 앞에 남은 데이터를 전부 옮긴다.
        for (i = lIdx; i <= mid; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }

    for (i = left; i <= right; i++)
        arr[i] = sortArr[i];

    free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
    int mid;

    if (left < right)
    {
        // 중간 지점을 계산한다.
        mid = (left + right) / 2;

        // 둘로 나눠서 각각을 정렬한다.
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        // 정렬된 두 배열을 병합한다.
        MergeTwoArea(arr, left, mid, right);
    }
}

int main(void)
{
    int arr[7] = {3, 2, 4, 1, 7, 6, 5};
    int i;

    // 배열 arr의 전체 영역 정렬
    MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

    for (i = 0; i < 7; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}
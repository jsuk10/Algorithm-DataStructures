#include <stdio.h>

void BubbleSort(int arr[], int n)
{
    int i, j;
    int temp;
    //n-1까지 반복 - i + 1 까지 참조해서
    for (i = 0; i < n - 1; i++)
    {
        //n-i번은 이미 정렬이 되어있기 때문
        for (j = 0; j < (n - i) - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    int arr[4] = {3, 2, 4, 1};
    int i;

    BubbleSort(arr, sizeof(arr) / sizeof(int));

    for (i = 0; i < 4; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}
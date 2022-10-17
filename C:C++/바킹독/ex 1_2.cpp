#include <stdio.h>

// N크기의 arr를 받아서 서로 다른 위치의 두 원소의 합이 100이 되는 값이 존재하면 1 반환, 없으면 0반환.

int func2(int arr[], int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            if(arr[i] + arr[j] == 100)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int arr1[3] = {1, 52, 48};
    int arr2[2] = {50, 42};
    
    printf("%d\n", func2(arr1, 3));
    printf("%d\n", func2(arr2, 2));
}


// 배열arr에서 두 원소의 합이 100인 원소가 존재하면 1, 아니면 0을 반환해라.(시간복잡도 O(N))

#include <bits/stdc++.h>
using namespace std;
// 등장여부 체크하는 배열 만듬

int occur[101];
int func2(int arr[], int N)
{
    for(int i = 0; i < N; i++)
    {
        if(occur[100 - arr[i]]) // == 1과 같음
            return 1;
        occur[arr[i]] = 1;
    }
    return 0;
}

int main()
{
    int arr1[3] = {1, 52, 48};
    int arr2[2] = {50, 42};
    int arr3[4] = {4, 13, 63, 87};
    
    printf("%d\n", func2(arr1, 3));
    printf("%d\n", func2(arr2, 2));
    printf("%d\n", func2(arr3, 4));
}
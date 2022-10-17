#include <stdio.h>

// N 이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환하는 함수

int func4(int N)
{
    int max = 1;
    while(max <= N / 2)
    {
        max *= 2;
    }
    return max;
}

int main()
{
    printf("%d\n", func4(5));
    printf("%d\n", func4(97615282));
    printf("%d\n", func4(1024));
}
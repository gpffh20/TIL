#include <stdio.h>

// N이하인 자연수 중에서 3의 배수이거나 5의 배수인 수를 모두 합한 값을 반환
 
int func1(int N)
{
    int sum = 0;
    for(int i = 1; i <= N; i++)
    {
        if(i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    printf("%d\n", func1(16));
    printf("%d\n", func1(34567));
    printf("%d\n", func1(27639));
}

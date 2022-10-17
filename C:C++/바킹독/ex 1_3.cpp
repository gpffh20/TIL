#include <stdio.h>

// N이 제곱수이면 1반환, 아니면 0반환

int func3(int N)
{
    for(int i = 1; i * i <= N; i++)
    {
        if(i * i == N)
       	{
		    return 1;
    	}
    }
    return 0;
}

int main()
{
    printf("%d\n", func3(9));
    printf("%d\n", func3(693953651));
    printf("%d\n", func3(756580036));
}

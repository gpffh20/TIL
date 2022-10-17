>## false는 0

>## printf("%d", x);

>## bool
* int absoluteX = (조건) ? 참일 때 출력값 : 거짓일 때 출력값;

>## pow()
```cpp
#include <math.h>
pow() -> 거듭제곱 연산 함수
double x = pow(2.0, 20.0); -> 2의 20제곱 
printf("2의 20제곱은 %.0f 입니다.\n",  x);
```
>## 반복문
```cpp
for(변수 초기화; 조건; 반복하면서 이루어지는 연산) 
for(i = 0; i < N; i++)
for(;;)와 while(1)은 무한루프 
```

>## 기본입출력
* scanf("%d", &x); 는 사용자에게 입력받은 값을 삽입한다는 의미
  ```cpp
  #include <stdio.h>

  int main(void)
  {
    int x;
    scanf("%d", &x);
    return 0;
  }
  ```
>## get 함수
- 공백(띄어쓰기)를 포함하여 enter키가 입력될때 까지의 1줄을 읽는다.
(scanf는 띄어쓰기(공백) 못읽는다.)
- 맨 마지막 문자 저장후 '\0(NULL)'문자를 넣어 입력
* gets()는 string, 즉 문자열을 받는다는 의미.
  * 엔터를 칠 때 까지의 문자열을 받는다. 
* 엔터 처리
  * C언어는 엔터도 문자로 입력.
  * getchar();는 문자를 하나만 입력받겠다는 뜻으로 효율적으로 엔터처리 가능함.

>## 사용자 정의 함수
* >### 전역변수
  * 모든 함수 바깥 가장 위에 선언해주면 됨.
  ```cpp
  #include <stdio.h>

  int hour;
  int minute;
  int minuteAdd;

  void counter();
  {
    minute += minuteAdd;
    hour += minute / 60;
    minute %= 60;
    hour %= 24;
  }

  int main(void)
  {
    printf("시를 입력하세요:");
    scanf("%d", &hour);
    printf("분을 입력하세요:");
    scanf("%d", &minute);
    printf("더할 분을 입력하세요:");
    scanf("%d", &minuteAdd);
    counter();
    prinf("더해진 시간은 %d시 %d분 입니다.\ n", hour, minute);
    return 0; 
  }
  ```
 >## 배열
 * 선언하기
    ```cpp
    int arr[3];
    // 크기 3인 배열 선언.
    char input[5] = "Love";
    // 크기가 5이고, 내용이 Love인 배열 선언.
    ```
>## 2차원배열
```cpp
int score[5][2];
// 5 * 2 크기의 2차원 배열 선언
int total[2] = {0, };
// 1차원 배열 할당 시 모든 데이터에 0을 넣어주겠다는 의미.
```

>## 포인터
```cpp
#include <stdio.h>

// 두 변수의 값을 교환하는 함수
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int x = 1;
    int y = 10;
    temp(&x, &y);
    // temp함수에서 필요한 매개변수가 포인터변수 즉 주소값이니, 주소를 넣어줘야 함.
    printf("x = %d\ny = %d\n", x, y);
    return 0;
}
```
>## 배열
* 배열 1칸은 1바이트다.
  * 영어 : 1바이트
  * 한국어, 중국어 등 : 2바이트

>## <limits.h>
|이름|설명|
|--|--|
CHAR_BIT|char의 비트 수
SCHAR_MIN|signed char의 최소값
SCHAR_MAX|signed char의 최대값
UCHAR_MAX|unsigned char의 최대값
CHAR_MIN|char의 최소값
CHAR_MAX|char의 최대값
MB_LEN_MAX|멀티바이트 문자의 최대 바이트 수
SHRT_MIN|short int의 최소값
SHRT_MAX|short int의 최대값
USHRT_MAX|unsigned short int의 최대값
INT_MIN|int의 최소값
INT_MAX|int의 최대값
UINT_MAX|unsigned int의 최대값
LONG_MIN|long int의 최소값
LONG_MAX|long int의 최대값
ULONG_MAX|unsigned long int의 최대값
>## <string.h>
 * strlen(문자열) - 문자열 길이 구해줌
 * strcmp(문자열1, 문자열2) - 문자열 2개가 완전히 동일하면 0, 문자열1이 더 앞에 있으면 음수, 문자열2가 더 앞에 있으면 양수 출력
 * strcpy(문자열1, 문자열2) - 문자열2에 문자열1의 내용을 복사
 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a, b;     // 받는 문자의 자료형에 따라 결과값도 받은 자료형으로 나온다.
    scanf("%lf %lf", &a, &b); // double은 서식지정자 lf
    printf("%.15lf", a / b);

    return 0;
}
// 시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F를 출력하는 프로그램을 작성하시오.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int score;
    cin >> score;

    if(score >= 90)
        cout << 'A';
    else if(score >= 80)
        cout << 'B';
    else if(score >= 70)
        cout << 'C';
    else if(score >= 60)
        cout << 'D';
    else
        cout << 'F';
    return 0;
}
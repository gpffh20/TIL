// 세 개의 자연수 A, B, C가 주어질 때 A × B × C를 계산한 결과에 0부터 9까지 각각의 숫자가 몇 번씩 쓰였는지를 구하는 프로그램을 작성하시오.

#include <bits/stdc++.h>
using namespace std;

int freq[11];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C;
    int mul;

    cin >> A >> B >> C;
    mul = A * B * C;

    while(mul > 0)
    {
        freq[mul%10]++;
        mul /= 10;
    }
    for(int i = 0; i < 10; i++)
        cout << freq[i] << '\n';
}
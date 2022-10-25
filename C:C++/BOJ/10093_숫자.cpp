#include <bits/stdc++.h>
using namespace std;

long long a, b;     // 최대 10^15 까지기 때문에 long long으로 선언
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    if(a > b)   // a가 b보다 크면 a와 b의 값을 바꿔줘서 다음 연산 진행함.
        swap(a, b);
    if(a == b || b - a == 1)
        cout << 0;
    else
    {
        cout << b - a - 1 << '\n';
        for(long long i = a + 1; i < b; i++)    // i가 long long 범위가 될 수 있음.
            cout << i << ' ';
    }
}
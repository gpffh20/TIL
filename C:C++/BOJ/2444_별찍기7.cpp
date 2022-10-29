#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)      // 정방향 삼각형 모양 n줄 출력
    {
        for(int j = 0; j < n - i - 1; j++)
            cout << ' ';
        for(int j = 0; j < 2 * i + 1; j++)
            cout << '*';
        cout << '\n';
    }

    for(int i = 1; i < n; i++)      // 역삼각형 모양 n - 1줄 출력
    {
        for(int j = 0; j < i; j++)
            cout << ' ';
        for(int j = 0; j < 2 * (n - i) - 1; j++)
            cout << '*';
        cout << '\n';
    }
}
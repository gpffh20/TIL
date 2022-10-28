#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)      // 공백 출력 
            cout << " ";
        for(int k = 0; k < 2 * (n - i) - 1; k++)      // 반쪽 역삼각형에서 찍었던 별의 개수의 2배 -1 만큼 *을 찍으면 됨

            cout << "*";
        cout << '\n';
    }
}
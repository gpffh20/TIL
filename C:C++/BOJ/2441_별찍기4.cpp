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
        for(int k = 0; k < n - i; k++)      // * 출력
            cout << "*";
        cout << '\n';
    }
}
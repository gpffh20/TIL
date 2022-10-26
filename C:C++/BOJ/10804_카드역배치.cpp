#include <bits/stdc++.h>
using namespace std;

int arr[21];
void reverse(int a, int b)
{
    for(int i = 0; i < (b - a + 1) / 2; i++)
        swap(arr[a + i], arr[b - i]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b;

    for(int i = 1; i < 21; i++)     // 배열 안에 숫자 오름차순으로 넣어줌
        arr[i] = i;
    for(int i = 0; i < 10; i++)
    {
        cin >> a >> b;
        reverse(a, b);
    }
    
    for(int i = 1; i < 21; i++)
        cout << arr[i] << " ";
}
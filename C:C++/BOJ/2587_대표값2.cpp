#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, e, ave, sum = 0;
int arr[5];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    ave = sum / 5;
    sort(arr, arr + 5);
    cout << ave << '\n' << arr[2];    

    return 0;
}
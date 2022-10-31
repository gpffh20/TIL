#include <bits/stdc++.h>
using namespace std;

int arr[10];
int idx, m = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 9; i++)
        cin >> arr[i];
    
    for(int i = 0; i < 9; i++)
    {
        if(arr[i] > m)
        {
            m = arr[i];
            idx = i;
        }
    }
    cout << m << '\n' << idx + 1;
}
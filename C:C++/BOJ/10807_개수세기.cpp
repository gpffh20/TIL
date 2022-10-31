#include <bits/stdc++.h>
using namespace std;

int n, v, cnt = 0;   // n은 입력 숫자의 개수, v는 찾아야 하는 값
int arr[101];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> v;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == v)
            cnt++;
    }
    
    cout << cnt;
}
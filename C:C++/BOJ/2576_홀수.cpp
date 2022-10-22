#include<bits/stdc++.h>
using namespace std;

int arr[7];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;

    for(int i = 0; i < 7; i++)      // 7개의 숫자 받아서 배열 생성
    {   cin >> arr[i];     
        if(!(arr[i] % 2))       // 최대 100인 숫자가 들어오기 때문에 짝수는 102로 지정하여 표시해줌.
            arr[i] = 102;
    }

    sort(arr, arr + 7);     // 정렬해서 최소값 min에 지정
    int min = arr[0];
    
    int i = 0;
    while(arr[i] && arr[i] != 102) // 홀수만 더해줌
    {
        sum += arr[i];
        i++;
    }

    if(min == 102)      // 들어온 모든 수가 짝수라면 -1 출력
        cout << -1;
    else
    {
        cout << sum << '\n';
        cout << min;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int arr[10];
int main()      // 가장 많이 나온 숫자의 빈도 만큼 구입
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    while(n > 0)    // 같은 숫자 몇 번 나오는지 확인
    {
        arr[n%10]++;
        n /= 10;
    }

    int sum = arr[6] + arr[9];      // 6과 9 처리
    arr[6] = (sum / 2) + (sum % 2);

    int max = 0;                   // 가장 많이 나온 숫자의 빈도 출력
    for(int i = 0; i < 9; i++)     // 9는 6과 합쳐서 읽으면 안되기 때문에 i < 9
    {
        if(arr[i] > max)
            max = arr[i];
    }
    cout << max;
}
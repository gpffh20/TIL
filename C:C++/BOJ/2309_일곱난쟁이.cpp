// 전부 더해서 숫자 2개를 뺀 값이 100이면 바로 리턴

#include <bits/stdc++.h>
using namespace std;

int num[9];
int sum = 0, flag = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 9; i++)
    {
        cin >> num[i];
        sum += num[i];
    }

    for(int i = 0; i < 8; i++)
    {
        for(int j = i + 1; j < 9; j++)
        {
            if(sum - num[i] - num[j] == 100)
            {
                num[i] = 0;
                num[j] = 0;
                flag = 1;
                break;
            }
        }
        if(flag)
            break;
    }
    sort(num, num + 9);
    for(int i = 0; i < 7; i++)
    {
        num[i] = num[i + 2];
        cout << num[i] << '\n';
    }
}
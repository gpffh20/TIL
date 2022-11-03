#include <bits/stdc++.h>
using namespace std;

int arr[2][6] = {};     // 2는 성별, 6은 학년별로 배열에 저장해주기 위해 생성
int n, k, s, y, sum = 0;    // n = 총 학생 수, k = 한 방에 배정되는 최대 학생 수, s = 성별, y = 학년 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> s >> y;
        arr[s][y - 1] += 1;
    }

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            sum += (arr[i][j]/k);
            if(arr[i][j]%k)
                sum++;
        }
    }
    cout << sum;
}
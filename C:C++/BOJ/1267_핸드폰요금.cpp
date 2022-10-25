// 영식 요금제와 민식 요금제 중 더 싼 요금제 출력
#include <bits/stdc++.h>
using namespace std;

int n, y = 0, m = 0;
int arr[21];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];      // 기준시간 미만이어도 요금이 붙기 때문에 +1을 해줘야 한다.
        y += (arr[i] / 30 + 1) * 10;    // 영식 요금제 가격
        m += (arr[i] / 60 + 1) * 15;    // 민식 요금제 가격
    }

    if(y < m)
        cout << "Y " << y;
    else if(m < y)
        cout << "M " << m;
    else
        cout << "Y M " << y;
}
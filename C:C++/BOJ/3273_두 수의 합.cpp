#include <bits/stdc++.h>
using namespace std;

int arr[1000001] = {};
int n, x;
bool occur[2000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)  // 입력받은 값 배열에 넣기
        cin >> arr[i];
    cin >> x;

    int val = 0;
    for(int i = 0; i < n; i++)
    {
        if((x > arr[i]) && (occur[x - arr[i]])) //arr[i]과 짝이 되는 수가 이전에 나왔으면 쌍이 존재하는 것이기 때문에 val을 하나 올려줌, x > arr[i]이 먼저 나와야함
            val++;
        occur[arr[i]] = true;     // arr[i]와 짝이 되는 수가 이전에 안나왔으면 1로 바꿈
    }
    cout << val;
}
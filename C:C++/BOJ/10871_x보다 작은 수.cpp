// 정수 N개로 이루어진 수열 A와 정수 X가 주어진다. 이때, A에서 X보다 작은 수를 모두 출력하는 프로그램을 작성하시오.

#include <bits/stdc++.h>
using namespace std;
int n, x, a[10005];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        if(a[i] < x)
        {
            cout << a[i] << ' ';
        }
    }
}
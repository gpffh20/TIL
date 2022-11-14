#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, sum = 0;
    stack<int> S;
    cin >> n;
    while(n--)
    {
        cin >> k;
        if(k == 0)
            S.pop();
        else
            S.push(k);
    }
    while(!S.empty())
    {
        sum += S.top();
        S.pop();
    }
    cout << sum;
}
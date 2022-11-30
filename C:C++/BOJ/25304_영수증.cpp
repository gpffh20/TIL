#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int total, n, sum = 0;
    cin >> total >> n;
    while(n--)
    {
        int cost, ea;
        cin >> cost >> ea;
        sum += cost * ea;
    }
    if(total == sum)
        cout << "Yes";
    else
        cout << "No";
}
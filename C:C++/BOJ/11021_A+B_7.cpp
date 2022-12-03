#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, i = 1;
    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        cout << "Case #" << i << ": " << a + b << '\n';
        i++;
    }
}
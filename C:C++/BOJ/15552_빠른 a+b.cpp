#include <bits/stdc++.h>
using namespace std;

int a, b, n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        cout << a + b << '\n';
    }
}
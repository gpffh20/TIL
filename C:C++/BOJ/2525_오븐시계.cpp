#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, m, add;
    cin >> h >> m;
    cin >> add;

    m += add;
    if(m >= 60)
    {
        h += m / 60;
        m = m % 60;
        if(h >= 24)
            h -= 24;
    }
    cout << h << " " << m;
}
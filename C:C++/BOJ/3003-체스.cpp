#include <bits/stdc++.h>
using namespace std;

int k, q, r, b, kn, p;  // k = king, q = queen, r = rook, b = bishop, kn = knite, p = pawn
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> q >> r >> b >> kn >> p;
    cout << 1 - k << " " << 1 - q << " " << 2 - r << " " << 2 - b << " " << 2 - kn << " " << 8 - p;
}
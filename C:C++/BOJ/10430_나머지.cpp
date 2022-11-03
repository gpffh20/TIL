#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    cout << (a + b) % c << '\n' << ((a % c) + (b % c)) % c << '\n';
    cout << (a * b) % c << '\n' << ((a % c) * (b % c)) % c;
}
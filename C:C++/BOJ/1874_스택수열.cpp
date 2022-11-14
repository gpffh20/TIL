#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t, cnt = 1;
    cin >> n;
    stack<int> S;
    string ans;

   while(n--)
   {
    cin >> t;
    while(cnt <= t)
    {
        S.push(cnt++);
        ans += "+\n";
    }
    if(S.top() != t)
    {
        cout << "NO";
        return 0;
    }
    S.pop();
    ans += "-\n";
   }
   cout << ans;
}
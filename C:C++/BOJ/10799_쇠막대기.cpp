#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int ans = 0;
    stack<char> S;
    bool isLaser = false;
    cin >> str;
    for(auto c : str)
    {
        if(c == '(')
        {
            S.push(c);
            isLaser = true;
        }
        else if(isLaser && c == ')')
        {
            S.pop();
            ans += S.size();
            isLaser = false;
        }
        else    // !isLaser && c == ')'
        {
            S.pop();
            ans += 1;
        }
    }
    cout << ans;
}
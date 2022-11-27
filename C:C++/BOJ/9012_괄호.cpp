#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--)
    {
        string str;
        bool isValid = true;
        stack<char> S;
        cin >> str;
        for(auto c : str)
        {
            if(c == '(')
                S.push(c);
            else if(S.empty() && c == ')')
            {
                isValid = false;
                break;
            }
            else if(S.top() == '(' && c == ')')
                S.pop();
        }
        if(isValid && S.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
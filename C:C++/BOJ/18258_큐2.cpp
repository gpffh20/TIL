// 10825_큐 와 완전히 똑같음
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue <int> Q;
    int n, i;
    string s;
    cin >> n;
    while(n--)
    {
        cin >> s;
        if(s == "push")
        {
            cin >> i;
            Q.push(i);
        }
        else if(s == "pop")
        {
            if(Q.empty())
                cout << -1 << '\n';
            else
            {
                cout << Q.front() << '\n';
                Q.pop();
            }
        }
        else if(s == "size")
            cout << Q.size() << '\n';
        else if(s == "empty")
            cout << Q.empty() << '\n';
        else if(s == "front")
        {
            if(Q.empty())
                cout << -1 << '\n';
            else
                cout << Q.front() << '\n';
        }
        else    // back
        {
            if(Q.empty())
                cout << -1 << '\n';
            else
                cout << Q.back() << '\n';
        }
    }
}
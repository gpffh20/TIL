#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i;
    string s;
    deque<int> DQ;
    cin >> n;
    while(n--)
    {
        cin >> s;
        if(s == "push_front")
        {
            cin >> i;
            DQ.push_front(i);
        }
        else if(s == "push_back")
        {
            cin >> i;
            DQ.push_back(i);
        }
        else if(s == "pop_front")
        {
            if(DQ.empty())
                cout << -1 << '\n';
            else
            {
                cout << DQ.front() << '\n';
                DQ.pop_front();
            }
        }
        else if(s == "pop_back")
        {
            if(DQ.empty())
                cout << -1 << '\n';
            else
            {
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }
        }
        else if(s == "size")
            cout << DQ.size() << '\n';
        else if(s == "empty")
            cout << DQ.empty() << '\n';
        else if(s == "front")
        {
            if(DQ.empty())
                cout << -1 << '\n';
            else
                cout << DQ.front() << '\n';
        }
        else // back
        {
            if(DQ.empty())
                cout << -1 << '\n';
            else
                cout << DQ.back() << '\n';
        }
    }
}
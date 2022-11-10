#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--)
    {
        string str;
        cin >> str;

        list<char> L;
        auto cursor = L.begin();

        for(auto v : str)
        {
            if(v == '<')
            {
                if(cursor != L.begin())
                    cursor--;
            }
            else if(v =='>')
            {
                if(cursor != L.end())
                    cursor++;
            }
            else if(v == '-')
            {
                if(cursor != L.begin())
                {
                    cursor--;
                    cursor = L.erase(cursor);
                }
            }
            else
                L.insert(cursor, v);
        }
        for(auto c : L)
            cout << c;
        cout << '\n';
    }
}
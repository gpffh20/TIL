#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, t, ans = 0;
    deque<int> DQ;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        DQ.push_back(i);
    while(m--)
    {
        cin >> t;
        int idx = find(DQ.begin(), DQ.end(), t) - DQ.begin(); // DQ.begin() + t의 idx = t의 위치
        if(idx <= DQ.size() / 2)
        {
            for(int j = 0; j < idx; j++)
            {
                DQ.push_back(DQ.front());
                DQ.pop_front();
                ans++;
            }
        }
        else
        {
            for(int j = 0; j < DQ.size() - idx; j++)
            {
                DQ.push_front(DQ.back());
                DQ.pop_back();
                ans++;
            }
        }
        DQ.pop_front();
    }
    cout << ans;
}
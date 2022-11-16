// 해당 건물을 볼 수 있는, 즉 벤치마킹 할 수 있는 건물의 수는 몇 개인가를 세어줌
#include <bits/stdc++.h>
using namespace std;

long long n, h, ans;
stack <int> s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--)
    {
        cin >> h;
        while(!s.empty() && s.top() <= h)
            s.pop();
        ans += s.size();
        s.push(h);
    }
    cout << ans;
}
// 서로 짝을 지어줄 수 있고, 짝 지은 선끼리 겹치지 않아야함
// 괄호 짝 찾기와 로직이 비슷
// 현재 기호와 top의 기호가 같으면 pop, 다르면 push
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;
    while(n--)
    {
        string str;
        cin >> str;
        stack<char> S;
        for(auto c : str)
        {
            if(S.empty() || S.top() != c)
                S.push(c);
            else    // S.top() == c
                S.pop();
        }
        if(S.empty())
            ans += 1;
    }
    cout << ans;
}
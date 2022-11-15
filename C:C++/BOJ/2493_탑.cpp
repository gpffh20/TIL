#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, height;
    stack <pair<int, int>> top;
    string ans;
    cin >> n;
    top.push({0, 100000001});    // 0출력 할 때 예외처리를 미리해줌
    
    for(int i = 1; i <= n; i++)
    {
        cin >> height;
        while(top.top().second < height)
            top.pop();
        cout << top.top().first << " ";
        top.push({i, height});
    }
}
// *2는 순간이동이라 초가 늘지 않기 때문에 먼저 처리해줘야함
#include <bits/stdc++.h>
using namespace std;
int n, k;
int board[200002];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    deque <int> dq;
    dq.push_back(n);
    fill(board, board + 200001, -1);
    board[n] = 0;
    while(!dq.empty())
    {
        int cur = dq.front();
        dq.pop_front();
        if(cur * 2 < 200001 && board[2 * cur] == -1){
            dq.push_front(2 * cur);
            board[2 * cur] = board[cur];
        }
        for(int nxt : {cur - 1, cur + 1})
        {
            if(nxt < 0 || nxt > 200001 || board[nxt] != -1)
                continue;
            board[nxt] = board[cur] + 1;
            dq.push_back(nxt);
        }
    }
    cout << board[k];
}
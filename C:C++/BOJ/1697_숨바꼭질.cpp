// 범위 지정할 때 음수로 갈 일은 절대 없고, 100,000보다 커지면 무조건 -1을 해야하기 때문에 애초에 100,000을 넘지 않는 것이 가장 이득
#include <bits/stdc++.h>
using namespace std;
int board[100002];
int n, m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    queue<int>Q;    // 인덱스 저장
    Q.push(n);
    fill(board, board + 100001, -1);    //배열 -1로 초기화
    board[n] = 0;   // 시작점 0으로 설정

    while(board[m] == -1)
    {
        int cur = Q.front();
        Q.pop();
        for(int nxt : {cur - 1, cur + 1, 2 * cur})
        {
            if(nxt < 0 || nxt > 100000)   // 범위처리
                continue;
            if(board[nxt] != -1)    // 이미 지나쳐온 곳은 어짜피 같은 결과가 나옴
                continue;
            board[nxt] = board[cur] + 1;
            Q.push(nxt);
        }
    }
    cout << board[m];
}
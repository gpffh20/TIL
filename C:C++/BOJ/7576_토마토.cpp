#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m, ans = 0;
int board[1002][1002];
int dist[1002][1002];   // 기본값: 0, 안익은건 -1
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    queue<pair<int,int> > Q;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 1)
                Q.push({i, j});
            if(board[i][j] == 0)
                dist[i][j] = -1;
        }
    }
    while(!Q.empty())
    {
        pair<int,int> cur = Q.front();  // 큐를 이용하기 때문에 순서대로 처리됨
        Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >=m)
                continue;
            if(dist[nx][ny] >= 0 || board[nx][ny] == -1)
                continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(dist[i][j] == -1)
            {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
}
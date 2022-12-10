#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int t, m, n, k, x, y;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> m >> n >> k; // m: 가로, n: 세로, k: 배추 개수
        int res = 0;
        int board[52][52] = {0};
        bool vis[52][52] = {0};
        for(int i = 0; i < k; i++)
        {
            cin >> x >> y;
            board[y][x] = 1;
        }
        queue<pair<int,int> > Q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 0 || vis[i][j])   // 시작점 찾아주기
                    continue;
                vis[i][j] = true;
                Q.push({i,j});
                while(!Q.empty())
                {
                    pair<int,int> cur = Q.front();
                    Q.pop();
                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                            continue;
                        if(vis[nx][ny] || board[nx][ny] != 1)
                            continue;
                        vis[nx][ny] = true;
                        Q.push({nx,ny});
                    }
                }
                res++;
            }
        }
        cout << res << '\n';
    }
}
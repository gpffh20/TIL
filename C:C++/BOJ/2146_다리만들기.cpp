#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[103][103];
int vis[103][103];
int dist[103][103];
int n, num = 0, ans = 9999999;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue <pair<int,int> > Q;
bool check(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void make_board()   // 섬에 넘버 부여함
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 0 || vis[i][j] == 1)
                continue;
            num++;
            Q.push({i,j});
            vis[i][j] = 1;
            board[i][j] = num;
            while(!Q.empty())
            {
                auto cur = Q.front();
                Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(!check(nx,ny) || board[nx][ny] == 0 || vis[nx][ny] == 1)
                        continue;
                    vis[nx][ny] = 1;
                    board[nx][ny] = num;
                    Q.push({nx,ny});
                }
            }
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    }
    make_board();   // 섬마다 넘버 부여
    for(int i = 0; i < n; i++)
        fill(dist[i], dist[i] + n, -1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 0)
                continue;
            queue<pair<int,int> > Q1;
            bool escape = false;
            dist[i][j] = 0;
            Q1.push({i,j});
            while(!Q1.empty() && !escape)
            {
                auto cur = Q1.front();
                Q1.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(!check(nx, ny))
                        continue;
                    if(board[i][j] == board[nx][ny] || dist[nx][ny] >= 0)
                        continue;
                    if(board[nx][ny] != 0 && board[i][j] != board[nx][ny]){
                        ans = min(ans, dist[cur.X][cur.Y]);
                        escape = true;
                        while(!Q1.empty())  // 섬에 도착하는 최단 경로를 찾았으니 그 전에 쌓아놨던 데이터는 모두 없앰
                            Q1.pop();
                        break;
                    }
                    dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                    Q1.push({nx,ny});
                }
            }
            for(int i = 0; i < n; i++)
                fill(dist[i], dist[i] + n, -1);
        }
    }
    cout << ans;
}
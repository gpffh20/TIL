#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board[102][102];
bool vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

int bfs()
{
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!vis[i][j]){
                cnt++;
                queue<pair<int,int> > Q;
                Q.push({i,j});
                vis[i][j] = 1;
                while(!Q.empty())
                {
                    auto cur = Q.front();
                    Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                            continue;
                        if(board[nx][ny] != board[cur.X][cur.Y] || vis[nx][ny])
                            continue;
                        Q.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    // 적록색약 아닌 사람
    int not_g = bfs();
    // 적록색약
    for(int i = 0; i < n; i++)
        fill(vis[i], vis[i] + n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'R')
                board[i][j] = 'G';
        }
    }
    int is_g = bfs();
    cout << not_g << " " << is_g; 
}
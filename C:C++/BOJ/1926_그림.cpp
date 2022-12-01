#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502];
int n, m;   // n: 세로, m: 가로
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    // board판 주어진대로 채움
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    int mx = 0, num = 0;   // mx:최대, num:그림의 수
    // (i, j)가 BFS의 시작점이 될 수 있는지 확인
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 0 || vis[i][j])  //board[i][j] == 0은 그림이 아닌 곳, vis[i][j] == 1은 이미 지나간 곳
                continue;
            num++;
            queue<pair<int,int>> Q;
            vis[i][j] = 1;
            Q.push({i, j});
            int area = 0;   // pop할 때 마다 증가 => 그림의 넓이가 됨
            while(!Q.empty())
            {
                area++;
                pair<int,int> cur = Q.front();
                Q.pop();
                for(int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if(vis[nx][ny] || board[nx][ny] != 1)
                        continue;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            mx = max(mx, area);
        }
    }
    cout << num << '\n' << mx;
}
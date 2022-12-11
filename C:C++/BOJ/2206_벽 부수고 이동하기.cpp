#include <bits/stdc++.h>
using namespace std;
char board[1002][1002];
int dist[1002][1002][2];
// dist[1002][1002][0] : 벽을 부수지 않았을 때 걸리는 시간
// dist[1002][1002][1] : 벽을 부수고 걸리는 시간
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int bfs()
{
    for(int i = 0; i < n; i++){ // dist배열 모두 -1로 초기화
        for(int j = 0; j < m; j++)
            dist[i][j][0] = dist[i][j][1] = -1;
    }
    dist[0][0][0] = dist[0][0][1] = 1;
    queue<tuple<int,int,int> > Q;
    Q.push({0,0,0});
    while(!Q.empty())
    {
        int x, y, broken;
        tie(x, y, broken) = Q.front();  // Q.front를 tie에 각각 저장
        if(x == n - 1 && y == m - 1)    // 우측 하단에 도착했을 때
            return dist[x][y][broken];
        Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if(board[nx][ny] == '0' && dist[nx][ny][broken] == -1){
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                Q.push({nx, ny, broken});
            }
            if(!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1){ // 벽(nx, ny)을 부수는 경우
                dist[nx][ny][1] = dist[x][y][broken] + 1;
                Q.push({nx, ny, 1});
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;  // n: 세로, m: 가로
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    }
    cout << bfs();
    return 0;
}
// 1. 녹이기, 2. 덩어리가 쪼개졌는지 확인하기, 3. 모두 0인지 확인하기
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m, year;
int board[302][302];
int vis[302][302];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool check(int i, int j){
    return(i >= 0 && i < n && j >= 0 && j < m);
}

void melting()
{
    int zero[302][302] = {0};   // 빙하가 한 번에 녹아야하기 때문에 int가 아닌 int배열 이용
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0)
                continue;
            for(int dir = 0; dir < 4; dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(check(nx, ny) && board[nx][ny] == 0)
                    zero[i][j]++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            board[i][j] = max(0, board[i][j] - zero[i][j]);
    }
}
// 0: 빙산 다 녹음, 1: 한 덩어리, 2: 덩어리 쪼개짐
int status()
{
    int x = -1, y = -1;
    int cnt1 = 0;
    // 남아있는 빙산 중 한 칸 무작위 선택
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j]){  // 0만 아니면 참
                x = i;
                y = j;
                cnt1++; // cnt1은 빙산이 남아있는 칸의 수
            }
        }
    }
    if(cnt1 == 0)   // 모두 녹은 상황
        return 0;
    int cnt2 = 0;
    queue<pair<int,int> > Q;
    vis[x][y] = 1;
    Q.push({x,y});
    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        cnt2++; // 서로 연결되어 있는 빙산의 수 체크
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(!check(nx,ny) || vis[nx][ny] == 1 || board[nx][ny] <= 0)
                continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
    if(cnt1 == cnt2)
        return 1;
    return 2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    }
    while(true)
    {
        year++;
        melting();
        for(int i = 0; i < n; i++)
            fill(vis[i], vis[i] + m, 0);
        int ans = status();
        if(ans == 0){
            cout << 0;
            return 0;
        }
        else if(ans == 1)
            continue;
        else    // ans == 2
            break;
    }
    cout << year;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int k, w, h;
int board[202][202];
int dist[202][202][32];
// dist[202][202][jump] : 나이트처럼 몇 번 점프했는지 같이 저장해줌 
int dmx[4] = {1, 0, -1, 0};
int dmy[4] = {0, 1, 0, -1};
int dkx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dky[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
bool check(int x, int y)
{
    return (x >= 0 && y >= 0 && x < h && y < w);
}
int bfs()
{
    queue <tuple<int,int,int> > Q;
    dist[0][0][0] = 1;
    Q.push({0, 0, 0});
    while(!Q.empty())
    {
        int x, y, jump;
        tie(x, y, jump) = Q.front();
        if(x == h - 1 && y == w - 1)
            return (dist[x][y][jump] - 1);
        Q.pop();
        for(int dir = 0; dir < 8; dir++){
            int nkx = x + dkx[dir];
            int nky = y + dky[dir];
            if(jump >= k)
                break;
            if(!check(nkx, nky) || dist[nkx][nky][jump + 1] >= 1 || board[nkx][nky] == 1)
                continue;
            dist[nkx][nky][jump + 1] = dist[x][y][jump] + 1;
            Q.push({nkx, nky, jump + 1});
        }
        for(int dir = 0; dir < 4; dir++){
            int nmx = x + dmx[dir];
            int nmy = y + dmy[dir];
            if(!check(nmx, nmy) || dist[nmx][nmy][jump] >= 1 || board[nmx][nmy] == 1)
                continue;
            dist[nmx][nmy][jump] = dist[x][y][jump] + 1;
            Q.push({nmx, nmy, jump});
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> w >> h;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++)
            cin >> board[i][j];
    }
    cout << bfs();
    return 0;
}
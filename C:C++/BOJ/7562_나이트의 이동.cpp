#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dist[302][302];
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int t, n, x, y, xx, yy;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
            fill(dist[i], dist[i] + n, -1);
        queue<pair<int,int> > Q;
        cin >> x >> y;
        Q.push({x, y});
        dist[x][y] = 0;
        cin >> xx >> yy;
        while(!Q.empty())
        {
            auto cur = Q.front();
            Q.pop();
            for(int dir = 0; dir < 8; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if(dist[nx][ny] != -1)
                    continue;
                Q.push({nx, ny});
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            }
        }
        cout << dist[xx][yy] << '\n';
    }
}
// 좌측 상단에서 우측 하단까지의 최단거리를 구하는 문제
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m;
string board[102];
int dist[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    for(int i = 0; i < n; i++)
        fill(dist[i], dist[i] + m, -1);
    queue<pair<int,int> > Q;
    Q.push({0,0});
    dist[0][0] = 1;
    while(!Q.empty())
    {
        pair<int,int> cur = Q.front();  // 현재 기준점이 되는 좌표
        Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(dist[nx][ny] >= 1 || board[nx][ny] != '1') // dist[nx][ny] >= 1은 이미 지나갔던 곳을 의미, 뒷 조건은 1만 갈 수 있는 길이기 때문에 조건 지정
                continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    cout << dist[n - 1][m - 1];
}
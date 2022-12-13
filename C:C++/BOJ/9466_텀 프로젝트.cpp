#include <bits/stdc++.h>
using namespace std;
const int NOT_VISITED = 0;
const int CYCLE_IN = -1;
int arr[100003];    // 입력받을 배열
int state[100003];  // 사이클에 들어와있는지 체크할 배열
int t, n;

void bfs(int x)
{
    int temp = x;
    while(true)
    {
        state[temp] = x; // state에 인덱스 저장
        temp = arr[temp];   // temp에 가르킨 학생 번호 저장 
        // 이미 지나간 학생에 도달한 경우
        if(state[temp] == x){   // bfs의 첫 시작이거나, 한 바퀴 돌아 다시 처음으로 돌아온 경우가 해당
            while(state[temp] != CYCLE_IN){
                state[temp] = CYCLE_IN;
                temp = arr[temp];
            }
            return;
        }
        // 이전 방문에서 지나간 학생에 도달했을 경우
        else if(state[temp] != 0)
            return;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        fill(state + 1, state + 1 + n, 0);  // 다음 케이스 진행 전 초기화
        for(int i = 1; i <= n; i++)
            cin >> arr[i];
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(state[i] == NOT_VISITED)
                bfs(i);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(state[i] != CYCLE_IN)
                cnt++;
        }
        cout << cnt << '\n';
    }
}
// 요세푸스 순열은 n개의 숫자가 있고, k번째에 있는 숫자를 삭제한다고 했을 때 삭제되는 숫자를 순서대로 나열한 것
#include <bits/stdc++.h>
using namespace std;

int n, k, len = 0;
int pre[5001];  // 이전 노드를 가르키는 배열 생성
int nxt[5001];  // 다음 노드를 가르키는 배열 생성
vector<int> v;  // 요세푸스 순열 담을 벡터 생성
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    // 순환연결리스트 생성
    for(int i = 1; i <= n; i++)
    {
        pre[i] = (i == 1) ? n : i - 1;
        nxt[i] = (i == n) ? 1 : i + 1;
        len++;
    }

    int j = 1;
    for(int i = 1; len != 0; i = nxt[i])
    {
        if(j == k)  // k번째 수를 벡터 v로 제거
        {
            nxt[pre[i]] = nxt[i];
            pre[nxt[i]] = pre[i];
            v.push_back(i);
            j = 1;
            len--;
        }
        else
            j++;
    }

    // 요세푸스 순열 출력
    cout << '<';
    for(int i = 0; i < n; i++)
    {
        cout << v[i];
        if(i != n - 1)
            cout << ", ";
    }
    cout << '>';
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;   // tc 개수
    cin >> t;
    while(t--)
    {
        deque<int> dq;  // 숫자 담을 덱
        string od, arr;  //  order담을 문자열, 주어진 배열 담을 문자열
        int n;  // 배열에 들어가 있는 개수
        bool isReverse = false, isError = false; // reverse 여부 체크

        cin >> od >> n >> arr;
        string temp = "";    // 덱에 담기 위한 임시변수
        // 덱에 숫자 넣기
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] == '[')
                continue;
            else if('0' <= arr[i] && arr[i] <= '9')
            {
                temp += arr[i];
            }
            else if(arr[i] == ']' | arr[i] == ',' && temp != "") // 주어진 배열이 공백일 때 예외처리 하려고 temp != "" 넣음
            {
                dq.push_back(stoi(temp));
                temp = "";
            }
        }
        // 명령 처리
        for(int i = 0; i < od.size(); i++)
        {
            if(od[i] == 'R')
            {
                isReverse = !isReverse;
            }
            else    // 'D'일때
            {
                if(dq.empty())
                {
                    isError = true;
                }
                else if(isReverse)
                    dq.pop_back();
                else    // !isReverse
                    dq.pop_front();
            }
        }
        // 출력
        if(isError)
            cout << "error\n";
        else if(dq.empty())
            cout << "[]\n";
        else if(isReverse)
        {
            cout << '[';
            while(dq.size() > 1)
            {
                cout << dq.back() << ",";
                dq.pop_back();
            }
            cout << dq.back() << "]\n";
        }
        else    // !isReverse
        {
            cout << '[';
            while(dq.size() > 1)
            {
                cout << dq.front() << ",";
                dq.pop_front();
            }
            cout << dq.front() << "]\n";
        }
    }
}
// 분배법칙으로 곱하기끼리, 더하기끼리 나눠서 연산 후, 누적 덧셈으로 답 찾아줌
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0, mul = 1;
    string str;
    stack<char> S;

    cin >> str;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '(')
        {
            S.push(str[i]);
            mul *= 2;
        }
        else if(str[i] == '[')
        {
            S.push(str[i]);
            mul *= 3;
        }
        else if(str[i] == ')')
        {
            if(S.empty() || S.top() != '(')
            {
                cout << 0;
                return 0;
            }
            if(str[i - 1] == '(')   // 가장 바깥쪽 괄호가 아닐 때
                sum += mul;
            mul /= 2;
            S.pop();
        }
        else if(str[i] == ']')
        {
            if(S.empty() || S.top() != '[')
            {
                cout << 0;
                return 0;
            }
            if(str[i - 1] == '[')  // 가장 바깥쪽 괄호가 아닐 때
                sum += mul;
            mul /= 3;
            S.pop();
        }
    }
    if(S.empty())
        cout << sum;
    else
        cout << 0;
}
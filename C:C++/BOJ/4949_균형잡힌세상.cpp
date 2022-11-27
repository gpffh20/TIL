// 쌍을 발견하면 pop 해서 마지막에 남는 괄호들을 보면 확인 가능
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true)
    {
        string str;
        getline(cin, str);
        bool isValid = true;
        if(str == ".")
            break;
        stack<char> s;
        for(auto c : str)
        {
            if(c == '(' || c == '[')
                s.push(c);
            else if(c == ')')
            {
                if(s.empty() || s.top() != '(') // 가장 최근에 들어온 괄호와 짝이 안맞으면 false, s.empty가 먼저와야지 런타임에러가 안남
                {
                    isValid = false;
                    break;
                }
                s.pop();
            }
            else if(c == ']')
            {
                if(s.empty() || s.top() != '[')
                {
                    isValid = false;
                    break;
                }
                s.pop();
            }
        }
        if(!s.empty())
            isValid = false;
        if(isValid)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}
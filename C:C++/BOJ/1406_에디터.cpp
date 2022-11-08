#include <bits/stdc++.h>
using namespace std;

string str1;
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str1;
    list<char> L;   // 캐릭터형 리스트 L 생성
    for(auto c : str1)  // 입력받은 문자열 리스트에 넣어줌
        L.push_back(c);
    auto cursor = L.end();  // 커서 리스트의 마지막에 위치시킴

    cin >> n;
    while(n--)
    {
        char od;    // order
        cin >> od;  // cin으로 한 문자씩 받아서 공백과 줄바꿈은 알아서 무시
        if(od == 'P')
        {
            char add;
            cin >> add;
            L.insert(cursor, add);  // cursor가 가르키는 곳에 add추가
        }
        else if(od == 'L')
        {
            if(cursor != L.begin()) // 문장의 맨 앞이면 무시
                cursor--;
        }
        else if(od == 'D')
        {
            if(cursor != L.end())   // 문장의 제일 뒤면 무시
                cursor++;
        }
        else    // B일 때
        {
            if(cursor != L.begin())
            {
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }
    for(auto c : L)
        cout << c;
}
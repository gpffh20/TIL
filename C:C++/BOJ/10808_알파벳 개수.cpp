// 알파벳 소문자로만 이루어진 단어 S가 주어진다. 각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 작성하시오.

#include <bits/stdc++.h>
using namespace std;

int freq[26]; // 전역변수로 선언해 초기값 알아서 0으로 채워짐
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for(auto c : s)
    freq[c-'a']++; 
    // 예를 들어 c가 'b'라면 'b' - 'a'는 1이고, 1번 인덱스에 숫자가 하나씩 늘어난다.
  for(int i = 0; i < 26; i++)
    cout << freq[i] << ' ';
}
#include <bits/stdc++.h>
using namespace std;

int res;
string str1, str2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[26] = {};
    cin >> str1;
    cin >> str2;

    for(auto v : str1)
        arr[v - 'a']++;
    for(auto v : str2)
        arr[v - 'a']--;

    for(int i : arr)
    {
        if(i != 0)
            res += abs(i);
    }
    cout << res;    
}
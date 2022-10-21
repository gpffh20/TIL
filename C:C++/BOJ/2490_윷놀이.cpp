#include <bits/stdc++.h>
using namespace std;

int arr[3][4];
char z;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 4; j++)
            cin >> arr[i][j];

    for(int i = 0; i < 3; i++)
    {
        z = 'A';
        for(int j = 0; j < 4; j++)
        {
            if(!arr[i][j])
                z++;
        }
        if(z == 'A')
            cout << 'E' << '\n';
        else
        {
            z--;
            cout << z << '\n';
        }
    }
    return 0;
}
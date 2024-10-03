#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 0;
    int n;
    cin >> n;
    while(n--)
    {
        char a[4];
        cin >> a;
        if(a[1]=='+')
        {
            x++;
        }
        if(a[1]=='-')
        {
            x--;
        }
    }
    cout << x;  
}
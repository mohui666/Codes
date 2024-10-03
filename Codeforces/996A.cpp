#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[6] = {0,100,20,10,5,1};
    int money;
    cin >> money;
    int count = 0;
    for(int i = 1;i<=5&&money>0;i++)
    {
        count += money/a[i];
        money %= a[i];
    }
    cout << count;
}
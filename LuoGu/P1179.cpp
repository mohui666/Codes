#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l,r;
    cin >> l >> r;
    int count = 0;
    for(int i = l;i<=r;i++)
    {
        int num = i;
        while(num)
        {
            if(num%10==2)
            {
                count++;
            }
            num/=10;
        }
    }

    cout << count;
}
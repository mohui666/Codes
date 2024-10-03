#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1,0);

    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }

    int maxDay = 1;
    int nowDays = 1;

    for(int i = 1;i<=n-1;i++)
    {
        if(a[i]<=a[i+1])
        {
            nowDays++;
            if(nowDays>maxDay)
            {
                maxDay = nowDays;
            }
        }
        else
        {
            nowDays = 1;
        }
    }

    cout << maxDay;
}
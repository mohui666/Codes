#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int x[N];
int n,c;

bool check(int mid)
{
    int now = 1, num = 1;
    for (int i = 2; i <= n; i++){
        if (x[i]-x[now]>=mid)
        {
            now=i;
            num++;
        }
        if(num>=c)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> c;

    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&x[i]);
    }

    sort(x+1,x+1+n);

    int l = 1,r=1e9;
    while(l<r)
    {
        int mid = l+r+1>>1;
        if(check(mid))
        {
            l = mid;
        }
        else 
        {
            r = mid-1;
        }
    }

    printf("%d",l);
}
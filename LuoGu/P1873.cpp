#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int h[N];
int n;
long long m;

bool check(int x)
{
    long long sum = 0;
    for(int i = 1;i<=n;i++)
    {
        if(h[i]>x)
        {
            sum += h[i] - x;
        }
    }

    return sum >= m;
}

int main()
{
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&h[i]);
    }

    sort(h+1,h+1+n);

    int l = 0,r = h[n];

    while(l<r)
    {
        int mid = l+r+1>>1;
        if(check(mid))
        {
            l = mid; 
        }
        else
        {
            r = mid - 1;
        }
    }

    printf("%d",l);
}
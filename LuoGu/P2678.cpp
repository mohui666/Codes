#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 +10;

int s[N];
int L,m,n;

bool check(int x)
{
    int now = 0, num = 0;
    for(int i = 1; i <= n+1; i++)
    {
        if(s[i] - s[now] < x)
        {
            num++;
        }
        else
        {
            now = i;
        }
    }
    return num<=m;
}

int main()
{

    cin >> L >> n >> m;

    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&s[i]);
    }

    s[n + 1] = L;

    sort(s + 1, s + n + 1);

    int l = 1, r = L;

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
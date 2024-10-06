#include <bits/stdc++.h>
using namespace std;

int n,k;
const int N = 20;
int a[N];

void dfs(int x,int start)
{
    if(x>k)
    {
        for(int i = 1;i<=k;i++)
        {
            printf("%3d",a[i]);
        }
        printf("\n");
        return;
    }

    for(int i = start;i<=n;i++)
    {
        a[x] = i;
        dfs(x+1,i+1);
        a[x] = 0;
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    dfs(1,1);
    return 0;
}
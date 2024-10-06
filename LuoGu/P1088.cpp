#include <bits/stdc++.h>
using namespace std;

int n,m;
const int N = 20000;
int a[N],c[N];
bool st[N];
int res=0;

void dfs(int depth)
{
    if(depth>n)
    {
        res++;
        if(res==m+1)
        {
            for(int i = 1;i<=n;i++)
            {
                printf("%d ",a[i]);
            }
            exit(0);
        }
        return;
    }

    for(int i = 1;i<=n;i++)
    {   
        if(!res)
        {
            i = c[depth];
        }

        if(!st[i])
        {
            st[i] = true;
            a[depth] = i;
            dfs(depth+1);
            st[i] = false;
            a[depth] = 0;
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);

    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }
    
    dfs(1);
    return 0;
}
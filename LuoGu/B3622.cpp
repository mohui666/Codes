#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 20;
int a[N];

void dfs(int x)
{
    if(x>n)
    {
        for(int i = 1;i<=n;i++)
        {
            if(a[i]==1)
            {
                printf("Y");
            }
            else
            {
                printf("N");
            }
        }
        printf("\n");
        return;
    }

    a[x] = 2;
    dfs(x+1);
    a[x] = 0;

    a[x] = 1;
    dfs(x+1);
    a[x] = 0;
}

int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}
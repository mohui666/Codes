#include <bits/stdc++.h>
using namespace std;

int n,k;
const int N = 20;
int a[N];

void dfs(int x) 
{
    if (x > n) 
    {
        for (int i = 1; i <= n; i++) 
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= k; i++) 
    {
        a[x] = i;
        dfs(x + 1);
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    dfs(1);
}
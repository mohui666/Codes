#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int v[N],w[N];
int dp[N]={0};

int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i = 1;i<=m;i++)
    {
        scanf("%d %d",&v[i],&w[i]);
    }

    for(int i = 1;i<=m;i++)
    {
        for(int j = v[i];j<=n;j++)
        {
            dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    printf("%d",dp[n]);
}